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
#ifndef AGFGRAPHICSITEM_H
#define AGFGRAPHICSITEM_H
#include <QGraphicsItem>
class AGFgraphicsView;
/**
 * Абстрактный класс объекта рисования. Наследуя его вы создаете новую фигуру.
 * Предназначен для управления базовыми функциями для всех объектов рисования.
 */
class AGFgraphicsItem: public QGraphicsItem
{
protected:
    /**
     * @var Виджет для рисования
     */
    AGFgraphicsView* view;
    /**
     * @var Координата центра фигуры
     */
    QPointF center;
public:
    AGFgraphicsItem(QGraphicsItem* parent = 0);
    //--------------------------------------------------------------------------------//
    /**
     * Методы-аксессоры set
     */
    void setGraphicsView(AGFgraphicsView* value);
    void setCenter(QPointF value);
    //--------------------------------------------------------------------------------//
    /**
     * Методы-аксессоры get
     */
    AGFgraphicsView* getGraphicsView() const;
    QPointF getCenter() const;
};

#endif // AGFGRAPHICSITEM_H
