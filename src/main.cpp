#include "Application.h"

#include "DataLayer/NetworkPackage.h"
Q_DECLARE_METATYPE(DataLayer::NetworkPackage)

int main(int argc, char* argv[]) {
    Application a(argc, argv);
    return a.exec();
}
