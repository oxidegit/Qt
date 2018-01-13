#include "lightui.h"
#include "ui_lightui.h"
#include <QDebug>

lightUI::lightUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::lightUI)
{
    i = 0;
    j = 0;
    n = 0;
    m = 0;
    ui->setupUi(this);
}

lightUI::~lightUI()
{
    delete ui;
}

void lightUI::on_pushButton_clicked()
{
    j=j+1;
    if (j%2 == 0)
    {
        ui->pushButton->setStyleSheet(tr("border-image: url(:/image/room1_on.png);"));
     }
     else
     {
         ui->pushButton->setStyleSheet(tr("border-image: url(:/image/room1.png);"));
     }


}

void lightUI::on_pushButton_2_clicked()
{
    i++;

    if (i%2 == 0)
    {
        ui->pushButton_2->setStyleSheet(tr("border-image: url(:/image/room2_on.png);"));
    }
    else
    {
        ui->pushButton_2->setStyleSheet(tr("border-image: url(:/image/room2.png);"));
    }

}

void lightUI::on_pushButton_3_clicked()
{
    n++;

    if (n%2 == 0)
    {
        ui->pushButton_3->setStyleSheet(tr("border-image: url(:/image/room4_on.png);"));
    }
    else
    {
        ui->pushButton_3->setStyleSheet(tr("border-image: url(:/image/room4.png);"));
    }
}

void lightUI::on_pushButton_4_clicked()
{
    m++;

    if (m%2 == 0)
    {
        ui->pushButton_4->setStyleSheet(tr("border-image: url(:/image/room3_on.png);"));
    }
    else
    {
        ui->pushButton_4->setStyleSheet(tr("border-image: url(:/image/room3.png);"));
    }
}
