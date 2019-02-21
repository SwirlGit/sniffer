#ifndef SNIFFER_H
#define SNIFFER_H

#include <QObject>

#include <winsock2.h>

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

    void listen();

signals:
    void gotPackage();

private:
    void planNextCheck();
private:
    SOCKET m_socket;
};

} // namespace ManagementLayer

#endif // SNIFFER_H
