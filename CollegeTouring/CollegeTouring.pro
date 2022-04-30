QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    admin.cpp \
    college_list.cpp \
    customtrip.cpp \
    dbcolleges.cpp \
    displaysouvenirs.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    tripplanner.cpp

HEADERS += \
    admin.h \
    college_list.h \
    customtrip.h \
    dbcolleges.h \
    displaysouvenirs.h \
    graph.h \
    login.h \
    orderedmap.h \
    mainwindow.h \
    tripplanner.h \
    vertex.h

FORMS += \
    admin.ui \
    collegelist.ui \
    customtrip.ui \
    displaysouvenirs.ui \
    login.ui \
    mainwindow.ui \
    tripplanner.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Distances.csv \
    Souvenirs.csv
