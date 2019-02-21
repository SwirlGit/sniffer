#-------------------------------------------------
#
# Project created by QtCreator 2018-05-18T10:13:17
#
#-------------------------------------------------

QT       += core gui widgets
CONFIG += c++14

QMAKE_CXXFLAGS_DEBUG += -pg
QMAKE_LFLAGS_DEBUG += -pg

TARGET = sniffer
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS


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
    ManagementLayer/AbstractViewManager.cpp \
    ManagementLayer/ApplicationManager.cpp \
    ViewLayer/ApplicationView.cpp



HEADERS += \
    Application.h \
    ManagementLayer/AbstractViewManager.h \
    ManagementLayer/ApplicationManager.h \
    ViewLayer/ApplicationView.h \
    ViewLayer/ApplicationViewPrivate.h
