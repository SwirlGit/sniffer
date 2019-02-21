#ifndef APPLICATION_VIEW_PRIVATE_H
#define APPLICATION_VIEW_PRIVATE_H

class QStackedWidget;
class QTabBar;

namespace ViewLayer
{

/**
 * @brief Данные главного предсталения приложения
 */
struct ApplicationViewPrivate
{
    ApplicationViewPrivate();
    ApplicationViewPrivate(const ApplicationViewPrivate&) = delete;

    /**
     * @brief Основные вкладки
     */
    QTabBar* tabs = nullptr;

    /**
     * @brief Содержимое вкладок
     */
    QStackedWidget* content = nullptr;
};
}

#endif // APPLICATION_VIEW_PRIVATE_H
