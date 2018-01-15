#ifndef EQUIPMENTUI_H
#define EQUIPMENTUI_H

#include <QWidget>
#include <QLabel>
#include <QGridLayout>   // Íø×´
#include "switchbutton.h"

#include "serialcommunication.h"

namespace Ui {
    class equipmentUI;
}

class equipmentUI : public QWidget
{
    Q_OBJECT

public:
    void setSerial(SerialCommunication *s){serial = s;};

    explicit equipmentUI(QWidget *parent = 0);
    ~equipmentUI();

    void reverseTvState(){switchTelBut->reverseState();};
    void reverseAudioState(){switchSouBut->reverseState();};

private slots:
    void switchTelButSlot(bool);
    void switchSouButSlot(bool);
signals:
    void clicked();

private:
    Ui::equipmentUI *ui;

    SwitchButton *switchTelBut;
    SwitchButton *switchSouBut;

    int e_TV;
    int e_JBL;

    SerialCommunication *serial;
};

#endif // EQUIPMENTUI_H
