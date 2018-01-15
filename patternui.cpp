#include "patternui.h"
#include "ui_patternui.h"

patternUI::patternUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::patternUI)
{
    curButton = 0;
    prveButton = 0;

    aqPatButton = new QPushButton(this);
    smPatButton = new QPushButton(this);
    ljPatButton = new QPushButton(this);
    shPatButton = new QPushButton(this);

    aqPatButton->setMinimumSize(50,90);
    smPatButton->setMinimumSize(50,90);
    ljPatButton->setMinimumSize(50,90);
    shPatButton->setMinimumSize(50,90);

    aqPatButton->setStyleSheet("QPushButton{border-image:url(:/img//img/safe.png);}");
    smPatButton->setStyleSheet("QPushButton{border-image:url(:/img//img/sleep.png);}");
    ljPatButton->setStyleSheet("QPushButton{border-image:url(:/img//img/leave.png);}");
    shPatButton->setStyleSheet("QPushButton{border-image:url(:/img//img/life.png);}");

    QLabel *temLabel = new QLabel("温度",this);
    QLabel *humLabel = new QLabel("湿度",this);
    QLabel *dlackLabel = new QLabel("门锁",this);
    QLabel *wlackLabel = new QLabel("窗锁",this);

    QPalette pe;
    pe.setColor(QPalette::WindowText,Qt::white);
    temLabel->setPalette(pe);
    humLabel->setPalette(pe);
    dlackLabel->setPalette(pe);
    wlackLabel->setPalette(pe);

    QFont ft("STHupo", 24, 20);
    temLabel->setFont(ft);
    humLabel->setFont(ft);
    dlackLabel->setFont(ft);
    wlackLabel->setFont(ft);


    trianLabel_1 = new QLabel(this);
    trianLabel_1->setStyleSheet("QLabel{border-image:url(:/img//img/flank-1.png);}");
    trianLabel_2 = new QLabel(this);
    trianLabel_2->setStyleSheet("QLabel{border-image:url(:/img//img/flank-2.png);}");
    trianLabel_3 = new QLabel(this);
    trianLabel_3->setStyleSheet("QLabel{border-image:url(:/img//img/flank-3.png);}");
    trianLabel_4 = new QLabel(this);
    trianLabel_4->setStyleSheet("QLabel{border-image:url(:/img//img/flank-4.png);}");

                             // x,y,w,h
    trianLabel_1->setGeometry(200,5,50,480);
    trianLabel_2->setGeometry(200,5,50,480);
    trianLabel_3->setGeometry(200,5,50,480);
    trianLabel_4->setGeometry(200,5,50,480);

    trianLabel_1->hide();
    trianLabel_2->hide();
    trianLabel_3->hide();
    trianLabel_4->hide();

    temAddBut = new QPushButton("+",this);
    temSelBut = new QPushButton("-",this);
    humAddBut = new QPushButton("+",this);
    humSelBut = new QPushButton("-",this);

    temAddBut->setFlat(true);
    temSelBut->setFlat(true);
    humAddBut->setFlat(true);
    humSelBut->setFlat(true);

    chooseBut = new QPushButton("选择",this);
    setvalBut = new QPushButton("设置",this);
    okkkkkBut = new QPushButton("确认",this);
    cancelBut = new QPushButton("取消",this);

    temAddBut->setPalette(pe);
    temSelBut->setPalette(pe);
    humAddBut->setPalette(pe);
    humSelBut->setPalette(pe);
    temAddBut->setFont(ft);
    temSelBut->setFont(ft);
    humAddBut->setFont(ft);
    humSelBut->setFont(ft);

    chooseBut->setPalette(pe);
    setvalBut->setPalette(pe);
    okkkkkBut->setPalette(pe);
    cancelBut->setPalette(pe);
    chooseBut->setFont(ft);
    setvalBut->setFont(ft);
    okkkkkBut->setFont(ft);
    cancelBut->setFont(ft);

    chooseBut->setFlat(true);
    setvalBut->setFlat(true);
    okkkkkBut->setFlat(true);
    cancelBut->setFlat(true);

    temLineEdit = new QLineEdit(this);
    humLineEdit = new QLineEdit(this);
    temLineEdit->setEnabled(false);
    humLineEdit->setEnabled(false);   // 不可更改

    temLineEdit->setPalette(pe);
    humLineEdit->setPalette(pe);
    temLineEdit->setFont(ft);
    humLineEdit->setFont(ft);

    temLineEdit->setFixedWidth(80);
    humLineEdit->setFixedWidth(80);

    doorlack = new QLabel(this);
    windowlack = new QLabel(this);

    doorlack->setPalette(pe);
    windowlack->setPalette(pe);

    doorlack->setFont(ft);
    windowlack->setFont(ft);



    QVBoxLayout *liftLayout = new QVBoxLayout;
    liftLayout->addWidget(aqPatButton);
    liftLayout->addWidget(smPatButton);
    liftLayout->addWidget(ljPatButton);
    liftLayout->addWidget(shPatButton);

    liftLayout->setContentsMargins(30,10,0,0);
    liftLayout->setSpacing(30);


    QGridLayout *rightLayout = new QGridLayout;

    // 选项                      行，列， 占x行x列
    rightLayout->addWidget(temLabel,0,0,1,1);
    rightLayout->addWidget(humLabel,1,0,1,1);
    rightLayout->addWidget(dlackLabel,2,0,1,1);
    rightLayout->addWidget(wlackLabel,3,0,1,1);

    // 温度按钮
    rightLayout->addWidget(temAddBut,0,1,1,1);
    rightLayout->addWidget(temLineEdit,0,2,1,1);
    rightLayout->addWidget(temSelBut,0,3,1,1);

    //湿度按钮
    rightLayout->addWidget(humAddBut,1,1,1,1);
    rightLayout->addWidget(humLineEdit,1,2,1,1);
    rightLayout->addWidget(humSelBut,1,3,1,1);

    //门窗锁
    rightLayout->addWidget(doorlack,2,2,1,1);
    rightLayout->addWidget(windowlack,3,2,1,1);

    // 四个按钮
    rightLayout->addWidget(chooseBut,4,1,1,1);
    rightLayout->addWidget(setvalBut,4,3,1,1);
    rightLayout->addWidget(okkkkkBut,4,1,1,1);
    rightLayout->addWidget(cancelBut,4,3,1,1);

    okkkkkBut->hide();
    cancelBut->hide();
    temAddBut->hide();
    temSelBut->hide();
    humAddBut->hide();
    humSelBut->hide();


    // 设置水平间距
    rightLayout->setHorizontalSpacing(10);
    // 设置垂直间距
    rightLayout->setVerticalSpacing(10);
    // 设置外间距
    rightLayout->setContentsMargins(50, 40, 20, 20);

    // 列比   第0列与第1列之比为 1:2
   // rightLayout-> setColumnStretch(0, 1);
   // rightLayout-> setColumnStretch(1, 2);
    // 行比   第0行与第1行之比为1:1
   // rightLayout-> setRowStretch(0, 1);
   // rightLayout-> setRowStretch(1, 1);

    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addLayout(liftLayout);
    mainLayout->addLayout(rightLayout);

    mainLayout->setStretchFactor(liftLayout, 1);
    mainLayout->setStretchFactor(rightLayout, 4);


    this->setLayout(mainLayout);

    connect(aqPatButton,SIGNAL(clicked()),this,SLOT(aqPatButtonSlot()));
    connect(smPatButton,SIGNAL(clicked()),this,SLOT(smPatButtonSlot()));
    connect(ljPatButton,SIGNAL(clicked()),this,SLOT(ljPatButtonSlot()));
    connect(shPatButton,SIGNAL(clicked()),this,SLOT(shPatButtonSlot()));

    connect(chooseBut,SIGNAL(clicked()),this,SLOT(chooseButSlot()));
    connect(setvalBut,SIGNAL(clicked()),this,SLOT(setvalButSlot()));
    connect(cancelBut,SIGNAL(clicked()),this,SLOT(cancelButSlot()));
    connect(okkkkkBut,SIGNAL(clicked()),this,SLOT(okkkkkButSlot()));

    connect(temAddBut,SIGNAL(clicked()),this,SLOT(temAddButSlot()));
    connect(temSelBut,SIGNAL(clicked()),this,SLOT(temSelButSlot()));
    connect(humAddBut,SIGNAL(clicked()),this,SLOT(humAddButSlot()));
    connect(humSelBut,SIGNAL(clicked()),this,SLOT(humSelButSlot()));

    ui->setupUi(this);
}

patternUI::~patternUI()
{
    delete ui;
}

//  刷新模式参数和按钮选中显示
void patternUI::aqPatButtonSlot()
{
    curButton = 1;

    int p = getPrve();
    setPrve(curButton);

    setButtonImg(curButton,p);

    aqPatButton->setEnabled(false);
    smPatButton->setEnabled(true);
    ljPatButton->setEnabled(true);
    shPatButton->setEnabled(true);

    trianLabel_1->show();
    trianLabel_2->hide();
    trianLabel_3->hide();
    trianLabel_4->hide();

    pchoose = 0;
    refValue(pchoose);
}

void patternUI::smPatButtonSlot()
{
    curButton = 2;

    int p = getPrve();
    setPrve(curButton);

    setButtonImg(curButton,p);

    aqPatButton->setEnabled(true);
    smPatButton->setEnabled(false);
    ljPatButton->setEnabled(true);
    shPatButton->setEnabled(true);

    trianLabel_1->hide();
    trianLabel_2->show();
    trianLabel_3->hide();
    trianLabel_4->hide();

    pchoose = 1;
    refValue(pchoose);
}

void patternUI::ljPatButtonSlot()
{
    curButton = 3;

    int p = getPrve();
    setPrve(curButton);

    setButtonImg(curButton,p);

    aqPatButton->setEnabled(true);
    smPatButton->setEnabled(true);
    ljPatButton->setEnabled(false);
    shPatButton->setEnabled(true);

    trianLabel_1->hide();
    trianLabel_2->hide();
    trianLabel_3->show();
    trianLabel_4->hide();

    pchoose = 2;
    refValue(pchoose);
}

void patternUI::shPatButtonSlot()
{
    curButton = 4;

    int p = getPrve();
    setPrve(curButton);

    setButtonImg(curButton,p);

    aqPatButton->setEnabled(true);
    smPatButton->setEnabled(true);
    ljPatButton->setEnabled(true);
    shPatButton->setEnabled(false);

    trianLabel_1->hide();
    trianLabel_2->hide();
    trianLabel_3->hide();
    trianLabel_4->show();

    pchoose = 3;
    refValue(pchoose);

}


void patternUI::chooseButSlot()   // 更改界面模式显示
{
    if (pchoose == 0){
        serial->qtUpdatePatternState(SAFE);
    }else if (pchoose == 1){
        serial->qtUpdatePatternState(SLEEP);
    }else if (pchoose == 2){
        serial->qtUpdatePatternState(OUTSIDE);
    }else if (pchoose == 3){
        serial->qtUpdatePatternState(LIFE);
    }

    emit signalP(pchoose);

    emit signalT(pattern[pchoose].p_Temp);
    emit signalH(pattern[pchoose].p_Humid);


    pTemp = pattern[pchoose].p_Temp;
    pHumid = pattern[pchoose].p_Humid;
}

void patternUI::setvalButSlot()  //  模式更改参数
{
    okkkkkBut->show();
    cancelBut->show();
    chooseBut->hide();
    setvalBut->hide();

    temAddBut->show();
    temSelBut->show();
    humAddBut->show();
    humSelBut->show();

    temLineEdit->setEnabled(true);
    humLineEdit->setEnabled(true);

    aqPatButton->setEnabled(false);
    smPatButton->setEnabled(false);
    ljPatButton->setEnabled(false);
    shPatButton->setEnabled(false);

}

void patternUI::okkkkkButSlot()   // 更改界面模式显示
{    
    QString str1 = temLineEdit->text();
    QString str2 = humLineEdit->text();

    int val1 = str1.toInt();
    int val2 = str2.toInt();

    pattern[pchoose].p_Temp = val1;
    pattern[pchoose].p_Humid = val2;


    aqPatButton->setEnabled(true);
    smPatButton->setEnabled(true);
    ljPatButton->setEnabled(true);
    shPatButton->setEnabled(true);

    okkkkkBut->hide();
    cancelBut->hide();
    chooseBut->show();
    setvalBut->show();

    temAddBut->hide();
    temSelBut->hide();
    humAddBut->hide();
    humSelBut->hide();

    temLineEdit->setEnabled(false);
    humLineEdit->setEnabled(false);

    aqPatButton->setEnabled(true);
    smPatButton->setEnabled(true);
    ljPatButton->setEnabled(true);
    shPatButton->setEnabled(true);

    refValue(pchoose);

}

void patternUI::cancelButSlot()
{
    okkkkkBut->hide();
    cancelBut->hide();
    chooseBut->show();
    setvalBut->show();

    temAddBut->hide();
    temSelBut->hide();
    humAddBut->hide();
    humSelBut->hide();

    temLineEdit->setEnabled(false);
    humLineEdit->setEnabled(false);

    aqPatButton->setEnabled(true);
    smPatButton->setEnabled(true);
    ljPatButton->setEnabled(true);
    shPatButton->setEnabled(true);

    refValue(pchoose);
}


void patternUI::temAddButSlot()
{
    pTemp ++;
    if(pTemp < 10 || pTemp > 48)
    {
        pTemp--;
    }
    QString data1 = QString("%1").arg(pTemp);
    temLineEdit->setText(data1);
}


void patternUI::temSelButSlot()
{
    pTemp --;
    if(pTemp < 10 || pTemp > 48)
    {
        pTemp++;
    }
    QString data1 = QString("%1").arg(pTemp);
    temLineEdit->setText(data1);
}


void patternUI::humAddButSlot()
{
    pHumid++;

    if(pHumid < 8 || pHumid > 98)
    {
        pHumid--;
    }
    QString data1 = QString("%1").arg(pHumid);
    humLineEdit->setText(data1);
}


void patternUI::humSelButSlot()
{
    pHumid--;
    if(pHumid < 8 || pHumid > 98)
    {
        pHumid++;
    }
    QString data1 = QString("%1").arg(pHumid);
    humLineEdit->setText(data1);
}

int patternUI::getPrve()
{
    return prveButton;
}

void patternUI::setPrve(int c)
{
    prveButton = c;
}

void patternUI::setButtonImg(int c,int p)
{
    if (c == 1)    // 安全模式按钮按下
    {
        aqPatButton->setStyleSheet("QPushButton{border-image:url(:/img//img/safe_p.png);}");
        //aqPatButton->setMinimumSize(60,100);

    }
    else if (c == 2)    // 睡眠按钮按下
    {
        smPatButton->setStyleSheet("QPushButton{border-image:url(:/img//img/sleep_p.png);}");
        //smPatButton->setMinimumSize(30,120);
    }
    else if (c == 3)    //离家按钮按下
    {
        ljPatButton->setStyleSheet("QPushButton{border-image:url(:/img//img/leave_p.png);}");
        //ljPatButton->setMinimumSize(30,120);
    }
    else if (c == 4)    //生活按钮按下
    {
        shPatButton->setStyleSheet("QPushButton{border-image:url(:/img//img/life_p.png);}");
        //shPatButton->setMinimumSize(30,120);
    }

    ///////////////////////////////////////////////////////////////


    if (p == 1)    //安全模式按钮复原
    {
        aqPatButton->setStyleSheet("QPushButton{border-image:url(:/img//img/safe.png);}");
        //aqPatButton->setMinimumSize(30,100);
    }
    else if (p == 2)    //睡眠模式按钮复原
    {
        smPatButton->setStyleSheet("QPushButton{border-image:url(:/img//img/sleep.png);}");
        //smPatButton->setMinimumSize(30,100);
    }
    else if (p == 3)    //离家模式按钮复原
    {
        ljPatButton->setStyleSheet("QPushButton{border-image:url(:/img//img/leave.png);}");
        //ljPatButton->setMinimumSize(30,100);
    }
    else if (p == 4)    //生活模式按钮复原
    {
        shPatButton->setStyleSheet("QPushButton{border-image:url(:/img//img/life.png);}");
        //shPatButton->setMinimumSize(30,100);
    }

}

int patternUI::sendTem(int p)
{
    return pattern[p].p_Temp;
}

int patternUI::sendHum(int p)
{
    return pattern[p].p_Humid;
}

void patternUI::refValue(int p)   // 更改模式参数刷新
{

    temLineEdit->setText(QString::number(pattern[p].p_Temp, 10));
    humLineEdit->setText(QString::number(pattern[p].p_Humid, 10));
    doorlack->setText(pattern[p].p_Door);
    windowlack->setText(pattern[p].p_Wins);

    pTemp = pattern[p].p_Temp;
    pHumid = pattern[p].p_Humid;

}

void patternUI::setPattern(QString p)  // 进入模式界面初始化
{
    pName = p;
    int temp;

    // 默认按钮选中
    if (pName == "安全")
    {
       temp = 0;
       curButton = 1;

       int p = getPrve();
       setPrve(curButton);

       setButtonImg(curButton,p);

       aqPatButton->setEnabled(false);
       smPatButton->setEnabled(true);
       ljPatButton->setEnabled(true);
       shPatButton->setEnabled(true);

       trianLabel_1->show();
       trianLabel_2->hide();
       trianLabel_3->hide();
       trianLabel_4->hide();

       pchoose = 0;
       refValue(pchoose);
    }
    else if(pName == "睡眠")
    {
       temp = 1;

       curButton = 2;

       int p = getPrve();
       setPrve(curButton);

       setButtonImg(curButton,p);

       aqPatButton->setEnabled(true);
       smPatButton->setEnabled(false);
       ljPatButton->setEnabled(true);
       shPatButton->setEnabled(true);

       trianLabel_1->hide();
       trianLabel_2->show();
       trianLabel_3->hide();
       trianLabel_4->hide();

       pchoose = 1;
       refValue(pchoose);
    }
    else if(pName == "离家")
    {
       temp = 2;

       curButton = 3;

       int p = getPrve();
       setPrve(curButton);

       setButtonImg(curButton,p);

       aqPatButton->setEnabled(true);
       smPatButton->setEnabled(true);
       ljPatButton->setEnabled(false);
       shPatButton->setEnabled(true);

       trianLabel_1->hide();
       trianLabel_2->hide();
       trianLabel_3->show();
       trianLabel_4->hide();

       pchoose = 2;
       refValue(pchoose);

    }
    else if(pName == "生活")
    {
       temp = 3;

       curButton = 4;

       int p = getPrve();
       setPrve(curButton);

       setButtonImg(curButton,p);

       aqPatButton->setEnabled(true);
       smPatButton->setEnabled(true);
       ljPatButton->setEnabled(true);
       shPatButton->setEnabled(false);

       trianLabel_1->hide();
       trianLabel_2->hide();
       trianLabel_3->hide();
       trianLabel_4->show();

       pchoose = 3;
       refValue(pchoose);
    }

    temLineEdit->setText(QString::number(pattern[temp].p_Temp, 10));
    humLineEdit->setText(QString::number(pattern[temp].p_Humid, 10));
    doorlack->setText(pattern[temp].p_Door);
    windowlack->setText(pattern[temp].p_Wins);

    pTemp = pattern[temp].p_Temp;
    pHumid = pattern[temp].p_Humid;

}


void patternUI::setValue()    // 模式参数初始化
{
    pattern[0].p_Name = "安全";
    pattern[0].p_Door = "已锁";
    pattern[0].p_Humid = 60;
    pattern[0].p_Temp = 24;
    pattern[0].p_Wins = "已锁";

    pattern[1].p_Name = "睡眠";
    pattern[1].p_Door = "已锁";
    pattern[1].p_Humid = 65;
    pattern[1].p_Temp = 25;
    pattern[1].p_Wins = "已锁";

    pattern[2].p_Name = "离家";
    pattern[2].p_Door = "已锁";
    pattern[2].p_Humid = 50;
    pattern[2].p_Temp = 20;
    pattern[2].p_Wins = "已锁";

    pattern[3].p_Name = "生活";
    pattern[3].p_Door = "未锁";
    pattern[3].p_Humid = 60;
    pattern[3].p_Temp = 23;
    pattern[3].p_Wins = "未锁";

}
