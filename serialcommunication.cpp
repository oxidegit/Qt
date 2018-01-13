#include "serialcommunication.h"
#include <QDebug>


SerialCommunication::SerialCommunication()
{
    myCom = new Win_QextSerialPort("com7",QextSerialBase::EventDriven);

    this->openCom();
    myCom->setBaudRate(BAUD115200);
    myCom->setDataBits(DATA_8);
    myCom->setParity(PAR_NONE);
    myCom->setStopBits(STOP_1);
    myCom->setFlowControl(FLOW_OFF);
    myCom->setTimeout(500); //设置延时
    //信号和槽函数关联，当串口缓冲区有数据时，进行读串口操作
    //connect(myCom,SIGNAL(readyRead()),this,SLOT(qtReceive()));
}

bool SerialCommunication::qtSend(QString signal)
{
    char c = qtToArm(signal);

    //定义一个结构体，用来存放串口各个参数
    //Win_QextSerialPort myCom("com7",QextSerialBase::EventDriven);
    //定义串口对象，并传递参数，在构造函数里对其进行初始化

    myCom->write(&c);
    //qDebug() << "send成功\n" ;
    qDebug() << qtToArm(signal);
    //closeCom();

    /*
    if (myCom->write(&c);]){//以可读写方式打开串口


        myCom->write(&c);
        qDebug() << "send成功\n" ;
        qDebug() << qtToArm(signal);
        closeCom();

        return true;

    }else{
        qDebug() << c;
        qDebug() << "send失败\n" ;
        return false;
    }*/

}
/*
QString SerialCommunication::qtReceive(int & state, QtReceivePara & para)
{
    QByteArray temp = myCom->readAll();
    //读取串口缓冲区的所有数据给临时变量temp
    //ui->textBrowser->insertPlainText(temp);
    //将串口的数据显示在窗口的文本浏览器中

    QString signal(temp);

    qDebug() << "state bit:" << signal[0];


    //环境1 照明2 模式3 设备4(电视音响) 修改模式参数5
    //模式1 2 3 4
    //温度1 湿度2 门3 窗4
    state = signal[0].toAscii() - '0';//提取状态位
    para.selectBit = signal[1].toAscii() - '0';//提取选择位
    int length = signal.length();

    if (state == 1){//提取环境模块参数
        para.value = signal.mid(2, length-2).toInt();//提取温度或者湿度

    }else if (state == 2 || state == 4){//提取 照明 和 设备 模块参数
        para.value = signal[2].toAscii() - '0'; //开或者关状态

    }else if (state == 5){//提取修改模块参数
        //signal.mid(1, );
    }



    return QString(temp);
}
*/
bool SerialCommunication::openCom()
{
    if (myCom->open(QIODevice::ReadWrite)){//以可读写方式打开串口
        return true;
    }else {
        return false;
    }


}

bool SerialCommunication::closeCom()
{
    myCom->close();
}

bool SerialCommunication::qtUpdateLightState(Light light)
{
    QString signal;
    signal.append("0");

    if (light == KICHEN){
        signal.append("0");
    }else if(light == BEDROOM){
        signal.append("1");
    }else if (light == DRAWINGROOM){
        signal.append("2");
    }else if (light == BATHROOM){
        signal.append("3");
    }
    /*
    if (lightSta ==OPEN){
        signal.append("1");
    }else{
        signal.append("0");
    }*/

    SerialCommunication::qtSend(signal);
}

bool SerialCommunication::qtUpdateEnvirState(EnvirPara envirPara)
{

    QString signal;

    signal.append("2");

    if (envirPara == TEMPERATUREP_PLUS){
        signal.append("0");
    }else if(envirPara == TEMPERATUREP_SUB){
        signal.append("1");
    }else if (envirPara == HUMIDITY_PLUS){
        signal.append("2");
    }else if (envirPara == HUMIDITY_SUB){
        signal.append("3");
    }

    qtSend(signal);

}

bool SerialCommunication::qtUpdatePatternState(Mode mode)
{
    QString signal;
    signal.append("1");

    if (mode == SAFE){
        signal.append("0");
    }else if(mode == OUTSIDE){
        signal.append("1");
    }else if (mode == LIFE){
        signal.append("2");
    }else if (mode == SLEEP){
        signal.append("3");
    }

    qtSend(signal);

}

bool SerialCommunication::qtUpdateEquipState(Equip equipment)
{
    QString signal;
    signal.append("3");

    if (equipment == TV){
        signal.append("0");
    }else if (equipment == AUDIO){
        signal.append("1");
    }

    /*
    if (state == OPEN){
        signal.append("1");
    }else if(state == CLOSE){
        signal.append("0");
    }*/
    qtSend(signal);
}

/*bool SerialCommunication::qtUpdateModePara(Mode selectedPat, int temperature, int humidity, State doorState, State windowState)
{

    QString signal;
    signal.append("5");
    //SAFE,
    //SLEEP,
    //OUTSIDE,
    //HOME
    if (selectedPat == SAFE){
        signal.append("1");
    }else if(selectedPat == SLEEP){
        signal.append("2");
    }else if(selectedPat == OUTSIDE){
        signal.append("3");
    }else if(selectedPat == LIFE){
        signal.append("4");
    }

    if (doorState == OPEN){
        signal.append("1");
    }else if (doorState == OPEN){
        signal.append("0");
    }

    if (windowState == OPEN){
        signal.append("1");
    }else if (windowState == OPEN){
        signal.append("0");
    }

    signal.append(QString::number(temperature));
    signal.append(",");
    signal.append(QString::number(humidity));

    qtSend(signal);
}
*/
char SerialCommunication::qtToArm(QString signal)
{
    int res = (signal[0].toAscii() - '0') * 4 + (signal[1].toAscii() - '0');

    res += 97;

    return res;
}
