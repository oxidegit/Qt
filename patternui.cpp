#include "patternui.h"
#include "ui_patternui.h"
#include "serialcommunication.h"

patternUI::patternUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::patternUI)
{
    //serial = new SerialCommunication();

    //QString curPat = getCurPattern();
    aqPatButton = new QPushButton("安全模式",this);
    smPatButton = new QPushButton("睡眠模式",this);
    ljPatButton = new QPushButton("离家模式",this);
    shPatButton = new QPushButton("生活模式",this);

    QLabel *temLabel = new QLabel("温度",this);
    QLabel *humLabel = new QLabel("湿度",this);
    QLabel *dlackLabel = new QLabel("门锁",this);
    QLabel *wlackLabel = new QLabel("窗锁",this);


    temAddBut = new QPushButton("+",this);
    temSelBut = new QPushButton("-",this);
    humAddBut = new QPushButton("+",this);
    humSelBut = new QPushButton("-",this);

    chooseBut = new QPushButton("选择",this);
    setvalBut = new QPushButton("设置",this);
    okkkkkBut = new QPushButton("确认",this);
    cancelBut = new QPushButton("取消",this);

    temLineEdit = new QLineEdit(this);
    humLineEdit = new QLineEdit(this);
    temLineEdit->setEnabled(false);
    humLineEdit->setEnabled(false);   // 不可更改

    temLineEdit->setFixedWidth(100);
    humLineEdit->setFixedWidth(100);

    doorlack = new QLabel(this);
    windowlack = new QLabel(this);


    QVBoxLayout *liftLayout = new QVBoxLayout;
    liftLayout->addWidget(aqPatButton);
    liftLayout->addWidget(smPatButton);
    liftLayout->addWidget(ljPatButton);
    liftLayout->addWidget(shPatButton);



    QGridLayout *rightLayout = new QGridLayout;

    // 选项                      行，列， 占x行x列
    rightLayout->addWidget(temLabel,0,0,1,1);
    rightLayout->addWidget(humLabel,1,0,1,1);
    rightLayout->addWidget(dlackLabel,2,0,1,1);
    rightLayout->addWidget(wlackLabel,3,0,1,1);

    // 温度按钮
    rightLayout->addWidget(temAddBut,0,2,1,1);
    rightLayout->addWidget(temLineEdit,0,3,1,1);
    rightLayout->addWidget(temSelBut,0,4,1,1);

    //湿度按钮
    rightLayout->addWidget(humAddBut,1,2,1,1);
    rightLayout->addWidget(humLineEdit,1,3,1,1);
    rightLayout->addWidget(humSelBut,1,4,1,1);

    //门窗锁
    rightLayout->addWidget(doorlack,2,3,1,1);
    rightLayout->addWidget(windowlack,3,3,1,1);

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
    rightLayout->setContentsMargins(20, 40, 20, 20);

    // 列比   第0列与第1列之比为 1:2
   // rightLayout-> setColumnStretch(0, 1);
   // rightLayout-> setColumnStretch(1, 2);
    // 行比   第0行与第1行之比为1:1
   // rightLayout-> setRowStretch(0, 1);
   // rightLayout-> setRowStretch(1, 1);

    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addLayout(liftLayout);
    mainLayout->addLayout(rightLayout);

    this->setLayout(mainLayout);

    connect(aqPatButton,SIGNAL(clicked()),this,SLOT(aqPatButtonSlot()));
    connect(smPatButton,SIGNAL(clicked()),this,SLOT(smPatButtonSlot()));
    connect(ljPatButton,SIGNAL(clicked()),this,SLOT(ljPatButtonSlot()));
    connect(shPatButton,SIGNAL(clicked()),this,SLOT(shPatButtonSlot()));
    connect(chooseBut,SIGNAL(clicked()),this,SLOT(chooseButSlot()));
    connect(setvalBut,SIGNAL(clicked()),this,SLOT(setvalButSlot()));
    connect(cancelBut,SIGNAL(clicked()),this,SLOT(cancelButSlot()));
    connect(okkkkkBut,SIGNAL(clicked()),this,SLOT(okkkkkButSlot()));


    ui->setupUi(this);
}

patternUI::~patternUI()
{
    delete ui;
}

//  刷新模式参数和按钮选中显示
void patternUI::aqPatButtonSlot()
{
    pchoose = 0;
    refValue(pchoose);
}

void patternUI::smPatButtonSlot()
{
    pchoose = 1;
    refValue(pchoose);
}

void patternUI::ljPatButtonSlot()
{
    pchoose = 2;
    refValue(pchoose);
}

void patternUI::shPatButtonSlot()
{
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
    pattern[pchoose].p_Wins = val2;


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
}

void patternUI::setPattern(QString p)  // 进入模式界面初始化
{
    pName = p;
    int temp;

    // 默认按钮选中
    if (pName == "安全")
    {
       temp = 0;
    }
    else if(pName == "睡眠")
    {
       temp = 1;
    }
    else if(pName == "离家")
    {
       temp = 2;
    }
    else if(pName == "生活")
    {
       temp = 3;
    }

    temLineEdit->setText(QString::number(pattern[temp].p_Temp, 10));
    humLineEdit->setText(QString::number(pattern[temp].p_Humid, 10));
    doorlack->setText(pattern[temp].p_Door);
    windowlack->setText(pattern[temp].p_Wins);

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
