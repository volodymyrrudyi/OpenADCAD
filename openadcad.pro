QT       += core gui svg xml

TARGET = openadcad
TEMPLATE = app

HEADERS += \
    componentloader.h \
    project.h \
    component.h \
    mainwindow.h \
    createprojectdialog.h \
    graphicscomponent.h \
    abstractscheme.h \
    dlgprincipalcomponentlibrary.h \
    xmlcomponentloader.h \
    componentinfo.h \
    textcomponent.h \
    dialogeditcomponent.h \
    schemeview.h \
    wireconnection.h \
    componentcommand.h \
    applicationutils.h \
    componentstorage.h

SOURCES += \
    componentloader.cpp \
    project.cpp \
    component.cpp \
    main.cpp \
    mainwindow.cpp \
    createprojectdialog.cpp \
    graphicscomponent.cpp \
    abstractscheme.cpp \
    dlgprincipalcomponentlibrary.cpp \
    xmlcomponentloader.cpp \
    componentinfo.cpp \
    textcomponent.cpp \
    dialogeditcomponent.cpp \
    schemeview.cpp \
    wireconnection.cpp \
    componentcommand.cpp \
    applicationutils.cpp \
    componentstorage.cpp

FORMS += \
    mainwindow.ui \
    createprojectdialog.ui \
    dlgprincipalcomponentlibrary.ui \
    dialogeditcomponent.ui

RESOURCES += \
    res.qrc

OTHER_FILES += \
    lib/library.principal.std.xml
