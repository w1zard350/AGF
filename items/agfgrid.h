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
#ifndef AGFGRID_H
#define AGFGRID_H
#include <QPainter>
#include "../agfgraphicsitem.h"

/**
 * Объект для рисования - сетка (grid).
 */
class AGFGrid: public AGFGraphicsItem
{
protected:
    /**
     * @var Массив параметров видимости координатных четвертей
     */
    bool quartersVisible[4];

    /**
     * @var Количество делений сетки по X и Y
     */
    int cellNumX;
    int cellNumY;

    /**
     * @var Размер ячейки сетки
     */
    int cellSize;

    /**
     * @var Перо для осей и для сетки
     */
    QPen axePen;
    QPen gridPen;
public:
    AGFGrid(QGraphicsItem* parent = 0);

    //--------------------------------------------------------------------------------//
    /**
     * Событие полной перерисовки объекта
     */
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    /**
     * Определяет прямоугольник, в котором производиться рисование
     */
    QRectF boundingRect() const;

    /**
     * Рисует сетку
     * @param area - прямоугольная область рисования
     * @param painter - объект, который выполняет собственно рисование
     */
    void drawGrid(QRectF area, QPainter* painter);
    //--------------------------------------------------------------------------------//
    /**
     * Методы-аксессоры set
     */
    void setQuarterVisible(int num, bool value);
    void setCellNumX(int value);
    void setCellNumY(int value);
    void setCellSize(int value);
    void setPenAxe(QPen value);
    void setPenGrid(QPen value);
    //--------------------------------------------------------------------------------//
    /**
     * Методы-аксессоры get
     */
    bool getQuarterVisible(int num) const;
    int getCellNumX() const;
    int getCellNumY() const;
    int getCellSize() const;
    QPen getPenAxe() const;
    QPen getPenGrid() const;
};

#endif // AGFGRID_H
