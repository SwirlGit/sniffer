#ifndef SNIFFER_H
#define SNIFFER_H

#include <QObject>

#include <winsock2.h>

#include "DataLayer/NetworkPackage.h"
#include "DataLayer/Settings.h"

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

    /**
     * @brief Установить настройки
     */
    void setSettings(const DataLayer::Settings& settings);

signals:
    /**
     * @brief Сигнал о получении пакета
     */
    void gotPackage(const DataLayer::NetworkPackage& package);

private:
    /**
     * @brief Запуск новой проверки на получение пакетов
     */
    void planNextCheck();

    /**
     * @brief Удовлетворяет ли пакет конфигурации
     */
    bool isPackageFit(const DataLayer::NetworkPackage& package);

private:
    /**
     * @brief Сокет
     */
    SOCKET m_socket;

    /**
     * @brief Установлены ли настройки
     */
    bool m_isSettingsSet = false;

    /**
     * @brief Настройки
     */
    DataLayer::Settings m_settings;
};

} // namespace ManagementLayer

#endif // SNIFFER_H
