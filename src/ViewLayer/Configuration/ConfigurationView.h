#ifndef CONFIGURATION_VIEW_H
#define CONFIGURATION_VIEW_H

#include <QFrame>

#include <memory>

#include "DataLayer/Settings.h"

namespace ViewLayer
{
struct ConfigurationViewPrivate;

/**
 * @brief Предсталение конфигурации
 */
class ConfigurationView : public QFrame
{
    Q_OBJECT

public:
    explicit ConfigurationView(QWidget* parent = nullptr);
    ~ConfigurationView();

signals:
    /**
     * @brief Нажата кнопка для применения настроек
     */
    void applySettingsPressed(DataLayer::Settings settings);

private:
    /**
     * @brief Заполнить структуру с настройками
     */
    void fillSettings();

    /**
     * @brief Восстановить настройки из сохраненных
     */
    void restoreSettings();

private:
    /**
     * @brief Скрытая имплементация представления
     */
    std::unique_ptr<ConfigurationViewPrivate> m_pimpl;

    /**
     * @brief данные конфигурации
     */
    DataLayer::Settings settings;
};
}

#endif // CONFIGURATION_VIEW_H
