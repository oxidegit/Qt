#include "lightui.h"
#include "ui_lightui.h"
#include <QDebug>

lightUI::lightUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::lightUI)
{
    i = 1;
    j = 1;
    n = 1;
    m = 1;
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

    serial->qtUpdateLightState(KICHEN);


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

    serial->qtUpdateLightState(DRAWINGROOM);

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

    serial->qtUpdateLightState(BATHROOM);
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

    serial->qtUpdateLightState(BEDROOM);
}


void lightUI::setLight(int x)
{
    if (x == 1)
    {
        j ++ ;

        if (j%2 == 0)
        {
            ui->pushButton->setStyleSheet(tr("border-image: url(:/image/room1_on.png);"));
        }
        else
        {
             ui->pushButton->setStyleSheet(tr("border-image: url(:/image/room1.png);"));
        }
    }
    else if (x == 2)
    {
        i ++;

        if (i%2 == 0)
        {
            ui->pushButton_2->setStyleSheet(tr("border-image: url(:/image/room2_on.png);"));
        }
        else
        {
            ui->pushButton_2->setStyleSheet(tr("border-image: url(:/image/room2.png);"));
        }
    }
    else if (x == 3)
    {
        n ++ ;

        if (n%2 == 0)
        {
            ui->pushButton_3->setStyleSheet(tr("border-image: url(:/image/room4_on.png);"));
        }
        else
        {
            ui->pushButton_3->setStyleSheet(tr("border-image: url(:/image/room4.png);"));
        }
    }
    else if (x == 4)
    {
        m ++;

        if (m%2 == 0)
        {
            ui->pushButton_4->setStyleSheet(tr("border-image: url(:/image/room3_on.png);"));
        }
        else
        {
            ui->pushButton_4->setStyleSheet(tr("border-image: url(:/image/room3.png);"));
        }
    }
}
