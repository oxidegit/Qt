#include "environmentui.h"
#include "ui_environmentui.h"

environmentUI::environmentUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::environmentUI)
{
    ui->setupUi(this);


    Temperature = 23;
    humidity = 60;

    QString data1 = QString("%1").arg(Temperature);
    ui->Label_Temperature->setText(data1);

    QString data2 = QString("%1").arg(humidity);
    ui->Label_Humidity->setText(data2);
}

environmentUI::~environmentUI()
{
    delete ui;
}

void environmentUI::on_Add_Temperature_clicked()
{
    Temperature++;
    if(Temperature < 10 || Temperature > 48)
    {
        Temperature--;
    }
    QString data1 = QString("%1").arg(Temperature);
    ui->Label_Temperature->setText(data1);
}

void environmentUI::on_Reduce_Temperature_clicked()
{
    Temperature--;
    if(Temperature < 10 || Temperature > 48)
    {
        Temperature++;
    }
    QString data1 = QString("%1").arg(Temperature);
    ui->Label_Temperature->setText(data1);
}

void environmentUI::on_Add_Humidity_clicked()
{
    humidity++;

    if(humidity < 8 || humidity > 98)
    {
        humidity--;
    }
    QString data1 = QString("%1").arg(humidity);
    ui->Label_Humidity->setText(data1);
}

void environmentUI::on_Reduce_Humidity_clicked()
{
    humidity--;
    if(humidity < 8 || humidity > 98)
    {
        humidity++;
    }
    QString data1 = QString("%1").arg(humidity);
    ui->Label_Humidity->setText(data1);
}


void environmentUI::getTemperature(int t)
{
     Temperature = t;
     //qDebug() << "接收成功";
     QString data1 = QString("%1").arg(Temperature);
     ui->Label_Temperature->setText(data1);
}

void environmentUI::gethumidity(int h)
{
     humidity = h;
     //qDebug() << "接收成功";
     QString data1 = QString("%1").arg(humidity);
     ui->Label_Humidity->setText(data1);
}
