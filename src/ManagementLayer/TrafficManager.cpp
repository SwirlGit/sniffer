#include "TrafficManager.h"

#include "ViewLayer/Traffic/TrafficView.h"

using ManagementLayer::TrafficManager;
using ViewLayer::TrafficView;

TrafficManager::TrafficManager(QObject* parent) :
    AbstractViewManager(parent),
    m_view(new TrafficView)
{
}

TrafficManager::~TrafficManager() = default;

QWidget* TrafficManager::view() const
{
    return m_view.get();
}

void TrafficManager::showPackage(const DataLayer::NetworkPackage& package)
{
    m_summaryPackageSize += package.size;
    m_view->addPackage(package);
    m_view->updateSize(m_summaryPackageSize);
}
