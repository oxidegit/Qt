#include "dialog.h"
#include "ui_dialog.h"

#include <qDebug>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    this->serial = new SerialCommunication();

    connect(serial->myCom, SIGNAL(readyRead()), this, SLOT(readMyCom()));

    this->setFixedSize(900,700);

    curPat = "����";
    npat = 0;
    nequ = 0;
    nlgh = 0;
    nevi = 0;

    QDateTime current_date_time = QDateTime::currentDateTime();
    QString current_date = current_date_time.toString("yyyy.MM.dd hh:mm ddd");

    //QString patStr = data.getPattern();

    patShowLab = new QLabel(curPat+"ģʽ",this);
    timShowLab = new QLabel(current_date,this);

    QPalette pe;
    pe.setColor(QPalette::WindowText,Qt::white);
    patShowLab->setPalette(pe);
    timShowLab->setPalette(pe);

    QFont ft("Microsoft YaHei", 18, 75);
    //ft.setPointSize(18);
    patShowLab->setFont(ft);
    timShowLab->setFont(ft);

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
    equButton = new QPushButton(this);
    lghButton = new QPushButton(this);
    eviButton = new QPushButton(this);

    patButton->setMinimumSize(30,100);
    equButton->setMinimumSize(30,100);
    lghButton->setMinimumSize(30,100);
    eviButton->setMinimumSize(30,100);

    patButton->setStyleSheet("QPushButton{border-image:url(:/img//img/model.jpg);}");
    equButton->setStyleSheet("QPushButton{border-image:url(:/img//img/equipment.jpg);}");
    lghButton->setStyleSheet("QPushButton{border-image:url(:/img//img/light.jpg);}");
    eviButton->setStyleSheet("QPushButton{border-image:url(:/img//img/atmosphere.jpg);}");

    QHBoxLayout *bomLayout = new QHBoxLayout(); // ����ĵ�����
    bomLayout->addWidget(patButton);
    bomLayout->addWidget(equButton);
    bomLayout->addWidget(lghButton);
    bomLayout->addWidget(eviButton);


    //bomLayout->setMargin(15);
    bomLayout->setContentsMargins(50,30,50,5);
    //bomLayout->setContentsMargins(QMargins(0,0,0,0));
    bomLayout->setSpacing(100);



    patWeidget = new patternUI(this);
    ligWeidget = new lightUI(this);
    equWeidget = new equipmentUI(this);
    envWeidget = new environmentUI(this);

    patWeidget->setSerial(serial);
    ligWeidget->setSerial(serial);
    equWeidget->setSerial(serial);
    envWeidget->setSerial(serial);

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
    npat ++ ;

    patWeidget->show();

    mainShowLab->hide();
    ligWeidget->hide();
    equWeidget->hide();
    envWeidget->hide();
    patWeidget->setPattern(curPat);

    if (npat%2 == 0)
    {
            patButton->setStyleSheet("QPushButton{border-image:url(:/img//img/model.jpg);}");
            patButton->setMinimumSize(30,100);
     }
     else
     {
            patButton->setStyleSheet("QPushButton{border-image:url(:/img//img/model_p.jpg);}");
            patButton->setMinimumSize(30,120);
     }

}

void Dialog::equButtonSlot()
{
    equWeidget->show();

    mainShowLab->hide();
    envWeidget->hide();
    ligWeidget->hide();
    patWeidget->hide();

    /*if (j%2 == 0)
    {
        ui->pushButton->setStyleSheet(tr("border-image: url(:/image/room1_on.png);"));
     }
     else
     {
         ui->pushButton->setStyleSheet(tr("border-image: url(:/image/room1.png);"));
     }*/
}

void Dialog::lghButtonSlot()
{
    ligWeidget->show();

    mainShowLab->hide();
    patWeidget->hide();
    envWeidget->hide();
    equWeidget->hide();

 /*   if (j%2 == 0)
    {
        ui->pushButton->setStyleSheet(tr("border-image: url(:/image/room1_on.png);"));
     }
     else
     {
         ui->pushButton->setStyleSheet(tr("border-image: url(:/image/room1.png);"));
     } */
}

void Dialog::eviButtonSlot()
{
    envWeidget->show();

    mainShowLab->hide();
    patWeidget->hide();
    equWeidget->hide();
    ligWeidget->hide();

  /*  if (j%2 == 0)
    {
        ui->pushButton->setStyleSheet(tr("border-image: url(:/image/room1_on.png);"));
     }
     else
     {
         ui->pushButton->setStyleSheet(tr("border-image: url(:/image/room1.png);"));
     }*/
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


void Dialog::readMyCom()
{
    QByteArray temp = serial->myCom->readAll();
    qDebug() << temp;

    QString s(temp);

    if (s == "m"){
        qDebug() << "ok";
    }
}






