#include "ApplicationManager.h"
#include "NetworkManager.h"

#include "Application.h"

#include "ViewLayer/ApplicationView.h"

using ManagementLayer::ApplicationManager;
using ManagementLayer::NetworkManager;
using ViewLayer::ApplicationView;

ApplicationManager::ApplicationManager(QObject* parent) :
    AbstractViewManager(parent),
    m_view(new ApplicationView),
    m_networkManager(new NetworkManager(parent))
{
    m_networkManager->start();

    // Настраиваем представление
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

