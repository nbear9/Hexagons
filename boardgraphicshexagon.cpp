#include "boardgraphicshexagon.h"
#include <QDebug>
#include <QBrush>


boardGraphicsHexagon::boardGraphicsHexagon(QGraphicsItem * parent): QGraphicsPixmapItem(parent)
{
    setAcceptDrops(true);
    setAcceptedMouseButtons(Qt::LeftButton);
    setAcceptHoverEvents(true);

    setShapeMode(QGraphicsPixmapItem::MaskShape);

    setFlag(QGraphicsItem::ItemIsFocusable);
    setFlag(QGraphicsItem::ItemIsSelectable);
}


void boardGraphicsHexagon::focusInEvent(QFocusEvent*)
{
    qDebug() << this->toolTip() << Q_FUNC_INFO;
}

void boardGraphicsHexagon::focusOutEvent(QFocusEvent*)
{
    qDebug() << this->toolTip() << Q_FUNC_INFO;
}

void boardGraphicsHexagon::hoverEnterEvent(QGraphicsSceneHoverEvent*)
{
    qDebug() << this->toolTip() << Q_FUNC_INFO;
//    this->setBrush(QBrush(Qt::cyan));
}

void boardGraphicsHexagon::hoverLeaveEvent(QGraphicsSceneHoverEvent*)
{
    qDebug() << this->toolTip() << Q_FUNC_INFO;
//    this->setBrush(QBrush());
}

void boardGraphicsHexagon::hoverMoveEvent(QGraphicsSceneHoverEvent*)
{
//    qDebug() << this->toolTip() << Q_FUNC_INFO;
}

void boardGraphicsHexagon::dragEnterEvent(QGraphicsSceneDragDropEvent*)
{
    qDebug() << this->toolTip() << Q_FUNC_INFO;

//    this->setBrush(QBrush(Qt::cyan));
}

void boardGraphicsHexagon::dragLeaveEvent(QGraphicsSceneDragDropEvent*)
{
    qDebug() << this->toolTip() << Q_FUNC_INFO;
//    this->setBrush(QBrush());
}

void boardGraphicsHexagon::dragMoveEvent(QGraphicsSceneDragDropEvent*)
{
    qDebug() << this->toolTip() << Q_FUNC_INFO;
}

void boardGraphicsHexagon::dropEvent(QGraphicsSceneDragDropEvent*)
{
    qDebug() << this->toolTip() << Q_FUNC_INFO;
}

