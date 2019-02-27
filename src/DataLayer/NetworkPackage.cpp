#include "NetworkPackage.h"

using DataLayer::NetworkPackage;

QString NetworkPackage::toString() const
{
    return "Sender: " + sender + "; " +
        "Receiver: " + receiver + "; " +
        "Protocol: " + protocol + "; " +
        "Size: " + QString::number(size) + "; " +
        "LifeTime: " + QString::number(lifeTIme) + ";";
}
