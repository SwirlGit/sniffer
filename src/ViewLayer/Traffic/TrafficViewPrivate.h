#ifndef TRAFFIC_VIEW_PRIVATE_H
#define TRAFFIC_VIEW_PRIVATE_H

class QLabel;
class QTextEdit;
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

    /**
     * @brief Панель для отображения информации о пакетах
     */
    QTextEdit* infoPanel = nullptr;

    /**
     * @brief Сумма размеров всех пакетов от начала сеанса
     */
    QLabel* resultSize = nullptr;
};
}

#endif // TRAFFIC_VIEW_PRIVATE_H
