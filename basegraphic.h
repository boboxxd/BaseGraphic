#ifndef BASEGRAPHIC_H
#define BASEGRAPHIC_H
#include <QPoint>
#include <QVector>
#include <QColor>
#include <QPainter>
#include <QPaintDevice>
#include <iostream>
#include <QDebug>

namespace Graphic {
    enum State{IN,OUT,ALL};
    enum Type {Alarm,Handle};
    class BaseGraphic; //base class
    class Rectangle;
    class Polygon;
    class Arrow;
    void drawRectangle(QPainter *p,const QPoint& begin,const QPoint& end);
    void drawRectangle(QPainter *p,const BaseGraphic& bg);

    void drawLine(QPainter *p,const QPoint& begin,const QPoint& end);

    void drawArrow(QPainter *p,const QPoint& begin,const QPoint& end);
    void drawArrow(QPainter *p,const BaseGraphic& bg);

    void drawPolygon(QPainter *p,const BaseGraphic& bg);
}

//base class of graphic
class BaseGraphic
{
public:
    virtual void show(std::ostream &out);
    BaseGraphic();
    virtual ~BaseGraphic();
    void setColor(const QColor&);
    void setPenwidth(int width);
    void setState(Graphic::State);
    void setType(Graphic::Type);
    void AppendPoint(const QPoint&); //add one point
    void DeletePoint(); //delete last point
    QVector<QPoint> GetPoints() const;
    QVector<QPoint> GetPoints();
    bool isEmpty();
    size_t Pointcount();

    virtual void paint(QPaintDevice*)=0; //draw the graphic
protected:
    size_t pointcount; //number of points
    QVector<QPoint> data; //save each points;
    QColor color;
    int penwidth;
    Graphic::State state; //into area or outfrom area
    Graphic::Type type; //Alarm area or Handle area
    QPainter *painter;
};

class Rectangle:public BaseGraphic
{
public:
    Rectangle();
    ~Rectangle();
    virtual void paint(QPaintDevice*) override;
private:
};

class Polygon:public BaseGraphic
{
public:
    Polygon();
    ~Polygon();
    virtual void paint(QPaintDevice*) override;
private:
};

class Arrow:public BaseGraphic
{
public:
    Arrow();
    ~Arrow();
    virtual void paint(QPaintDevice*) override;
private:
};

#endif // BASEGRAPHIC_H
