#ifndef CONFIGURATION_VIEW_PRIVATE_H
#define CONFIGURATION_VIEW_PRIVATE_H

class QCheckBox;
class QGroupBox;
class QPushButton;
class QTextEdit;
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

    /**
     * @brief рамка для фильтрации по протоколу
     */
    QGroupBox* protocolFilterGroupBox = nullptr;

    /**
     * @brief фильтрация для tcp
     */
    QCheckBox* tcpCheckBox = nullptr;

    /**
     * @brief фильтрация для udp
     */
    QCheckBox* udpCheckBox = nullptr;

    /**
     * @brief фильтрация для ip
     */
    QCheckBox* ipCheckBox = nullptr;

    /**
     * @brief список валидных ip в случае фильтрации
     */
    QTextEdit* ipTextEdit = nullptr;

    /**
     * @brief кнопка для восстановления настроек
     */
    QPushButton* restoreButton = nullptr;

    /**
     * @brief кнопка для подтверждения конфигурации
     */
    QPushButton* applyButton = nullptr;
};
}

#endif // CONFIGURATION_VIEW_PRIVATE_H
