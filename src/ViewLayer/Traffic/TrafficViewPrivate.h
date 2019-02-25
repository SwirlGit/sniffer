#ifndef TRAFFIC_VIEW_PRIVATE_H
#define TRAFFIC_VIEW_PRIVATE_H

class QWidget;

namespace ViewLayer
{
/**
 * @brief Данные представления отображения трафика
 */
struct TrafficViewPrivate
{
    TrafficViewPrivate(QWidget* parent);
    TrafficViewPrivate(const TrafficViewPrivate&) = delete;
};
}

#endif // TRAFFIC_VIEW_PRIVATE_H
