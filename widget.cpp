#include "widget.h"
#include <QGraphicsView>
#include "graphicsscene.h"
#include <QHBoxLayout>
#include <QGraphicsPolygonItem>
#include <QPolygonF>
#include <qmath.h>
#include "boardhexagon.h"

const bool VERTICAL = true;
const int SIZE      = 30;
const int FIELD_X   = 9;
const int FIELD_Y   = 15;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QHBoxLayout * hbox = new QHBoxLayout;
    QGraphicsView * view = new QGraphicsView;
    GraphicsScene * scene = new GraphicsScene;

    const qreal side = SIZE;
    const qreal dx = qSqrt(3)/2 * side;
    const bool hexVertical = VERTICAL;

    QPolygonF polygon;       
    if(hexVertical)
    {
        polygon
            // standing on a point (vertical)
            << QPointF(dx, -side/2)
            << QPointF(0, -side)
            << QPointF(-dx, -side/2)
            << QPointF(-dx, side/2)
            << QPointF(0, side)
            << QPointF(dx, side/2);
    }
    else
    {
        polygon
            // sitting flat (horizontal)
            << QPointF(-side/2, dx)
            << QPointF(-side, 0)
            << QPointF(-side/2, -dx)
            << QPointF(side/2, -dx)
            << QPointF(side, 0)
            << QPointF(side/2, dx);
    }

    int x_coord = 0;
    int y_coord = 0;
    for(int r = 0; r < FIELD_Y; r++)
    {
        for(int c = 0; c < FIELD_X; c++)
        {
            BoardHexagon * hexagon = new BoardHexagon(0);
            hexagon->setPolygon(polygon);
            scene->addItem(hexagon);
            if(hexVertical)
                hexagon->setPos(dx * (c * 2 + (r % 2)), side * 1.5 * r);
            else
                hexagon->setPos(side * 1.5 * c, dx * (r * 2 + (c % 2)));
            hexagon->setToolTip(QString::number(x_coord) + "," + QString::number(y_coord));
            x_coord++;
        }
        x_coord = 0;
        y_coord++;
    }

    QGraphicsEllipseItem * ellipse = scene->addEllipse(-40, -40, 20, 20,QPen(), QBrush(QColor(Qt::green)));
    this->makeDraggable(ellipse);


    view->setRenderHint(QPainter::Antialiasing);
    view->setScene(scene);

    view->setMouseTracking(true);

    hbox->addWidget(view);
    this->setLayout(hbox);

    this->resize(800, 800);
}

void Widget::makeDraggable(QGraphicsItem *item)
{
    item->setFlag(QGraphicsItem::ItemIsSelectable);
    item->setFlag(QGraphicsItem::ItemIsMovable);
    item->setFlag(QGraphicsItem::ItemSendsGeometryChanges);
    item->setFlag(QGraphicsItem::ItemSendsScenePositionChanges);
}

Widget::~Widget()
{

}
