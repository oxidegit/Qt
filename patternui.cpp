#include "patternui.h"
#include "ui_patternui.h"
#include "serialcommunication.h"

patternUI::patternUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::patternUI)
{
    //serial = new SerialCommunication();

    //QString curPat = getCurPattern();
    aqPatButton = new QPushButton("��ȫģʽ",this);
    smPatButton = new QPushButton("˯��ģʽ",this);
    ljPatButton = new QPushButton("���ģʽ",this);
    shPatButton = new QPushButton("����ģʽ",this);

    QLabel *temLabel = new QLabel("�¶�",this);
    QLabel *humLabel = new QLabel("ʪ��",this);
    QLabel *dlackLabel = new QLabel("����",this);
    QLabel *wlackLabel = new QLabel("����",this);


    temAddBut = new QPushButton("+",this);
    temSelBut = new QPushButton("-",this);
    humAddBut = new QPushButton("+",this);
    humSelBut = new QPushButton("-",this);

    chooseBut = new QPushButton("ѡ��",this);
    setvalBut = new QPushButton("����",this);
    okkkkkBut = new QPushButton("ȷ��",this);
    cancelBut = new QPushButton("ȡ��",this);

    temLineEdit = new QLineEdit(this);
    humLineEdit = new QLineEdit(this);
    temLineEdit->setEnabled(false);
    humLineEdit->setEnabled(false);   // ���ɸ���

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

    // ѡ��                      �У��У� ռx��x��
    rightLayout->addWidget(temLabel,0,0,1,1);
    rightLayout->addWidget(humLabel,1,0,1,1);
    rightLayout->addWidget(dlackLabel,2,0,1,1);
    rightLayout->addWidget(wlackLabel,3,0,1,1);

    // �¶Ȱ�ť
    rightLayout->addWidget(temAddBut,0,2,1,1);
    rightLayout->addWidget(temLineEdit,0,3,1,1);
    rightLayout->addWidget(temSelBut,0,4,1,1);

    //ʪ�Ȱ�ť
    rightLayout->addWidget(humAddBut,1,2,1,1);
    rightLayout->addWidget(humLineEdit,1,3,1,1);
    rightLayout->addWidget(humSelBut,1,4,1,1);

    //�Ŵ���
    rightLayout->addWidget(doorlack,2,3,1,1);
    rightLayout->addWidget(windowlack,3,3,1,1);

    // �ĸ���ť
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


    // ����ˮƽ���
    rightLayout->setHorizontalSpacing(10);
    // ���ô�ֱ���
    rightLayout->setVerticalSpacing(10);
    // ��������
    rightLayout->setContentsMargins(20, 40, 20, 20);

    // �б�   ��0�����1��֮��Ϊ 1:2
   // rightLayout-> setColumnStretch(0, 1);
   // rightLayout-> setColumnStretch(1, 2);
    // �б�   ��0�����1��֮��Ϊ1:1
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

//  ˢ��ģʽ�����Ͱ�ťѡ����ʾ
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


void patternUI::chooseButSlot()   // ���Ľ���ģʽ��ʾ
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

void patternUI::setvalButSlot()  //  ģʽ���Ĳ���
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

void patternUI::okkkkkButSlot()   // ���Ľ���ģʽ��ʾ
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

void patternUI::refValue(int p)   // ����ģʽ����ˢ��
{

    temLineEdit->setText(QString::number(pattern[p].p_Temp, 10));
    humLineEdit->setText(QString::number(pattern[p].p_Humid, 10));
    doorlack->setText(pattern[p].p_Door);
    windowlack->setText(pattern[p].p_Wins);
}

void patternUI::setPattern(QString p)  // ����ģʽ�����ʼ��
{
    pName = p;
    int temp;

    // Ĭ�ϰ�ťѡ��
    if (pName == "��ȫ")
    {
       temp = 0;
    }
    else if(pName == "˯��")
    {
       temp = 1;
    }
    else if(pName == "���")
    {
       temp = 2;
    }
    else if(pName == "����")
    {
       temp = 3;
    }

    temLineEdit->setText(QString::number(pattern[temp].p_Temp, 10));
    humLineEdit->setText(QString::number(pattern[temp].p_Humid, 10));
    doorlack->setText(pattern[temp].p_Door);
    windowlack->setText(pattern[temp].p_Wins);

}


void patternUI::setValue()    // ģʽ������ʼ��
{
    pattern[0].p_Name = "��ȫ";
    pattern[0].p_Door = "����";
    pattern[0].p_Humid = 60;
    pattern[0].p_Temp = 24;
    pattern[0].p_Wins = "����";

    pattern[1].p_Name = "˯��";
    pattern[1].p_Door = "����";
    pattern[1].p_Humid = 65;
    pattern[1].p_Temp = 25;
    pattern[1].p_Wins = "����";

    pattern[2].p_Name = "���";
    pattern[2].p_Door = "����";
    pattern[2].p_Humid = 50;
    pattern[2].p_Temp = 20;
    pattern[2].p_Wins = "����";

    pattern[3].p_Name = "����";
    pattern[3].p_Door = "δ��";
    pattern[3].p_Humid = 60;
    pattern[3].p_Temp = 23;
    pattern[3].p_Wins = "δ��";

}
