#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{

    this->setFixedSize(900,600);

    curPat = "����";

    QDateTime current_date_time = QDateTime::currentDateTime();
    QString current_date = current_date_time.toString("yyyy.MM.dd hh:mm ddd");

    //QString patStr = data.getPattern();

    patShowLab = new QLabel(curPat+"ģʽ",this);
    timShowLab = new QLabel(current_date,this);

    QHBoxLayout *topLayout = new QHBoxLayout(); // �����label
    topLayout->addWidget(patShowLab);   // ģʽ��
    topLayout->addWidget(timShowLab);   // ʱ��
    //patShowLab->show();
    topLayout->setMargin(0);
    topLayout->setSpacing(0);

    mainShowLab = new QLabel("����ŵ����������ﻹû��õ��׷�ɶ�Ķ�����˵���׷ŵ�ʲô�ط�һ��logo�ǲ����е�յ��ǲ���logo����֪����ʲô�����׷�ʲô�غþ���ѽ",this);
    QHBoxLayout *midLayout = new QHBoxLayout();
    midLayout->addWidget(mainShowLab);

    patButton = new QPushButton(this);
    equButton = new QPushButton("�豸",this);
    lghButton = new QPushButton("����",this);
    eviButton = new QPushButton("����",this);

    patButton->setMinimumSize(40,100);

    patButton->setStyleSheet("QPushButton{border-image:url(:/img//img/model.jpg);}");

    QHBoxLayout *bomLayout = new QHBoxLayout(); // ����ĵ�����
    bomLayout->addWidget(patButton);
    bomLayout->addWidget(equButton);
    bomLayout->addWidget(lghButton);
    bomLayout->addWidget(eviButton);


    //bomLayout->setMargin(15);
    bomLayout->setContentsMargins(50,10,50,5);
    //bomLayout->setContentsMargins(QMargins(0,0,0,0));
    bomLayout->setSpacing(80);



    patWeidget = new patternUI(this);
    ligWeidget = new lightUI(this);
    equWeidget = new equipmentUI(this);
    envWeidget = new environmentUI(this);

    patWeidget->setValue();

    midLayout->addWidget(patWeidget);
    midLayout->addWidget(ligWeidget);
    midLayout->addWidget(equWeidget);
    midLayout->addWidget(envWeidget);

    patWeidget->hide();
    ligWeidget->hide();
    equWeidget->hide();
    envWeidget->hide();

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(topLayout);
    mainLayout->addLayout(midLayout);
    mainLayout->addLayout(bomLayout);

    mainLayout->setStretchFactor(topLayout, 0.5);
    mainLayout->setStretchFactor(midLayout, 3);
    mainLayout->setStretchFactor(bomLayout, 2);

    //this->adjustSize();
    this->setLayout(mainLayout);

    connect(patButton,SIGNAL(clicked()),this,SLOT(patButtonSlot()));
    connect(equButton,SIGNAL(clicked()),this,SLOT(equButtonSlot()));
    connect(lghButton,SIGNAL(clicked()),this,SLOT(lghButtonSlot()));
    connect(eviButton,SIGNAL(clicked()),this,SLOT(eviButtonSlot()));

    /***************************************��******************************/
    connect(patWeidget, SIGNAL(signalP(int)), this, SLOT(setModeText(int)));
    connect(patWeidget, SIGNAL(signalT(int)), envWeidget, SLOT(getTemperature(int)));
    connect(patWeidget, SIGNAL(signalH(int)), envWeidget, SLOT(gethumidity(int)));

    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::patButtonSlot()
{
    patWeidget->show();

    mainShowLab->hide();
    ligWeidget->hide();
    equWeidget->hide();
    envWeidget->hide();
    patWeidget->setPattern(curPat);
}

void Dialog::equButtonSlot()
{
    equWeidget->show();

    mainShowLab->hide();
    envWeidget->hide();
    ligWeidget->hide();
    patWeidget->hide();
}

void Dialog::lghButtonSlot()
{
    ligWeidget->show();

    mainShowLab->hide();
    patWeidget->hide();
    envWeidget->hide();
    equWeidget->hide();
}

void Dialog::eviButtonSlot()
{
    envWeidget->show();

    mainShowLab->hide();
    patWeidget->hide();
    equWeidget->hide();
    ligWeidget->hide();
}

void Dialog::setModeText(int mode)
{
    if (mode == 0)
    {
        curPat = "��ȫ";
        this->patShowLab->setText("��ȫģʽ");
    }
    else if (mode == 1)
    {
        curPat = "˯��";
        this->patShowLab->setText("˯��ģʽ");
    }
    else if (mode == 2)
    {
        curPat = "���";
        this->patShowLab->setText("���ģʽ");
    }
    else if (mode == 3)
    {
        curPat = "����";
        this->patShowLab->setText("����ģʽ");
    }
    //qDebug() << "���ճɹ�";
}






