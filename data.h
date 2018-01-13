#ifndef DATA_H
#define DATA_H

#include <QString>



class Data
{
public:
    Data();
    QString getPattern();
    void setPattern();

private:

    QString m_ncurPat;
    int m_ncurTemp;
    int m_ncurHumid;
    int m_ncurDoor;
    int m_ncurWins;
    int m_ncurTV;
    int m_ncurJBL;
    int m_ncurLight[4];
};

#endif // DATA_H
