#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{

    this->setFixedSize(900,700);

    curPat = "生活";
    curButton = 0;
    prveButton = 0;

    QDateTime current_date_time = QDateTime::currentDateTime();
    QString current_date = current_date_time.toString("yyyy.MM.dd hh:mm ddd");

    //QString patStr = data.getPattern();

    patShowLab = new QLabel(curPat+"模式",this);
    timShowLab = new QLabel(current_date,this);

    QPalette pe;
    pe.setColor(QPalette::WindowText,Qt::white);
    patShowLab->setPalette(pe);
    timShowLab->setPalette(pe);

    QFont ft("STHupo", 24, 20);
    //ft.setPointSize(18);
    patShowLab->setFont(ft);
    timShowLab->setFont(ft);

    QHBoxLayout *topLayout = new QHBoxLayout(); // 上面的label
    topLayout->addWidget(patShowLab);   // 模式。
    topLayout->addWidget(timShowLab);   // 时间
    topLayout->setMargin(0);
    topLayout->setSpacing(0);

    mainShowLab = new QLabel("既然你诚心诚意的发问了!\n我们就大发慈悲的告诉你！\n为了防止世界被破坏!\n为了守护世界的和平!\n贯彻爱与真实的邪恶!\n可爱又迷人的反派角色!\n武藏！ 小次郎！\n我们是穿梭在银河的火箭队！\n白洞，白色的明天在等着我们！\n就是这样!喵!",this);
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

    QHBoxLayout *bomLayout = new QHBoxLayout(); // 下面的导航栏
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
    if (c == 1)    // 模式按钮按下
    {
        patButton->setStyleSheet("QPushButton{border-image:url(:/img//img/model_p.jpg);}");
        patButton->setMinimumSize(30,120);

    }
    else if (c == 2)    // 设备按钮按下
    {
        equButton->setStyleSheet("QPushButton{border-image:url(:/img//img/equipment_p.jpg);}");
        equButton->setMinimumSize(30,120);
    }
    else if (c == 3)    //照明按钮按下
    {
        lghButton->setStyleSheet("QPushButton{border-image:url(:/img//img/light_p.jpg);}");
        lghButton->setMinimumSize(30,120);
    }
    else if (c == 4)    //环境按钮按下
    {
        eviButton->setStyleSheet("QPushButton{border-image:url(:/img//img/atmosphere_p.jpg);}");
        eviButton->setMinimumSize(30,120);
    }

    ///////////////////////////////////////////////////////////////


    if (p == 1)    //模式按钮复原
    {
        patButton->setStyleSheet("QPushButton{border-image:url(:/img//img/model.jpg);}");
        patButton->setMinimumSize(30,100);
    }
    else if (p == 2)    //设备按钮复原
    {
        equButton->setStyleSheet("QPushButton{border-image:url(:/img//img/equipment.jpg);}");
        equButton->setMinimumSize(30,100);
    }
    else if (p == 3)    //环照明按钮复原
    {
        lghButton->setStyleSheet("QPushButton{border-image:url(:/img//img/light.jpg);}");
        lghButton->setMinimumSize(30,100);
    }
    else if (p == 4)    //环境按钮复原
    {
        eviButton->setStyleSheet("QPushButton{border-image:url(:/img//img/atmosphere.jpg);}");
        eviButton->setMinimumSize(30,100);
    }

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






