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
    myCom->setTimeout(500); //������ʱ
    //�źźͲۺ��������������ڻ�����������ʱ�����ж����ڲ���
    //connect(myCom,SIGNAL(readyRead()),this,SLOT(qtReceive()));
}

bool SerialCommunication::qtSend(QString signal)
{
    char c = qtToArm(signal);

    //����һ���ṹ�壬������Ŵ��ڸ�������
    //Win_QextSerialPort myCom("com7",QextSerialBase::EventDriven);
    //���崮�ڶ��󣬲����ݲ������ڹ��캯���������г�ʼ��

    myCom->write(&c);
    //qDebug() << "send�ɹ�\n" ;
    qDebug() << qtToArm(signal);
    //closeCom();

    /*
    if (myCom->write(&c);]){//�Կɶ�д��ʽ�򿪴���


        myCom->write(&c);
        qDebug() << "send�ɹ�\n" ;
        qDebug() << qtToArm(signal);
        closeCom();

        return true;

    }else{
        qDebug() << c;
        qDebug() << "sendʧ��\n" ;
        return false;
    }*/

}
/*
QString SerialCommunication::qtReceive(int & state, QtReceivePara & para)
{
    QByteArray temp = myCom->readAll();
    //��ȡ���ڻ��������������ݸ���ʱ����temp
    //ui->textBrowser->insertPlainText(temp);
    //�����ڵ�������ʾ�ڴ��ڵ��ı��������

    QString signal(temp);

    qDebug() << "state bit:" << signal[0];


    //����1 ����2 ģʽ3 �豸4(��������) �޸�ģʽ����5
    //ģʽ1 2 3 4
    //�¶�1 ʪ��2 ��3 ��4
    state = signal[0].toAscii() - '0';//��ȡ״̬λ
    para.selectBit = signal[1].toAscii() - '0';//��ȡѡ��λ
    int length = signal.length();

    if (state == 1){//��ȡ����ģ�����
        para.value = signal.mid(2, length-2).toInt();//��ȡ�¶Ȼ���ʪ��

    }else if (state == 2 || state == 4){//��ȡ ���� �� �豸 ģ�����
        para.value = signal[2].toAscii() - '0'; //�����߹�״̬

    }else if (state == 5){//��ȡ�޸�ģ�����
        //signal.mid(1, );
    }



    return QString(temp);
}
*/
bool SerialCommunication::openCom()
{
    if (myCom->open(QIODevice::ReadWrite)){//�Կɶ�д��ʽ�򿪴���
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
