#include "Sniffer.h"

#include <QDebug>
#include <QTimer>

using NetworkLayer::Sniffer;
using DataLayer::NetworkPackage;

#define MAX_PACKET_SIZE    0x10000
#define SIO_RCVALL         0x98000001

namespace {

/// Структура заголовка IP-пакета
struct IPHeader {
  UCHAR   iph_verlen;   // версия и длина заголовка
  UCHAR   iph_tos;      // тип сервиса
  USHORT  iph_length;   // длина всего пакета
  USHORT  iph_id;       // Идентификация
  USHORT  iph_offset;   // флаги и смещения
  UCHAR   iph_ttl;      // время жизни пакета
  UCHAR   iph_protocol; // протокол
  USHORT  iph_xsum;     // контрольная сумма
  ULONG   iph_src;      // IP-адрес отправителя
  ULONG   iph_dest;     // IP-адрес назначения
};

/// время задержки между проверками сокета, ms
const int kListenUsualReplanningTimeoutMs = 100;

} // namespace

Sniffer::Sniffer() :
    QObject(nullptr)
{
    // инициализация
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2,2), &wsaData);
    m_socket = socket( AF_INET, SOCK_RAW, IPPROTO_IP );

    // имя хоста
    char hostName[128];
    gethostname(hostName, sizeof(hostName));

    // информация о хосте
    HOSTENT* hostInfo;
    hostInfo = gethostbyname(hostName);

    // адрес хоста
    SOCKADDR_IN socketAddr;
    ZeroMemory( &socketAddr, sizeof(socketAddr) );
    socketAddr.sin_family = AF_INET;
    socketAddr.sin_addr.s_addr = ((IN_ADDR*)hostInfo->h_addr_list[0])->s_addr;

    // связываем
    bind(m_socket, (SOCKADDR*)&socketAddr, sizeof(SOCKADDR));

    // включаем promiscuous mode
    unsigned long flag = 1;
    ioctlsocket(m_socket, SIO_RCVALL, &flag);
}

Sniffer::~Sniffer() {
    closesocket(m_socket);
    WSACleanup();
}

// FIXME: удалить вывод в лог
void Sniffer::listen() {
    char buffer[MAX_PACKET_SIZE]; // 64 Kb
    const uint count = recv(m_socket, buffer, sizeof(buffer), 0);
    if (count >= sizeof(IPHeader)) {
        // Начинаем разбор пакета
        NetworkPackage package;
        QString logString;
        qDebug() << "Received package";

        // Отправитель
        IPHeader* header = (IPHeader*)buffer;
        IN_ADDR inAddr;
        inAddr.s_addr = header->iph_src;
        package.sender = inet_ntoa(inAddr);
        logString += "Sender: " + package.sender + ";";

        // Получатель
        inAddr.s_addr = header->iph_dest;
        package.receiver = inet_ntoa(inAddr);
        logString += " Receiver: " + package.receiver + ";";

        // Протокол
        if(header->iph_protocol == IPPROTO_TCP) {
            package.protocol = "TCP";
        } else if (header->iph_protocol == IPPROTO_UDP) {
            package.protocol = "UDP";
        } else {
            package.protocol = "Unknown";
        }
        logString += " Protocol: " + package.protocol + ";";

        // Размер
        const ushort lowbyte = header->iph_length >> 8;
        const ushort highbyte = header->iph_length << 8;
        package.size = lowbyte + highbyte;
        logString += " Size: " + QString::number(package.size) + ";";

        // Время жизни
        package.lifeTIme = header->iph_ttl;
        logString += " LifeTime: " + QString::number(package.lifeTIme) + ";";

        qDebug() << logString;

        // Уведомляем подписчиков о получении пакета, если он подходит
        if (isPackageFit(package)) {
            emit gotPackage(package);
        } else {
            qDebug() << "Package is filtered";
        }
    }
    planNextCheck();
}

void Sniffer::setSettings(const DataLayer::Settings& settings)
{
    m_isSettingsSet = true;
    m_settings = settings;
}

void Sniffer::planNextCheck()
{
    QTimer::singleShot(kListenUsualReplanningTimeoutMs, this, &Sniffer::listen);
}

bool Sniffer::isPackageFit(const DataLayer::NetworkPackage& package)
{
    // Если настройки не установлены, то и фильтровать нечем
    if (!m_isSettingsSet) {
        return true;
    }

    // Проверка фильтра по протоколу
    const bool isProtocolFit = ((package.protocol == "TCP") && (m_settings.protocolFilter.tcp)) ||
            ((package.protocol == "UDP") && (m_settings.protocolFilter.udp));

    // Провекра фильтра по ip
    const bool isIPFit = !m_settings.ipFilter.filter || m_settings.ipFilter.ips.contains(package.sender);

    return isProtocolFit && isIPFit;

}
