#include "TrafficView.h"
#include "TrafficViewPrivate.h"

#include <QLabel>
#include <QTextEdit>
#include <QVBoxLayout>

using ViewLayer::TrafficViewPrivate;
using ViewLayer::TrafficView;


TrafficViewPrivate::TrafficViewPrivate(QWidget* parent) :
    infoPanel(new QTextEdit(parent)),
    resultSize(new QLabel(parent))
{
}

// ****

TrafficView::TrafficView(QWidget *parent) :
    QFrame(parent),
    m_pimpl(new TrafficViewPrivate(parent))
{
    setObjectName("trafficView");

    m_pimpl->infoPanel->setReadOnly(true);
    m_pimpl->resultSize->setText("Size: 0 byte");

    QVBoxLayout* infoPanelLayout = new QVBoxLayout;
    infoPanelLayout->addWidget(m_pimpl->infoPanel);

    QHBoxLayout* summaryLayout = new QHBoxLayout;
    summaryLayout->addWidget(m_pimpl->resultSize);
    summaryLayout->addStretch(1);

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addLayout(infoPanelLayout, 1);
    layout->addLayout(summaryLayout);
    setLayout(layout);
}

TrafficView::~TrafficView()
{

}
