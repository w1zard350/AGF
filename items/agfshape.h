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
#ifndef AGFSHAPE_H
#define AGFSHAPE_H
#include <QPainter>
#include "agfgraphicsitem.h"

/**
 * Геометрическая фигура, любая.
 */
class AGFShape: public AGFGraphicsItem
{
protected:
    /**
     * @var Перо для фигуры
     */
    QPen pen;
public:
    AGFShape(AGFGraphicsItem* parent = 0);
    //--------------------------------------------------------------------------------//
    /**
     * Событие полной перерисовки объекта
     */
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    /**
     * Определяет прямоугольник, в котором производиться рисование
     */
    QRectF boundingRect() const;
    //--------------------------------------------------------------------------------//
    /**
     * Методы-аксессоры set
     */
    void setPen(QPen value);
    //--------------------------------------------------------------------------------//
    /**
     * Методы-аксессоры get
     */
    QPen getPen() const;
};

#endif // AGFSHAPE_H
