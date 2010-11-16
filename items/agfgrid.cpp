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

AGFGrid::AGFGrid(QGraphicsItem* parent): AGFGraphicsItem(parent) {
    setQuarterVisible(1, true);
    setQuarterVisible(2, true);
    setQuarterVisible(3, true);
    setQuarterVisible(4, true);
    setCellNumX(10);
    setCellNumY(10);
    setCellSize(10);
    setPenAxe(QPen(Qt::black, 2));
    setPenGrid(QPen(Qt::lightGray, 1));
}

void AGFGrid::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
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
    if(quartersVisible[0] || quartersVisible[3]) painter->drawLine(tc(xc, yc), tc(xright, yc)); // ось X (положительная)
    if(quartersVisible[1] || quartersVisible[2]) painter->drawLine(tc(xleft, yc), tc(xc, yc)); // ось X (отрицательная)
    if(quartersVisible[0] || quartersVisible[1]) painter->drawLine(tc(xc, yc), tc(xc, ytop)); // ось Y (положительная)
    if(quartersVisible[2] || quartersVisible[3]) painter->drawLine(tc(xc, yc), tc(xc, ybottom)); // ось Y (отрицательная)


    QPointF points[3];
    QPointF point;
    // стрелочка X
    if(quartersVisible[0] || quartersVisible[3]) {
        point = tc(xright, yc);
        points[0] = point;
        points[1] = QPointF(point.x()-10, point.y()-2);
        points[2] = QPointF(point.x()-10, point.y()+2);
        painter->drawPolygon(points, 3, Qt::WindingFill);
        painter->drawText(QPointF(point.x()-10, point.y()+15), "x");
    }

    // стрелочка Y
    if(quartersVisible[0] || quartersVisible[1]) {
        point = tc(xc, ytop);
        points[0] = point;
        points[1] = QPointF(point.x()-2, point.y()+10);
        points[2] = QPointF(point.x()+2, point.y()+10);
        painter->drawPolygon(points, 3, Qt::WindingFill);
        painter->drawText(QPointF(point.x()+5, point.y()-10), "y");
    }

}

void AGFGrid::drawGrid(QRectF area, QPainter* painter) {
    painter->setPen(gridPen);
    // вертикальные полосы
    for(qreal x=area.left(); x <= area.right(); x += cellSize) {
        painter->drawLine(tc(x, area.bottom()), tc(x, area.top()));
    }
    // горизонтальные полосы
    for(qreal y=area.bottom(); y<=area.top(); y+=cellSize) {
        painter->drawLine(tc(area.left(), y), tc(area.right(), y));
    }
}

QRectF AGFGrid::boundingRect() const {
    return scene()->sceneRect();
}

//--------------------------------------------------------------------------------//
/**
 * Методы-аксессоры set для полей
 */
void AGFGrid::setQuarterVisible(int num, bool value) {
    if(num >= 1 && num <= 4) {
        quartersVisible[num-1] = value;
    }
}

void AGFGrid::setCellNumX(int value) {
    if(value > 0) cellNumX = value;
    else cellNumX = 0;
}

void AGFGrid::setCellNumY(int value) {
    if(value > 0) cellNumY = value;
    else cellNumY = 0;
}

void AGFGrid::setCellSize(int value) {
    if(value > 0) cellSize = value;
    else cellSize = 0;
}

void AGFGrid::setPenAxe(QPen value) {
    axePen = value;
}

void AGFGrid::setPenGrid(QPen value) {
    gridPen = value;
}
//--------------------------------------------------------------------------------//
/**
 * Методы-аксессоры get для полей
 */
bool AGFGrid::getQuarterVisible(int num) const {
    if(num >= 1 && num <= 4) {
        return quartersVisible[num-1];
    }
    return false;
}

int AGFGrid::getCellNumX() const {
    return cellNumX;
}

int AGFGrid::getCellNumY() const {
    return cellNumY;
}

int AGFGrid::getCellSize() const {
    return cellSize;
}

QPen AGFGrid::getPenAxe() const {
    return axePen;
}

QPen AGFGrid::getPenGrid() const {
    return gridPen;
}
