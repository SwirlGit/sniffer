#ifndef TRAFFICMANAGER_H
#define TRAFFICMANAGER_H

#include "AbstractViewManager.h"

#include "DataLayer/NetworkPackage.h"

#include <memory>

namespace ViewLayer {
class TrafficView;
}

namespace ManagementLayer
{
/**
 * @brief Менеджер трафика
 */
class TrafficManager : public AbstractViewManager
{
    Q_OBJECT

public:
    explicit TrafficManager(QObject* parent = nullptr);
    ~TrafficManager();

    /**
     * @brief Получить представление, которым управляем
     */
    QWidget* view() const override final;

    /**
     * @brief Отобразить полученный пакет
     */
    void showPackage(const DataLayer::NetworkPackage& package);

private:
    /**
     * @brief Представление трафика
     */
    std::unique_ptr<ViewLayer::TrafficView> m_view;

    /**
     * @brief Суммарный размер полученных пакетов
     */
    long long int m_summaryPackageSize = 0;
};

} // namespace ManagementLayer

#endif // TRAFFICMANAGER_H
