#ifndef APPLICATIONMANAGER_H
#define APPLICATIONMANAGER_H

#include "AbstractViewManager.h"

#include <memory>

namespace ViewLayer {
class ApplicationView;
}

namespace ManagementLayer {
class NetworkManager;
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

    /**
     * @brief Управляющие сетевым взаимодействием
     */
    std::unique_ptr<ManagementLayer::NetworkManager> m_networkManager;
};

} // namespace ManagementLayer

#endif // APPLICATIONMANAGER_H
