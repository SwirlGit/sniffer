#include "NetworkManager.h"

#include "NetworkLayer/Sniffer.h"

#include <QThread>

using ManagementLayer::NetworkManager;
using NetworkLayer::Sniffer;

NetworkManager::NetworkManager(QObject* parent) :
    QObject(parent)
{
}

void NetworkManager::start()
{
    m_sniffer.reset(new Sniffer());
    m_snifferThread.reset(new QThread);
    m_sniffer->moveToThread(m_snifferThread.get());
    connect(m_snifferThread.get(), &QThread::started, m_sniffer.get(), &Sniffer::listen);
    connect(m_sniffer.get(), &Sniffer::gotPackage, this, &NetworkManager::gotPackage);
    m_snifferThread->start();
}

void NetworkManager::stop()
{
    m_snifferThread->quit();
    m_snifferThread->wait();
}

void NetworkManager::configure(DataLayer::Settings settings)
{
    m_sniffer->setSettings(settings);
}

NetworkManager::~NetworkManager() = default;
