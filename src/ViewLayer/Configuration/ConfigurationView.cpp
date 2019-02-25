#include "ConfigurationView.h"
#include "ConfigurationViewPrivate.h"

#include <QCheckBox>
#include <QGroupBox>
#include <QTextEdit>
#include <QVBoxLayout>

using ViewLayer::ConfigurationViewPrivate;
using ViewLayer::ConfigurationView;


ConfigurationViewPrivate::ConfigurationViewPrivate(QWidget* parent) :
    protocolFilterGroupBox(new QGroupBox(parent)),
    tcpCheckBox(new QCheckBox("TCP", parent)),
    udpCheckBox(new QCheckBox("UDP", parent)),
    ipCheckBox(new QCheckBox("IP filter", parent)),
    ipTextEdit(new QTextEdit)
{
}


// ****

ConfigurationView::ConfigurationView(QWidget *parent) :
    QFrame(parent),
    m_pimpl(new ConfigurationViewPrivate(parent))
{
    setObjectName("configurationView");

    m_pimpl->protocolFilterGroupBox->setTitle("Protocol");

    m_pimpl->tcpCheckBox->setChecked(true);
    m_pimpl->udpCheckBox->setChecked(true);
    m_pimpl->ipCheckBox->setChecked(false);
    m_pimpl->ipTextEdit->setReadOnly(true);

    QVBoxLayout* groupBoxLayout = new QVBoxLayout;
    groupBoxLayout->addWidget(m_pimpl->tcpCheckBox);
    groupBoxLayout->addWidget(m_pimpl->udpCheckBox);
    groupBoxLayout->addStretch(0);
    m_pimpl->protocolFilterGroupBox->setLayout(groupBoxLayout);

    QVBoxLayout* protocolLayout = new QVBoxLayout;
    protocolLayout->addWidget(m_pimpl->protocolFilterGroupBox);
    protocolLayout->addStretch(1);

    QVBoxLayout* ipLayout = new QVBoxLayout;
    ipLayout->addWidget(m_pimpl->ipCheckBox);
    ipLayout->addWidget(m_pimpl->ipTextEdit);
    ipLayout->addStretch(1);

    QHBoxLayout* layout = new QHBoxLayout;
    layout->addLayout(protocolLayout);
    layout->addLayout(ipLayout);
    layout->addStretch(1);
    setLayout(layout);

    connect(m_pimpl->ipCheckBox, &QCheckBox::toggled, [this] (bool checked) {
        m_pimpl->ipTextEdit->setReadOnly(!checked);
    });
}

ConfigurationView::~ConfigurationView()
{

}
