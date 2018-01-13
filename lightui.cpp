#include "lightui.h"
#include "ui_lightui.h"

lightUI::lightUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::lightUI)
{
    ui->setupUi(this);
}

lightUI::~lightUI()
{
    delete ui;
}
