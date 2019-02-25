#include "ConfigurationManager.h"

#include "ViewLayer/Configuration/ConfigurationView.h"

using ManagementLayer::ConfigurationManager;
using ViewLayer::ConfigurationView;

ConfigurationManager::ConfigurationManager(QObject* parent) :
    AbstractViewManager(parent),
    m_view(new ConfigurationView)
{
}

ConfigurationManager::~ConfigurationManager() = default;

QWidget* ConfigurationManager::view() const
{
    return m_view.get();
}
