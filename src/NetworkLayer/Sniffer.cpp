#include "Sniffer.h"

#include <QDebug>
#include <QTimer>

using NetworkLayer::Sniffer;

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

void Sniffer::listen() {
    char buffer[MAX_PACKET_SIZE]; // 64 Kb
    const uint count = recv(m_socket, buffer, sizeof(buffer), 0);
    if (count >= sizeof(IPHeader)) {
        // Начинаем разбор пакета
        qDebug() << "Received package";
        IPHeader* header = (IPHeader*)buffer;
        IN_ADDR inAddr;
        inAddr.s_addr = header->iph_src;
        qDebug() << inet_ntoa(inAddr);

        emit gotPackage();
    }
    planNextCheck();
}

void Sniffer::planNextCheck()
{
    QTimer::singleShot(kListenUsualReplanningTimeoutMs, this, &Sniffer::listen);
}
