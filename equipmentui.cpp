#include "equipmentui.h"
#include "ui_equipmentui.h"

equipmentUI::equipmentUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::equipmentUI)
{
    QLabel *televLabel = new QLabel(this);
    QLabel *soundLabel = new QLabel(this);

    //televLabel->setText("<font color=white size=18><B>����</B></font>");
    //soundLabel->setStyleSheet("color:#fffafa;");

    QLabel *Label_1 = new QLabel(this);
    QLabel *Label_2 = new QLabel(this);
    QLabel *Label_3 = new QLabel(this);
    QLabel *Label_4 = new QLabel(this);
    Label_1->setText("<font face='STHupo' color=white size=18>����          </font>");
    Label_2->setText("<font face='STHupo' color=white size=18>����          </font>");
    Label_3->setText("   ");
    Label_4->setText("   ");

    switchTelBut = new SwitchButton(this);
    switchSouBut = new SwitchButton(this);

    televLabel->setStyleSheet("QLabel{border-image:url(:/img/img/TV.png);}");
    soundLabel->setStyleSheet("QLabel{border-image:url(:/img/img/JBL.png);}");

    televLabel->setMaximumSize(200,200);
    soundLabel->setMaximumSize(200,200);
    televLabel->setMinimumSize(200,200);
    //soundLabel->setMinimumSize(200,200);

    QGridLayout *mainLayout = new QGridLayout;
      mainLayout->addWidget(televLabel,0,1,3,1);
    mainLayout->addWidget(switchTelBut,1,3,1,1);
      mainLayout->addWidget(soundLabel,2,1,2,1);
    mainLayout->addWidget(switchSouBut,3,3,1,1);

    mainLayout->addWidget(Label_1,1,2,1,1);
    mainLayout->addWidget(Label_2,3,2,1,1);
    mainLayout->addWidget(Label_3,1,4,1,1);
    mainLayout->addWidget(Label_4,3,4,1,1);

    // �б�   ��0�����3��֮��Ϊ 3:1
    //mainLayout->setColumnStretch(0,1);
    //mainLayout->setColumnStretch(3,1);
    // �б�   ��0�����1��֮��Ϊ1:1
   // mainLayout-> setRowStretch(0, 1);
   // mainLayout-> setRowStretch(1, 1);



    // ����ˮƽ���
    mainLayout->setHorizontalSpacing(100);
    // ���ô�ֱ���
    mainLayout->setVerticalSpacing(80);
    // ��������
    mainLayout->setContentsMargins(60,50,60,50);

    this->setLayout(mainLayout);

    connect(switchTelBut,SIGNAL(checkedChanged(bool)),this,SLOT(switchTelButSlot(bool)));
    connect(switchSouBut,SIGNAL(checkedChanged(bool)),this,SLOT(switchSouButSlot(bool)));

    connect(switchTelBut,SIGNAL(clicked()),this,SLOT(switchTelButSlot()));
    connect(switchSouBut,SIGNAL(clicked()),this,SLOT(switchSouButSlot()));

    ui->setupUi(this);
}

equipmentUI::~equipmentUI()
{
    delete ui;
}


void equipmentUI::switchTelButSlot(bool)
{
    serial->qtUpdateEquipState(TV);//同步qt
}


void equipmentUI::switchSouButSlot()
{
    serial->qtUpdateEquipState(AUDIO);//同步qt
}
