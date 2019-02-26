#ifndef SETTINGS_H
#define SETTINGS_H

#include "QStringList"

namespace DataLayer {

struct ProtocolFilter {
    bool tcp;
    bool udp;
};

struct IpFilter {
    bool filter;
    QStringList ips;
};

struct Settings {
    ProtocolFilter protocolFilter;
    IpFilter ipFilter;
};

} // namespace DataLayer

#endif // SETTINGS_H
