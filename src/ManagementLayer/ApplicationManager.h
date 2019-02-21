#ifndef APPLICATIONMANAGER_H
#define APPLICATIONMANAGER_H

#include "AbstractViewManager.h"

#include <memory>

namespace ViewLayer {
class ApplicationView;
}

namespace ManagementLayer
{
/**
 * @brief Менеджер приложения
 */
class ApplicationManager : public AbstractViewManager
{
    Q_OBJECT

public:
    explicit ApplicationManager(QObject* parent = nullptr);
    ~ApplicationManager();

    /**
     * @brief Получить представление, которым управляем
     */
    QWidget* view() const override final;

    /**
     * @brief Запустить выполнение приложения
     */
    void exec();

private:
    /**
     * @brief Представление приложения
     */
    std::unique_ptr<ViewLayer::ApplicationView> m_view;
};

} // namespace ManagementLayer

#endif // APPLICATIONMANAGER_H
