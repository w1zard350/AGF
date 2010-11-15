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
#include <QGraphicsScene>
#include "agfshape.h"

AGFshape::AGFshape(AGFgraphicsItem* parent): AGFgraphicsItem(parent) {
    setPen(QPen(Qt::red, 2));
}

void AGFshape::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setPen(pen);
    painter->drawLine(tc(0,0), tc(50, 50));
}

QRectF AGFshape::boundingRect() const {
    return scene()->sceneRect();
}
//--------------------------------------------------------------------------------//
/**
 * Методы-аксессоры set для полей
 */
void AGFshape::setPen(QPen value) {
    pen = value;
}
//--------------------------------------------------------------------------------//
/**
 * Методы-аксессоры get для полей
 */
QPen AGFshape::getPen() const {
    return pen;
}
