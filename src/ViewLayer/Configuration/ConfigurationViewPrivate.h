#ifndef CONFIGURATION_VIEW_PRIVATE_H
#define CONFIGURATION_VIEW_PRIVATE_H

class QWidget;

namespace ViewLayer
{
/**
 * @brief Данные представления конфигурации
 */
struct ConfigurationViewPrivate
{
    ConfigurationViewPrivate(QWidget* parent);
    ConfigurationViewPrivate(const ConfigurationViewPrivate&) = delete;
};
}

#endif // CONFIGURATION_VIEW_PRIVATE_H
