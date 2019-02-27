#include "ApplicationManager.h"
#include "ConfigurationManager.h"
#include "NetworkManager.h"
#include "TrafficManager.h"

#include "Application.h"

#include "ViewLayer/ApplicationView.h"

using ManagementLayer::ApplicationManager;
using ManagementLayer::ConfigurationManager;
using ManagementLayer::NetworkManager;
using ManagementLayer::TrafficManager;
using ViewLayer::ApplicationView;

Q_DECLARE_METATYPE(DataLayer::NetworkPackage)
Q_DECLARE_METATYPE(DataLayer::Settings)

ApplicationManager::ApplicationManager(QObject* parent) :
    AbstractViewManager(parent),
    m_view(new ApplicationView),
    m_configurationManager(new ConfigurationManager(this)),
    m_networkManager(new NetworkManager(this)),
    m_trafficManager(new TrafficManager(this))
{
    qRegisterMetaType<DataLayer::NetworkPackage>();
    qRegisterMetaType<DataLayer::Settings>();

    // Настраиваем представление
    m_view->addContentPage("Configuration", m_configurationManager->view());
    m_view->addContentPage("Report", m_trafficManager->view());

    // Настраиваем соединение
    connect(m_configurationManager.get(), &ConfigurationManager::applySettingsRequested,
            m_networkManager.get(), &NetworkManager::configure);
    connect(m_networkManager.get(), &NetworkManager::gotPackage,
            m_trafficManager.get(), &TrafficManager::showPackage);

    // Запускаем
    m_networkManager->start();
}

ApplicationManager::~ApplicationManager() = default;

QWidget* ApplicationManager::view() const
{
    return m_view.get();
}

void ApplicationManager::exec()
{
    m_view->showMaximized();
}

