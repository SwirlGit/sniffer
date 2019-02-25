#ifndef SNIFFER_H
#define SNIFFER_H

#include <QObject>

#include <winsock2.h>

#include "DataLayer/NetworkPackage.h"

namespace NetworkLayer
{
/**
 * @brief Класс реализующий прослушку
 *
 * @note Переносится для выполнения в отдельный поток и запускается извне, пример использования:
 * @code
         Sniffer sniffer();
         QThread snifferThread;
         sniffer.moveToThread(&snifferThread);
         QObject::connect(&snifferThread, &QThread::started, &sniffer, &Sniffer::listen);
         QObject::connect(&sniffer, &Sniffer::gotPackage, module, &Module::processMessage);
         QObject::connect(&application, &QApplication::aboutToQuit, [&snifferThread] {
             snifferThread.quit();
             snifferThread.wait();
         });
         snifferThread.start();
 * @endcode
 */
class Sniffer : public QObject
{
    Q_OBJECT

public:
    explicit Sniffer();
    ~Sniffer();

    /**
     * @brief Запустить прослушивание
     */
    void listen();

signals:
    /**
     * @brief Сигнал о получении пакета
     */
    void gotPackage(DataLayer::NetworkPackage package);

private:
    /**
     * @brief Запуск новой проверки на получение пакетов
     */
    void planNextCheck();

private:
    /**
     * @brief Сокет
     */
    SOCKET m_socket;
};

} // namespace ManagementLayer

#endif // SNIFFER_H
