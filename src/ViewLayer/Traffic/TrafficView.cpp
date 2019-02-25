#include "TrafficView.h"
#include "TrafficViewPrivate.h"

using ViewLayer::TrafficViewPrivate;
using ViewLayer::TrafficView;


TrafficViewPrivate::TrafficViewPrivate(QWidget* parent)
{
    Q_UNUSED(parent);
}


// ****

TrafficView::TrafficView(QWidget *parent) :
    QFrame(parent),
    m_pimpl(new TrafficViewPrivate(parent))
{
    setObjectName("trafficView");
}

TrafficView::~TrafficView()
{

}
