#ifndef SERIALCOMMUNICATION_H
#define SERIALCOMMUNICATION_H

#include <QString>
#include "win_qextserialport.h"

enum Light{
    KICHEN,
    BEDROOM,
    DRAWINGROOM,
    BATHROOM
};

enum Equip{
    TV,
    AUDIO
};

enum EnvirPara{
    TEMPERATUREP_PLUS,
    TEMPERATUREP_SUB,
    HUMIDITY_PLUS,
    HUMIDITY_SUB
};

enum Mode{
    SAFE,
    SLEEP,
    OUTSIDE,
    LIFE
};

//����qt�˽��յ��Ĳ���
struct QtReceivePara
{
    int selectBit;//ѡ��λ
    int value;//ֵ

    /*
    int lightState;//�Ƶ�״̬
    int temperature;//�¶�
    int humidity;//ʪ��
    int selectedPat;//��ѡģʽ
    int tvState;//����״̬
    int audioState;//����״̬
    */

    //ģʽ��Ӧ����
    int modifiedMode;//���޸ĵ�ģʽ
    int audioPara;//�������
    int doorPara;//�Ų���
    int temperPara;//�¶Ȳ���
    int humidityPara;//ʪ�Ȳ���
};


//����2 ����0 ģʽ1 �豸4(��������) �޸�ģʽ����5
//ģʽ1 2 3 4
//�¶�1 ʪ��2 ��3 ��4

class SerialCommunication
{
public:
    SerialCommunication();

public:
    char qtToArm(QString signal);
    QString armToQt(QString signal);
    bool qtUpdateLightState(Light light);
    bool qtUpdatePatternState(Mode selectedPat);
    bool qtUpdateEquipState(Equip device);
    bool qtUpdateEnvirState(EnvirPara envirPara);
    //static bool qtUpdateModePara(Mode selectedPat, int temperature, int humidity, State doorState, State windowState);
    bool qtSend(QString signal);
    bool openCom();
    bool closeCom();

    Win_QextSerialPort *myCom;
private:



    //QString qtReceive(int & state, QtReceivePara & para);
    //bool isComOpen();
};

#endif // SERIALCOMMUNICATION_H
