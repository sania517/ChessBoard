#ifndef XOD_H
#define XOD_H
//#include "controller.h"
#include "koordinaty_xoda.h"
#include "controller.h"



class Xod
{
public:

    Xod(Controller &contr);
    void readXod();
    //void setBoard( );

private:
Controller & m_contr;

};

#endif // XOD_H
