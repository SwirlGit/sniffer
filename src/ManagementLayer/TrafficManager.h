#ifndef TRAFFICMANAGER_H
#define TRAFFICMANAGER_H

#include "AbstractViewManager.h"

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

private:
    /**
     * @brief Представление трафика
     */
    std::unique_ptr<ViewLayer::TrafficView> m_view;
};

} // namespace ManagementLayer

#endif // TRAFFICMANAGER_H
