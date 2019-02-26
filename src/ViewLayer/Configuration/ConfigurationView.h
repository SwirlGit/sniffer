#ifndef CONFIGURATION_VIEW_H
#define CONFIGURATION_VIEW_H

#include <QFrame>

#include <memory>

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

private:
    /**
     * @brief Скрытая имплементация представления
     */
    std::unique_ptr<ConfigurationViewPrivate> m_pimpl;
};
}

#endif // CONFIGURATION_VIEW_H
