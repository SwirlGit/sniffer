#include "ConfigurationView.h"
#include "ConfigurationViewPrivate.h"

#include <QCheckBox>
#include <QGroupBox>
#include <QPushButton>
#include <QTextEdit>
#include <QVBoxLayout>

using DataLayer::Settings;
using ViewLayer::ConfigurationViewPrivate;
using ViewLayer::ConfigurationView;


ConfigurationViewPrivate::ConfigurationViewPrivate(QWidget* parent) :
    protocolFilterGroupBox(new QGroupBox(parent)),
    tcpCheckBox(new QCheckBox("TCP", parent)),
    udpCheckBox(new QCheckBox("UDP", parent)),
    ipCheckBox(new QCheckBox("IP filter", parent)),
    ipTextEdit(new QTextEdit(parent)),
    restoreButton(new QPushButton(parent)),
    applyButton(new QPushButton(parent))
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
    m_pimpl->restoreButton->setText("Restore");
    m_pimpl->applyButton->setText("Apply");
    fillSettings();

    QVBoxLayout* groupBoxLayout = new QVBoxLayout;
    groupBoxLayout->addWidget(m_pimpl->tcpCheckBox);
    groupBoxLayout->addWidget(m_pimpl->udpCheckBox);
    groupBoxLayout->addStretch(0);
    m_pimpl->protocolFilterGroupBox->setLayout(groupBoxLayout);

    QVBoxLayout* protocolLayout = new QVBoxLayout;
    protocolLayout->addWidget(m_pimpl->protocolFilterGroupBox);

    QVBoxLayout* ipLayout = new QVBoxLayout;
    ipLayout->addWidget(m_pimpl->ipCheckBox);
    ipLayout->addWidget(m_pimpl->ipTextEdit);

    QHBoxLayout* settingsLayout = new QHBoxLayout;
    settingsLayout->addLayout(protocolLayout);
    settingsLayout->addLayout(ipLayout);

    QHBoxLayout* buttonsLayout = new QHBoxLayout;
    buttonsLayout->addStretch(1);
    buttonsLayout->addWidget(m_pimpl->restoreButton);
    buttonsLayout->addWidget(m_pimpl->applyButton);

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addLayout(settingsLayout, 1);
    layout->addLayout(buttonsLayout);
    setLayout(layout);

    connect(m_pimpl->ipCheckBox, &QCheckBox::toggled, [this] (bool checked) {
        m_pimpl->ipTextEdit->setReadOnly(!checked);
    });
    connect(m_pimpl->restoreButton, &QPushButton::clicked, this, &ConfigurationView::restoreSettings);
    connect(m_pimpl->applyButton, &QPushButton::clicked, [this] {
        fillSettings();
        emit applySettingsPressed(settings);
    });
}

ConfigurationView::~ConfigurationView()
{
}

void ConfigurationView::fillSettings()
{
    settings.protocolFilter.tcp = m_pimpl->tcpCheckBox->isChecked();
    settings.protocolFilter.udp = m_pimpl->udpCheckBox->isChecked();
    settings.ipFilter.filter = m_pimpl->ipCheckBox->isChecked();
    const QString ipsString = m_pimpl->ipTextEdit->toPlainText();
    settings.ipFilter.ips = ipsString.split('\n', QString::SkipEmptyParts);
}

void ConfigurationView::restoreSettings()
{
    m_pimpl->tcpCheckBox->setChecked(settings.protocolFilter.tcp);
    m_pimpl->udpCheckBox->setChecked(settings.protocolFilter.udp);
    m_pimpl->ipCheckBox->setChecked(settings.ipFilter.filter);
    m_pimpl->ipTextEdit->setText(settings.ipFilter.ips.join('\n'));
}
