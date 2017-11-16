#include <QCoreApplication>
#include "basegraphic.h"
#include<iostream>
int main(int argc, char *argv[])
{
    //QCoreApplication a(argc, argv);


    Arrow rect;
    BaseGraphic *p=&rect;
    p->setState(Graphic::IN);
    p->setType(Graphic::Handle);
    p->AppendPoint(QPoint(100,1000));
    p->AppendPoint(QPoint(345,2000));
    p->AppendPoint(QPoint(300,46));
    p->AppendPoint(QPoint(4000,4000));
    p->show(std::cout);

    std::cout<<"point number: "<<p->Pointcount();

    return 0;
    //return a.exec();
}
