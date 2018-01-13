#include <QtGui/QApplication>
#include <QTextCodec>
#include "dialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec *codec = QTextCodec::codecForName("GBK");//ַי¿צ1
    QTextCodec::setCodecForTr(codec);
    QTextCodec::setCodecForLocale(codec);
    QTextCodec::setCodecForCStrings(codec);
    Dialog w;
    w.setObjectName("main");
    w.setStyleSheet("#main{border-image: url(:/img/img/background.jpg);}");
    w.show();

    return a.exec();
}
