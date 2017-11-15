#include "basegraphic.h"

void drawRectangle(QPainter *p,const QPoint& begin,const QPoint& end)
{

}

void drawRectangle(QPainter *p,const BaseGraphic& bg)
{
    int width=qAbs(bg.GetPoints().begin()->x()-(bg.GetPoints().end()-1)->x());
    int height=qAbs(bg.GetPoints().begin()->y()-(bg.GetPoints().end()-1)->y());
    p->drawRect(bg.GetPoints().begin()->x(),bg.GetPoints().begin()->y(),width,height);
}

void drawLine(QPainter *p,const QPoint& begin,const QPoint& end)
{
    p->drawLine(begin,end);
}

void drawPolygon(QPainter *p,const BaseGraphic& bg)
{

    for(auto i=bg.GetPoints().cbegin();i!=bg.GetPoints().cend();i++)
    {
        drawLine(p,*i,*(i+1));
    }
}

void drawArrow(QPainter *p,const QPoint& begin,const QPoint& end)
{

}

void drawArrow(QPainter *p,const BaseGraphic& bg)
{
        int x1 = bg.GetPoints().begin()->x();                                     //取points[0]起点的x
        int y1 = bg.GetPoints().begin()->y();                                     //取points[0]起点的y
        int x2 = bg.GetPoints().end()->x();                                       //取points[count-1]终点的x
        int y2 = bg.GetPoints().end()->y();                                       //取points[count-1]终点的y
        int l = 10.0;                                           //箭头的长度
        int a = 1;                                            //箭头与线段角度
        int x3 = x2 - l * cos(atan2((y2 - y1) , (x2 - x1)) - a);//计算箭头的终点（x3,y3）
        int y3 = y2 - l * sin(atan2((y2 - y1) , (x2 - x1)) - a);
        int x4 = x2 - l * sin(atan2((x2 - x1) , (y2 - y1)) - a);//计算箭头的终点（x4,y4）
        int y4 = y2 - l * cos(atan2((x2 - x1) , (y2 - y1)) - a);
        drawLine(p,QPoint(x2,y2),QPoint(x3,y3));                                 //绘制箭头(x2,y2,x3,y3)
        drawLine(p,QPoint(x2,y2),QPoint(x4,y4));                                 //绘制箭头(x2,y2,x4,y4)
        drawLine(p,*bg.GetPoints().begin(),*bg.GetPoints().end());                                   //绘制主干箭头(begin,end)
}



/**************************************BaseGraphic--Begin**************************/
BaseGraphic::BaseGraphic()

{
    qDebug()<<"BaseGraphic::BaseGraphic()";
    pointcount=0;
    penwidth=2;
    painter=new QPainter;
}

BaseGraphic::~BaseGraphic()
{
    delete painter;
}

void BaseGraphic::show(std::ostream &out)
{
    qDebug()<<"void BaseGraphic::show(std::ostream &out)";
    for(auto i=data.begin();i!=data.end();i++)
    {
        out<<"("<<i->x()<<","<<i->y()<<")"<<' ';
    }
}

size_t BaseGraphic::Pointcount()
{
    qDebug()<<"size_t BaseGraphic::Pointcount()";
    return pointcount;
}

bool BaseGraphic::isEmpty()
{
    qDebug()<<"bool BaseGraphic::isEmpty()";
    if(data.size()!=0)
        return false;
    return true;
}

void BaseGraphic::AppendPoint(const QPoint& po)
{
    qDebug()<<"void BaseGraphic::AppendPoint(const QPoint& po)";
    data.append(po);
    ++pointcount;
}

void BaseGraphic::DeletePoint()
{
    qDebug()<<"void BaseGraphic::DeletePoint()";
    if(data.size()!=0)
    {
        data.pop_back();
        --pointcount;
    }
}

QVector<QPoint> BaseGraphic::GetPoints() const
{
    qDebug()<<"QVector<QPoint> BaseGraphic::GetPoints() const";
    QVector<QPoint> vec;
    for(auto i=data.cbegin();i!=data.cend();i++)
    {
        vec.append(*i);
    }
    return vec;
}

QVector<QPoint> BaseGraphic::GetPoints()
{
    qDebug()<<"QVector<QPoint> BaseGraphic::GetPoints()";
    QVector<QPoint> vec;
    for(auto i=data.begin();i!=data.end();i++)
    {
        vec.append(*i);
    }
    return vec;
}

void BaseGraphic::setColor(const QColor& _color)
{
    color=_color;
}

void BaseGraphic::setPenwidth(int width)
{
    penwidth=width;
}

void BaseGraphic::setState(Graphic::State _state)
{
    state=_state;
}

void BaseGraphic::setType(Graphic::Type _type)
{
    type=_type;
}

/**************************************BaseGraphic--END**************************/
/**************************************Rectangle--Begin**************************/
Rectangle::Rectangle():BaseGraphic()
{
    qDebug()<<"Rectangle::Rectangle():BaseGraphic()";
}

Rectangle::~Rectangle()
{}

 void Rectangle::paint(QPaintDevice *device)
{
     qDebug()<<"void Rectangle::paint(QPaintDevice *device)";
     painter->begin(device);
     painter->setPen(QPen(color,penwidth));
     drawRectangle(painter,*this);
     painter->end();
}

/**************************************Rectangle--END**************************/
/**************************************Polygon--Begin**************************/
 Polygon::Polygon():BaseGraphic()
 {
     qDebug()<<"Polygon::Polygon():BaseGraphic()";
 }

 Polygon::~Polygon()
 {}

void Polygon::paint(QPaintDevice *device)
{
    qDebug()<<"void Polygon::paint(QPaintDevice *device)";
    painter->begin(device);
    painter->setPen(QPen(color,penwidth));
    drawPolygon(painter,*this);
    painter->end();
}

/**************************************Polygon--END**************************/
/**************************************Arrow--Begin**************************/
Arrow::Arrow():BaseGraphic()
{
   qDebug()<<"Arrow::Arrow():BaseGraphic()";
}

Arrow::~Arrow()
{}

void Arrow::paint(QPaintDevice *device)
{
   qDebug()<<"void Arrow::paint(QPaintDevice *device)";
    painter->begin(device);
    painter->setPen(QPen(color,penwidth));
    drawArrow(painter,*this);
    painter->end();
}
/**************************************Arrow--END**************************/
