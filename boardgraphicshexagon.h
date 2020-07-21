#ifndef BOARDGRAPHICSHEXAGON_H
#define BOARDGRAPHICSHEXAGON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneHoverEvent>
#include <QGraphicsSceneDragDropEvent>
#include <QFocusEvent>
#include <QGraphicsItem>

class boardGraphicsHexagon : public QGraphicsPixmapItem
{
public:
    boardGraphicsHexagon(QGraphicsItem *parent = 0);
    ~boardGraphicsHexagon(){}
    void focusInEvent(QFocusEvent*);
    void focusOutEvent(QFocusEvent*);
    void hoverEnterEvent(QGraphicsSceneHoverEvent*);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent*);
    void hoverMoveEvent(QGraphicsSceneHoverEvent*);
    void dragEnterEvent(QGraphicsSceneDragDropEvent*);
    void dragLeaveEvent(QGraphicsSceneDragDropEvent*);
    void dragMoveEvent(QGraphicsSceneDragDropEvent*);
    void dropEvent(QGraphicsSceneDragDropEvent *);
};

#endif // BOARDGRAPHICSHEXAGON_H
