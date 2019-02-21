#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H

#include <QObject>

#include <memory>

namespace NetworkLayer {
class Sniffer;
}
class QThread;

namespace ManagementLayer
{
/**
 * @brief Менеджер приложения
 */
class NetworkManager : public QObject
{
    Q_OBJECT

public:
    explicit NetworkManager(QObject* parent = nullptr);
    ~NetworkManager();

    void start();
    void stop();

signals:
    void gotPackage();

private:
    /**
     * @brief Отправщик сообщений для сервиса обработки данных
     */
    std::unique_ptr<NetworkLayer::Sniffer> m_sniffer;

    /**
     * @brief Поток выполнения отправщика
     */
    std::unique_ptr<QThread> m_snifferThread;
};

} // namespace ManagementLayer

#endif // NETWORKMANAGER_H
