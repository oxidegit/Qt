#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{

    this->serial = new SerialCommunication();
    connect(serial->myCom, SIGNAL(readyRead()), this, SLOT(readMyCom()));

    this->setFixedSize(900,700);

    curPat = "����";
    curButton = 0;
    prveButton = 0;

    QDateTime current_date_time = QDateTime::currentDateTime();
    QString current_date = current_date_time.toString("yyyy.MM.dd hh:mm ddd");

    //QString patStr = data.getPattern();

    patShowLab = new QLabel(curPat+"ģʽ",this);
    timShowLab = new QLabel(current_date,this);

    QPalette pe;
    pe.setColor(QPalette::WindowText,Qt::white);
    patShowLab->setPalette(pe);
    timShowLab->setPalette(pe);

    QFont ft("STHupo", 24, 20);
    //ft.setPointSize(18);
    patShowLab->setFont(ft);
    timShowLab->setFont(ft);

    QHBoxLayout *topLayout = new QHBoxLayout(); // �����label
    topLayout->addWidget(patShowLab);   // ģʽ��
    topLayout->addWidget(timShowLab);   // ʱ��
    topLayout->setMargin(0);
    topLayout->setSpacing(0);

    mainShowLab = new QLabel("��Ȼ����ĳ���ķ�����!\n���Ǿʹ󷢴ȱ��ĸ����㣡\nΪ�˷�ֹ���类�ƻ�!\nΪ���ػ�����ĺ�ƽ!\n�᳹������ʵ��а��!\n�ɰ������˵ķ��ɽ�ɫ!\n��أ� С���ɣ�\n�����Ǵ��������ӵĻ���ӣ�\n�׶�����ɫ�������ڵ������ǣ�\n��������!��!",this);
    QFont fy("STHupo", 20, 22);
    mainShowLab->setPalette(pe);
    mainShowLab->setFont(fy);

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
    bomLayout->setContentsMargins(50,30,50,0);
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
    curButton = 1;

    int p = getPrve();
    setPrve(curButton);

    setButtonImg(curButton,p);

    patButton->setEnabled(false);
    equButton->setEnabled(true);
    lghButton->setEnabled(true);
    eviButton->setEnabled(true);

    patWeidget->show();

    mainShowLab->hide();
    ligWeidget->hide();
    equWeidget->hide();
    envWeidget->hide();
    patWeidget->setPattern(curPat);

}

void Dialog::equButtonSlot()
{
    curButton = 2;

    int p = getPrve();
    setPrve(curButton);

    setButtonImg(curButton,p);

    patButton->setEnabled(true);
    equButton->setEnabled(false);
    lghButton->setEnabled(true);
    eviButton->setEnabled(true);

    equWeidget->show();

    mainShowLab->hide();
    envWeidget->hide();
    ligWeidget->hide();
    patWeidget->hide();

}

void Dialog::lghButtonSlot()
{
    curButton = 3;

    int p = getPrve();
    setPrve(curButton);

    setButtonImg(curButton,p);

    patButton->setEnabled(true);
    equButton->setEnabled(true);
    lghButton->setEnabled(false);
    eviButton->setEnabled(true);

    ligWeidget->show();

    mainShowLab->hide();
    patWeidget->hide();
    envWeidget->hide();
    equWeidget->hide();

}

void Dialog::eviButtonSlot()
{
    curButton = 4;

    int p = getPrve();
    setPrve(curButton);

    setButtonImg(curButton,p);

    patButton->setEnabled(true);
    equButton->setEnabled(true);
    lghButton->setEnabled(true);
    eviButton->setEnabled(false);

    envWeidget->show();

    mainShowLab->hide();
    patWeidget->hide();
    equWeidget->hide();
    ligWeidget->hide();
}


int Dialog::getPrve()
{
    return prveButton;
}

void Dialog::setPrve(int c)
{
    prveButton = c;
}

void Dialog::setButtonImg(int c,int p)
{
    if (c == 1)    // ģʽ��ť����
    {
        patButton->setStyleSheet("QPushButton{border-image:url(:/img//img/model_p.jpg);}");
        patButton->setMinimumSize(30,120);

    }
    else if (c == 2)    // �豸��ť����
    {
        equButton->setStyleSheet("QPushButton{border-image:url(:/img//img/equipment_p.jpg);}");
        equButton->setMinimumSize(30,120);
    }
    else if (c == 3)    //������ť����
    {
        lghButton->setStyleSheet("QPushButton{border-image:url(:/img//img/light_p.jpg);}");
        lghButton->setMinimumSize(30,120);
    }
    else if (c == 4)    //������ť����
    {
        eviButton->setStyleSheet("QPushButton{border-image:url(:/img//img/atmosphere_p.jpg);}");
        eviButton->setMinimumSize(30,120);
    }

    ///////////////////////////////////////////////////////////////


    if (p == 1)    //ģʽ��ť��ԭ
    {
        patButton->setStyleSheet("QPushButton{border-image:url(:/img//img/model.jpg);}");
        patButton->setMinimumSize(30,100);
    }
    else if (p == 2)    //�豸��ť��ԭ
    {
        equButton->setStyleSheet("QPushButton{border-image:url(:/img//img/equipment.jpg);}");
        equButton->setMinimumSize(30,100);
    }
    else if (p == 3)    //��������ť��ԭ
    {
        lghButton->setStyleSheet("QPushButton{border-image:url(:/img//img/light.jpg);}");
        lghButton->setMinimumSize(30,100);
    }
    else if (p == 4)    //������ť��ԭ
    {
        eviButton->setStyleSheet("QPushButton{border-image:url(:/img//img/atmosphere.jpg);}");
        eviButton->setMinimumSize(30,100);
    }

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

void Dialog::readMyCom(){
    QByteArray temp = serial->myCom->readAll();
    QString s(temp);
    if (s == "m"){
        qDebug() << "ok";
    }
}





