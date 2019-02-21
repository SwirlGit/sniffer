#ifndef APPLICATION_VIEW_H
#define APPLICATION_VIEW_H

#include <QWidget>

#include <memory>

class QTabBar;

namespace ViewLayer
{
struct ApplicationViewPrivate;

/**
 * @brief Главное предсталение приложения
 */
class ApplicationView : public QWidget
{
    Q_OBJECT

public:
    explicit ApplicationView(QWidget* parent = nullptr);
    ~ApplicationView();

    /**
     * @brief Добавить дочернюю страницу представления
     */
    void addContentPage(const QString& pageName, QWidget* page);

    /**
     * @brief Вставить дочернюю страницу в указанную позицию
     */
    void insertContentPage(int index, const QString& pageName, QWidget* page);

    /**
     * @brief Удалить дочернюю страницу
     */
    void removeContentPage(QWidget* page);

    /**
     * @brief Получить индекс активной вкладки
     */
    int currentContentPageIndex() const;

    /**
     * @brief Получить название вкладки
     */
    QString contentPageName(int index) const;

    /**
     * @brief Установить название вкладки
     */
    void setContentPageName(int index, const QString& name);

    /**
     * @brief Сменить активную вкладку
     */
    void setCurrentContentPage(int index);

signals:
    /**
     * @brief Изменилась текущая страница
     * @param index - индекс отображаемой страницы
     */
    void currentContentPageChanged(int index);

private:
    /**
     * @brief Скрытая имплементация представления
     */
    std::unique_ptr<ApplicationViewPrivate> m_pimpl;
};
}

#endif // APPLICATION_VIEW_H
