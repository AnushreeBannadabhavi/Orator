QT       += core gui multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets multimedia multimediawidgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    interviewoptions.cpp \
    interviewstart.cpp \
    main.cpp \
    mainwindow.cpp \
    permissionpage.cpp \
    practiceoptions.cpp \
    promptscreen.cpp \
    publicspeaking.cpp \
    pubspeakingprompt.cpp \
    pubspstart.cpp \
    thankyouscreen.cpp

HEADERS += \
    interviewoptions.h \
    interviewstart.h \
    mainwindow.h \
    permissionpage.h \
    practiceoptions.h \
    promptscreen.h \
    publicspeaking.h \
    pubspeakingprompt.h \
    pubspstart.h \
    thankyouscreen.h

FORMS += \
    interviewoptions.ui \
    interviewstart.ui \
    mainwindow.ui \
    permissionpage.ui \
    practiceoptions.ui \
    promptscreen.ui \
    publicspeaking.ui \
    pubspeakingprompt.ui \
    pubspstart.ui \
    thankyouscreen.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc
