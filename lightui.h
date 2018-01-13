#ifndef LIGHTUI_H
#define LIGHTUI_H

#include <QWidget>
#include <QPushButton>
#include "serialcommunication.h"

namespace Ui {
    class lightUI;
}

class lightUI : public QWidget
{
    Q_OBJECT

public:
    explicit lightUI(QWidget *parent = 0);
    ~lightUI();
    int i;
    int j;
    int n;
    int m;

    void setSerial(SerialCommunication *s){serial = s;};

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::lightUI *ui;

    SerialCommunication *serial;
};

#endif // WIDGET_H
