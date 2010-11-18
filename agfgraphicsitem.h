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
#include <QPainter>

class AGFGraphicsView;

/**
 * Абстрактный класс объекта рисования. Наследуя его вы создаете новую фигуру.
 * Предназначен для управления базовыми функциями для всех объектов рисования.
 */
class AGFGraphicsItem: public QGraphicsItem
{
protected:
    /**
     * @var Виджет для рисования
     */
    AGFGraphicsView* view;

    /**
     * @var Координата центра фигуры
     */
    QPointF center;

public:
    AGFGraphicsItem(QGraphicsItem* parent = 0);

    /**
     * Применяет к переданной точке систему всех активных преобразований
     * @param x,y координаты точки для преобразования
     * @return точка с преобразованными координатами
     */
    QPointF tc(qreal x, qreal y);

    /**
     * Перегрузка предыдущего метода
     * @param point координаты точки для преобразования
     * @return точка с преобразованными координатами
     */
    QPointF tc(QPointF point);

    //--------------------------------------------------------------------------------//
    /**
     * Методы-аксессоры set
     */
    void setGraphicsView(AGFGraphicsView* value);
    void setCenter(QPointF value);

    //--------------------------------------------------------------------------------//
    /**
     * Методы-аксессоры get
     */
    AGFGraphicsView* getGraphicsView() const;
    QPointF getCenter() const;
};

#endif // AGFGRAPHICSITEM_H
