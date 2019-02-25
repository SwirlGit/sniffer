#ifndef NETWORKPACKAGE_H
#define NETWORKPACKAGE_H

#include "QString"

namespace DataLayer {

struct NetworkPackage {
    QString sender;
    QString receiver;
    QString protocol;
    int size;
    int lifeTIme;
};

} // namespace DataLayer

#endif // NETWORKPACKAGE_H
