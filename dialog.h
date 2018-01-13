#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLabel>
#include <QObject>
#include <QString>
#include <QDateTime>
#include <QPushButton>
#include <QPalette>
#include <QFont>
#include <QBoxLayout>
#include <QVBoxLayout>   // Ë®Æ½
#include <QHBoxLayout>   // ´¹Ö±
#include <QGridLayout>   // Íø×´

#include <QIODevice>

#include "patternui.h"
#include "lightui.h"
#include "equipmentui.h"
#include "environmentui.h"

#include "win_qextserialport.h"
#include "serialcommunication.h"

//#include "data.h"

namespace Ui {
    class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

public slots:
    void setModeText(int mode);
    void readMyCom();
private slots:
    void patButtonSlot();
    void equButtonSlot();
    void lghButtonSlot();
    void eviButtonSlot();

private:
    Ui::Dialog *ui;

    patternUI *patWeidget;
    lightUI *ligWeidget;
    equipmentUI *equWeidget;
    environmentUI *envWeidget;

    QLabel *patShowLab;
    QLabel *timShowLab;
    QLabel *mainShowLab;


    QPushButton *patButton;
    QPushButton *equButton;
    QPushButton *lghButton;
    QPushButton *eviButton;

    //Data data;
    QString curPat;
    int npat;
    int nequ;
    int nlgh;
    int nevi;

    SerialCommunication *serial;
};

#endif // DIALOG_H
