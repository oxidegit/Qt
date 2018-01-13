#include "equipmentui.h"
#include "ui_equipmentui.h"

equipmentUI::equipmentUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::equipmentUI)
{
    QLabel *televLabel = new QLabel("电视",this);
    QLabel *soundLabel = new QLabel("音响",this);

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(televLabel,0,0,1,1);
    mainLayout->addWidget(soundLabel,1,0,1,1);
    //mainLayout->addWidget(dlackLabel,2,0,1,2);
    //mainLayout->addWidget(wlackLabel,3,0,1,2);

    // 设置水平间距
    mainLayout->setHorizontalSpacing(10);
    // 设置垂直间距
    mainLayout->setVerticalSpacing(10);
    // 设置外间距
    mainLayout->setContentsMargins(40, 40, 40, 40);

    this->setLayout(mainLayout);

    ui->setupUi(this);
}

equipmentUI::~equipmentUI()
{
    delete ui;
}
