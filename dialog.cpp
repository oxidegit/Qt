#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{

    this->setFixedSize(900,600);

    curPat = "生活";

    QDateTime current_date_time = QDateTime::currentDateTime();
    QString current_date = current_date_time.toString("yyyy.MM.dd hh:mm ddd");

    //QString patStr = data.getPattern();

    patShowLab = new QLabel(curPat+"模式",this);
    timShowLab = new QLabel(current_date,this);

    QHBoxLayout *topLayout = new QHBoxLayout(); // 上面的label
    topLayout->addWidget(patShowLab);   // 模式。
    topLayout->addWidget(timShowLab);   // 时间
    //patShowLab->show();
    topLayout->setMargin(0);
    topLayout->setSpacing(0);

    mainShowLab = new QLabel("这里放的是主界面里还没想好到底放啥的东西你说到底放点什么呢放一个logo是不是有点空但是不当logo还不知道放什么哎到底放什么呢好纠结呀",this);
    QHBoxLayout *midLayout = new QHBoxLayout();
    midLayout->addWidget(mainShowLab);

    patButton = new QPushButton(this);
    equButton = new QPushButton("设备",this);
    lghButton = new QPushButton("照明",this);
    eviButton = new QPushButton("环境",this);

    patButton->setMinimumSize(40,100);

    patButton->setStyleSheet("QPushButton{border-image:url(:/img//img/model.jpg);}");

    QHBoxLayout *bomLayout = new QHBoxLayout(); // 下面的导航栏
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

    /***************************************绑定******************************/
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
        curPat = "安全";
        this->patShowLab->setText("安全模式");
    }
    else if (mode == 1)
    {
        curPat = "睡眠";
        this->patShowLab->setText("睡眠模式");
    }
    else if (mode == 2)
    {
        curPat = "离家";
        this->patShowLab->setText("离家模式");
    }
    else if (mode == 3)
    {
        curPat = "生活";
        this->patShowLab->setText("生活模式");
    }
    //qDebug() << "接收成功";
}






