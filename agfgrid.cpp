/**
 * AGF - Advanced Graphic Framework
 * Copyright (C) 2010 Yuriy Buchchenko,
 * Copyright (C) 2010 Andrew Krasnogolovets
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details in LICENSE.txt.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "agfgrid.h"
#include <QGraphicsScene>
#include <QDebug>
AGFgrid::AGFgrid(QGraphicsItem* parent): AGFgraphicsItem(parent) {
    setQuarterVisible(1, true);
    setQuarterVisible(2, true);
    setQuarterVisible(3, true);
    setQuarterVisible(4, true);
    setCellNumX(10);
    setCellNumY(10);
    setCellSize(10);
}

void AGFgrid::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);

    // координаты центра графического объекта
    qreal xc = center.x();
    qreal yc = center.y();

    // считаем координаты крайних линий координатных четвертей
    qreal xleft   = xc - cellNumX*cellSize;
    qreal ybottom = yc - cellNumY*cellSize;
    qreal xright = xc + cellNumX*cellSize;
    qreal ytop   = yc + cellNumY*cellSize;

    // определяем области координатных четвертей
    QRectF firstQ( QPointF(xc, ytop),    QPointF(xright, yc));
    QRectF secondQ(QPointF(xleft, ytop), QPointF(xc, yc));
    QRectF thirdQ( QPointF(xleft, yc),   QPointF(xc, ybottom));
    QRectF fourthQ(QPointF(xc, yc),      QPointF(xright, ybottom));

    // в зависимости от видимости, рисуем четверти
    if(quartersVisible[0]) drawGrid(firstQ, painter);
    if(quartersVisible[1]) drawGrid(secondQ, painter);
    if(quartersVisible[2]) drawGrid(thirdQ, painter);
    if(quartersVisible[3]) drawGrid(fourthQ, painter);

    painter->setPen(axePen);
    painter->drawLine(xleft, yc, xright, yc); // ось X
    painter->drawLine(xc, ybottom, xc, ytop); // ось Y

    // стрелочка X
    QPointF points[3];
    points[0] = QPointF(xright, yc);
    points[1] = QPointF(xright-10, yc-2);
    points[2] = QPointF(xright-10, yc+2);
    painter->drawPolygon(points, 3, Qt::WindingFill);

    // стрелочка Y
    points[0] = QPointF(xc, ytop);
    points[1] = QPointF(xc-2, ytop-10);
    points[2] = QPointF(xc+2, ytop-10);
    painter->drawPolygon(points, 3, Qt::WindingFill);

    painter->drawText(xright-10, yc+15, "x");
    painter->drawText(xc+5, ytop-10, "y");
}

void AGFgrid::drawGrid(QRectF area, QPainter* painter) {
    painter->setPen(gridPen);
    // вертикальные полосы
    for(qreal x=area.left(); x <= area.right(); x += cellSize) {
        painter->drawLine(x, area.bottom(), x, area.top());
    }
    // горизонтальные полосы
    for(qreal y=area.bottom(); y<=area.top(); y+=cellSize) {
        painter->drawLine(area.left(), y, area.right(), y);
    }
}

QRectF AGFgrid::boundingRect() const {
    return scene()->sceneRect();
}

//--------------------------------------------------------------------------------//
/**
 * Методы-аксессоры set для полей
 */
void AGFgrid::setQuarterVisible(int num, bool value) {
    if(num >= 1 && num <= 4) {
        quartersVisible[num-1] = value;
    }
}

void AGFgrid::setCellNumX(int value) {
    if(value > 0) cellNumX = value;
    else cellNumX = 0;
}

void AGFgrid::setCellNumY(int value) {
    if(value > 0) cellNumY = value;
    else cellNumY = 0;
}

void AGFgrid::setCellSize(int value) {
    if(value > 0) cellSize = value;
    else cellSize = 0;
}

void AGFgrid::setPenAxe(QPen value) {
    axePen = value;
}

void AGFgrid::setPenGrid(QPen value) {
    gridPen = value;
}
//--------------------------------------------------------------------------------//
/**
 * Методы-аксессоры get для полей
 */
bool AGFgrid::getQuarterVisible(int num) const {
    if(num >= 1 && num <= 4) {
        return quartersVisible[num-1];
    }
    return false;
}

int AGFgrid::getCellNumX() const {
    return cellNumX;
}

int AGFgrid::getCellNumY() const {
    return cellNumY;
}

int AGFgrid::getCellSize() const {
    return cellSize;
}

QPen AGFgrid::getPenAxe() const {
    return axePen;
}

QPen AGFgrid::getPenGrid() const {
    return gridPen;
}
