#include <QCoreApplication>
#include "basegraphic.h"
#include<iostream>
int main(int argc, char *argv[])
{
    //QCoreApplication a(argc, argv);

    Rectangle *rect=new Rectangle;
    rect->setColor(Qt::red);
    rect->setState(Graphic::IN);
    rect->setType(Graphic::Handle);
    rect->AppendPoint(QPoint(100,1000));
    rect->AppendPoint(QPoint(345,2000));
    rect->AppendPoint(QPoint(300,46));
    rect->AppendPoint(QPoint(4000,4000));
    rect->show(std::cout);
    std::cout<<"point number: "<<rect->Pointcount();

    return 0;
    //return a.exec();
}
