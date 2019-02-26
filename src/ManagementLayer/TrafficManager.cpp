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
