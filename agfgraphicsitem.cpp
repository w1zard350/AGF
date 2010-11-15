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
#include "agfgraphicsitem.h"
#include "agfgraphicsview.h"
AGFGraphicsItem::AGFGraphicsItem(QGraphicsItem* parent): QGraphicsItem(parent) {
    setCenter(QPointF(0,0));
}

QPointF AGFGraphicsItem::tc(qreal x, qreal y) {
    return view->tc(QPointF(x,y));
}

//--------------------------------------------------------------------------------//
/**
 * Методы-аксессоры set для полей
 */
void AGFGraphicsItem::setGraphicsView(AGFGraphicsView* value) {
    view = value;
}

void AGFGraphicsItem::setCenter(QPointF value) {
    center = value;
}

//--------------------------------------------------------------------------------//
/**
 * Методы-аксессоры get для полей
 */
AGFGraphicsView* AGFGraphicsItem::getGraphicsView() const {
    return view;
}

QPointF AGFGraphicsItem::getCenter() const {
    return center;
}


