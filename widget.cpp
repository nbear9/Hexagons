#include "widget.h"
#include <QGraphicsView>
#include "graphicsscene.h"
#include <QHBoxLayout>
#include <QGraphicsPolygonItem>
#include <QPolygonF>
#include <qmath.h>
#include "boardhexagon.h"
#include "boardgraphicshexagon.h"

const bool VERTICAL = true;
const int SIZE      = 44;
const int FIELD_X   = 5;
const int FIELD_Y   = 8;
const bool GRAPHICAL = true;


Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QHBoxLayout * hbox = new QHBoxLayout;
    QGraphicsView * view = new QGraphicsView;
    GraphicsScene * scene = new GraphicsScene;

    qsrand(12355);

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
    QPixmap p;
    for(int r = 0; r < FIELD_Y; r++)
    {
        for(int c = 0; c < FIELD_X; c++)
        {
            if(GRAPHICAL)
            {
                boardGraphicsHexagon* hexagon = new boardGraphicsHexagon(0);

                int t = qrand() % 4;
                switch (t) {
                    case 0:
                        p = QPixmap(":/terrains/grass.png");
                        break;
                    case 1:
                        p = QPixmap(":/terrains/dirt.png");
                        break;
                    case 2:
                        p = QPixmap(":/terrains/sand.png");
                        break;
                    case 3:
                    default:
                        p = QPixmap(":/terrains/stone.png");
                        break;
                }
                hexagon->setPixmap(p.scaled(dx*2, side*2));
                scene->addItem(hexagon);
                if(hexVertical)
                    hexagon->setPos(dx * (c * 2 + (r % 2)), side * 1.5 * r);
                else
                    hexagon->setPos(side * 1.5 * c, dx * (r * 2 + (c % 2)));
                hexagon->setToolTip(QString::number(x_coord) + "," + QString::number(y_coord));
            }
            else
            {
                BoardHexagon * hexagon = new BoardHexagon(0);
                hexagon->setPolygon(polygon);
                scene->addItem(hexagon);
                if(hexVertical)
                    hexagon->setPos(dx * (c * 2 + (r % 2)), side * 1.5 * r);
                else
                    hexagon->setPos(side * 1.5 * c, dx * (r * 2 + (c % 2)));
                hexagon->setToolTip(QString::number(x_coord) + "," + QString::number(y_coord));
            }
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
