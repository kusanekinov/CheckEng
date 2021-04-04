#pragma once
#include <QObject>

#define TR_CLASS(cls) class cls: public QObject { \
    Q_OBJECT \
};

TR_CLASS(iInfo)
TR_CLASS(iMsg)
TR_CLASS(iMenu)
TR_CLASS(iError)
TR_CLASS(iDesc)
