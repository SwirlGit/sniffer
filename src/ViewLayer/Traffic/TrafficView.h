#ifndef TRAFFIC_VIEW_H
#define TRAFFIC_VIEW_H

#include <QFrame>

#include <memory>

namespace ViewLayer
{
struct TrafficViewPrivate;

/**
 * @brief Предсталение трафика
 */
class TrafficView : public QFrame
{
    Q_OBJECT

public:
    explicit TrafficView(QWidget* parent = nullptr);
    ~TrafficView();

private:
    /**
     * @brief Скрытая имплементация представления
     */
    std::unique_ptr<TrafficViewPrivate> m_pimpl;
};
}

#endif // TRAFFIC_VIEW_H
