#include "TrafficView.h"
#include "TrafficViewPrivate.h"

#include <QLabel>
#include <QTextEdit>
#include <QVBoxLayout>

using DataLayer::NetworkPackage;
using ViewLayer::TrafficViewPrivate;
using ViewLayer::TrafficView;

namespace {
    const QVector<QString> sizeNames = {"byte", "Kb", "Mb", "Gb", "Tb"};

    QString sizeToString(long long int size) {
        int power = 0;
        const int maxPower = sizeNames.size();
        while ((size / 1024 > 0) && (power < maxPower - 1)) {
            power++;
            size /= 1024;
        }
        return QString::number(size) + " " + sizeNames[power];
    }
}

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

void TrafficView::addPackage(const NetworkPackage& package)
{
    m_pimpl->infoPanel->append(package.toString());
}

void TrafficView::updateSize(long long size)
{
    m_pimpl->resultSize->setText(sizeToString(size));
}
