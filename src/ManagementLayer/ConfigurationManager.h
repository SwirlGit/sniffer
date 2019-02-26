#ifndef CONFIGURATIONMANAGER_H
#define CONFIGURATIONMANAGER_H

#include "AbstractViewManager.h"

#include <memory>

#include "DataLayer/Settings.h"

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

signals:
    /**
     * @brief applySettingsRequested
     */
    void applySettingsRequested(DataLayer::Settings settings);

private:
    /**
     * @brief Представление конфигурации
     */
    std::unique_ptr<ViewLayer::ConfigurationView> m_view;
};

} // namespace ManagementLayer

#endif // CONFIGURATIONMANAGER_H
