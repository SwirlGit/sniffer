#ifndef CONFIGURATIONMANAGER_H
#define CONFIGURATIONMANAGER_H

#include "AbstractViewManager.h"

#include <memory>

namespace ViewLayer {
class ConfigurationView;
}

namespace ManagementLayer
{
/**
 * @brief Менеджер конфигурации
 */
class ConfigurationManager : public AbstractViewManager
{
    Q_OBJECT

public:
    explicit ConfigurationManager(QObject* parent = nullptr);
    ~ConfigurationManager();

    /**
     * @brief Получить представление, которым управляем
     */
    QWidget* view() const override final;

private:
    /**
     * @brief Представление конфигурации
     */
    std::unique_ptr<ViewLayer::ConfigurationView> m_view;
};

} // namespace ManagementLayer

#endif // CONFIGURATIONMANAGER_H
