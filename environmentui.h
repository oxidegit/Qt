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
    void setSerial(SerialCommunication *s){serial = s;};

    explicit environmentUI(QWidget *parent = 0);
    ~environmentUI();

    void Add_Temperature();
    void Reduce_Temperature();
    void Add_Humidity();
    void Reduce_Humidity();


public slots:
    void getTemperature(int t);
    void gethumidity(int h);



private:
    SerialCommunication *serial;
    Ui::environmentUI *ui;

    int Temperature;
    int humidity;

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
