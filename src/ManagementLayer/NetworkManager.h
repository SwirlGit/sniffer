#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H

#include <QObject>

#include <memory>

#include "DataLayer/NetworkPackage.h"
#include "DataLayer/Settings.h"

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

    /**
     * @brief Запустить работу
     */
    void start();

    /**
     * @brief Остановить работу
     */
    void stop();

    /**
     * @brief сконфигурировать фильтрацию
     */
    void configure(DataLayer::Settings settings);

signals:
    /**
     * @brief Был получен пакет
     */
    void gotPackage(DataLayer::NetworkPackage package);

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
