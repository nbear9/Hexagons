#include "widget.h"
#include <QGraphicsView>
#include "graphicsscene.h"
#include <QHBoxLayout>
#include <QGraphicsPolygonItem>
#include <QPolygonF>
#include <qmath.h>
#include "boardhexagon.h"

const int SIZE      = 30;
const int FIELD_X   = 9;
const int FIELD_Y   = 15;
const bool VERTICAL = true;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QHBoxLayout * hbox = new QHBoxLayout;
    QGraphicsView * view = new QGraphicsView;
    GraphicsScene * scene = new GraphicsScene;

    const qreal side = SIZE;
    const qreal dx = qSqrt(3)/2 * side;
    const bool hexVertical = VERTICAL;
    int w = FIELD_X;
    int h = FIELD_Y;

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
        w *= 2;
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
        h *= 2;
    }

    for(int r = 0; r < h; r++)
    {
        for(int c = 0; c < w; c++)
        {
            if(r % 2 != c % 2)
            {
                // don't add a hexagon, it isn't on the board!
            }
            else
            {
                BoardHexagon * hexagon = new BoardHexagon(0);
                hexagon->setPolygon(polygon);
                scene->addItem(hexagon);
                if(hexVertical)
                    hexagon->setPos(dx * c, side * 1.5 * r);
                else
                    hexagon->setPos(side * 1.5 * c, dx * r);
                hexagon->setToolTip(QString::number(r) + "," + QString::number(c));
            }
        }
    }

    QGraphicsEllipseItem * ellipse = scene->addEllipse(-20, -20, 20, 20,QPen(), QBrush(QColor(Qt::green)));
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
