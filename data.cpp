#include "data.h"

Data::Data()
{
    m_ncurPat = "Éú»î";
    m_ncurTemp = 23;
    m_ncurHumid = 60;
    m_ncurDoor = 1;
    m_ncurWins = 1;
    m_ncurTV = 0;
    m_ncurJBL = 0;


    m_ncurLight[0] = 0;
    m_ncurLight[1] = 0;
    m_ncurLight[2] = 0;
    m_ncurLight[3] = 0;

}

QString Data::getPattern()
{
    return m_ncurPat;
}

void Data::setPattern()
{

}
