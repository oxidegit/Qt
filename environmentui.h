#ifndef ENVIRONMENTUI_H
#define ENVIRONMENTUI_H

#include <QWidget>
#include <QDebug>
#include "serialcommunication.h"

namespace Ui {
    class environmentUI;
}

class environmentUI : public QWidget
{
    Q_OBJECT

public:

    explicit environmentUI(QWidget *parent = 0);
    ~environmentUI();


    void setSerial(SerialCommunication *s){serial = s;};

public slots:
    void getTemperature(int t);
    void gethumidity(int h);

private:
    Ui::environmentUI *ui;

    int Temperature;
    int humidity;

    SerialCommunication *serial;

private slots:

    void on_Add_Temperature_clicked();

    void on_Reduce_Temperature_clicked();

    void on_Add_Humidity_clicked();

    void on_Reduce_Humidity_clicked();

/*signals:
    void dlgshow();
    void quit();*/


};

#endif // ENVIRONMENTUI_H
