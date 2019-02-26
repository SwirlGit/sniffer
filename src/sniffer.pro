#-------------------------------------------------
#
# Project created by QtCreator 2018-05-18T10:13:17
#
#-------------------------------------------------

QT       += core gui widgets network
CONFIG += c++14

QMAKE_CXXFLAGS_DEBUG += -pg
QMAKE_LFLAGS_DEBUG += -pg

TARGET = sniffer
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

LIBS += -lws2_32

######################################################################
# paths for building
######################################################################

MOC_DIR = moc
RCC_DIR = resources

!debug_and_release {

    # in case of debug_and_release object files
    # are built in the release and debug subdirectories
    OBJECTS_DIR       = obj
}

SOURCES += \
    main.cpp \
    Application.cpp \
    DataLayer/NetworkPackage.cpp \
    ManagementLayer/AbstractViewManager.cpp \
    ManagementLayer/ApplicationManager.cpp \
    ManagementLayer/ConfigurationManager.cpp \
    ManagementLayer/NetworkManager.cpp \
    ManagementLayer/TrafficManager.cpp \
    NetworkLayer/Sniffer.cpp \
    ViewLayer/ApplicationView.cpp \
    ViewLayer/Configuration/ConfigurationView.cpp \
    ViewLayer/Traffic/TrafficView.cpp \
    DataLayer/Settings.cpp




HEADERS += \
    Application.h \
    DataLayer/NetworkPackage.h \
    ManagementLayer/AbstractViewManager.h \
    ManagementLayer/ApplicationManager.h \
    ManagementLayer/ConfigurationManager.h \
    ManagementLayer/NetworkManager.h \
    ManagementLayer/TrafficManager.h \
    NetworkLayer/Sniffer.h \
    ViewLayer/ApplicationView.h \
    ViewLayer/ApplicationViewPrivate.h \
    ViewLayer/Configuration/ConfigurationView.h \
    ViewLayer/Configuration/ConfigurationViewPrivate.h \
    ViewLayer/Traffic/TrafficView.h \
    ViewLayer/Traffic/TrafficViewPrivate.h \
    DataLayer/Settings.h

