#ifndef PATTERNUI_H
#define PATTERNUI_H

#include <QDialog>
#include <QLabel>
#include <QString>
#include <QObject>
#include <QDateTime>
#include <QPushButton>
#include <QBoxLayout>
#include <QVBoxLayout>   // 水平
#include <QHBoxLayout>   // 垂直
#include <QGridLayout>   // 网状
#include <QFormLayout>
#include <QWidget>
#include <QDebug>
#include <QLineEdit>

#include "serialcommunication.h"

namespace Ui {
    class patternUI;
}

struct Pattern
{
    QString p_Name;
    int p_Temp;
    int p_Humid;
   // int p_Door;
    //int p_Wins;
    QString p_Door;
    QString p_Wins;

};

class patternUI : public QWidget
{
    Q_OBJECT

public:
    explicit patternUI(QWidget *parent = 0);
    ~patternUI();

    void setSerial(SerialCommunication *s){serial = s;};

    void setPattern(QString p);

    int sendTem(int p);
    int sendHum(int p);

    void refValue(int p);
    void setValue();

signals:
    void signalP(int);

    void signalT(int);
    void signalH(int);

private slots:

    void aqPatButtonSlot();
    void smPatButtonSlot();
    void ljPatButtonSlot();
    void shPatButtonSlot();

    void chooseButSlot();
    void setvalButSlot();

    void okkkkkButSlot();
    void cancelButSlot();

    //void toDialogSlot();

private:
    Ui::patternUI *ui;

    QLabel *doorlack;
    QLabel *windowlack;
    QLineEdit *temLineEdit;
    QLineEdit *humLineEdit;

    QPushButton *aqPatButton;//安全模式
    QPushButton *smPatButton;//睡眠
    QPushButton *ljPatButton;//离家
    QPushButton *shPatButton;//生活

    QPushButton *temAddBut;
    QPushButton *temSelBut;
    QPushButton *humAddBut;
    QPushButton *humSelBut;

    QPushButton *chooseBut;
    QPushButton *setvalBut;
    QPushButton *okkkkkBut;
    QPushButton *cancelBut;


    Pattern pattern[4];

    QString pName;
    int pTemp;
    int pHumid;
    int pDoor;
    int pWins;
    int pchoose;

    SerialCommunication *serial;
};

#endif // PATTERNUI_H
