#ifndef EQUIPMENTUI_H
#define EQUIPMENTUI_H

#include <QWidget>
#include <QLabel>
#include <QGridLayout>   // Íø×´
#include "switchbutton.h"

namespace Ui {
    class equipmentUI;
}

class equipmentUI : public QWidget
{
    Q_OBJECT

public:
    explicit equipmentUI(QWidget *parent = 0);
    ~equipmentUI();

private slots:
    void switchTelButSlot();
    void switchSouButSlot();
signals:
    void clicked();

private:
    Ui::equipmentUI *ui;

    SwitchButton *switchTelBut;
    SwitchButton *switchSouBut;

    int e_TV;
    int e_JBL;
};

#endif // EQUIPMENTUI_H
