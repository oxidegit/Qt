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

//保存qt端接收到的参数
struct QtReceivePara
{
    int selectBit;//选择位
    int value;//值

    /*
    int lightState;//灯的状态
    int temperature;//温度
    int humidity;//湿度
    int selectedPat;//所选模式
    int tvState;//电视状态
    int audioState;//音响状态
    */

    //模式对应参数
    int modifiedMode;//所修改的模式
    int audioPara;//音响参数
    int doorPara;//门参数
    int temperPara;//温度参数
    int humidityPara;//湿度参数
};


//环境2 照明0 模式1 设备4(电视音响) 修改模式参数5
//模式1 2 3 4
//温度1 湿度2 门3 窗4

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
