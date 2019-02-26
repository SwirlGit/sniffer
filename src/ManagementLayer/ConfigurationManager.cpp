#include "ConfigurationManager.h"

#include "ViewLayer/Configuration/ConfigurationView.h"

using ManagementLayer::ConfigurationManager;
using ViewLayer::ConfigurationView;

ConfigurationManager::ConfigurationManager(QObject* parent) :
    AbstractViewManager(parent),
    m_view(new ConfigurationView)
{
    connect(m_view.get(), &ConfigurationView::applySettingsPressed, this, &ConfigurationManager::applySettingsRequested);
}

ConfigurationManager::~ConfigurationManager() = default;

QWidget* ConfigurationManager::view() const
{
    return m_view.get();
}
