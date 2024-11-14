QT       += core gui widgets charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    exceptions.cpp \
    filter.cpp \
    filter_form.cpp \
    filter_list.cpp \
    graph_widget.cpp \
    main.cpp \
    mainwindow.cpp \
    project.cpp \
    project_info_form.cpp \
    project_journal.cpp \
    sort_form.cpp

HEADERS += \
    comparator.h \
    exceptions.h \
    filter.h \
    filter_form.h \
    filter_list.h \
    graph_widget.h \
    mainwindow.h \
    project.h \
    project_info_form.h \
    project_journal.h \
    sort_form.h

FORMS += \
    filter_form.ui \
    graph_widget.ui \
    mainwindow.ui \
    project_info_form.ui \
    sort_form.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Readme
