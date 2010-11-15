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
#ifndef AGFGRAPHICSVIEW_H
#define AGFGRAPHICSVIEW_H
#include <QGraphicsView>
#include "items/agfgrid.h"
class Affine;
class Euclidean;
class Projective;
/**
 * Класс виджета для рисования.
 */
class AGFgraphicsView: public QGraphicsView
{
    Q_OBJECT
protected:
    /**
     * @var Объекты систем преобразований
     */
    Affine* affine;
    Euclidean* euclidean;
    Projective* projective;
    /**
     * @var Цвет фона сцены
     */
    Qt::GlobalColor bgColor;
    /**
     * @var Состояния "включенности" систем преобразований
     */
    bool affineEnabled;
    bool euclideanEnabled;
    bool projectiveEnabled;
public:
    AGFgraphicsView(QWidget* parent = 0);

    /**
     * Добавляет новый элемент (объект для прорисовки) в сцену
     */
    void addItem(AGFgraphicsItem* item);
    /**
     * Пересчитывает параметры сцены и вносит изменения в виджет для рисования View
     */
    void reconfigure();
    /**
     * Применяет к переданной точке систему всех активных преобразований
     * @param point точка для преобразования
     * @return точка с преобразованными координатами
     */
    QPointF tc(QPointF point);
    //--------------------------------------------------------------------------------//
    /**
     * События
     */
    void resizeEvent(QResizeEvent* event);
    //--------------------------------------------------------------------------------//
    /**
     * Методы-аксессоры set
     */
    void setAffine(Affine* value);
    void setEuclidean(Euclidean* value);
    void setProjective(Projective* value);

    void setBgColor(Qt::GlobalColor value);
public slots:
    void setEuclideanEnabled(bool value);
    void setAffineEnabled(bool value);
    void setProjectiveEnabled(bool value);

    void setMx(double value);
    void setMy(double value);

    void setAlphaDegree(double value);
    void setBetaDegree(double value);
    void setGammaDegree(double value);

    void setXShift(double value);
    void setYShift(double value);
    //--------------------------------------------------------------------------------//
    /**
     * Методы-аксессоры get
     */
public:
    Affine* getAffine() const;
    Euclidean* getEuclidean() const;
    Projective* getProjective() const;

    Qt::GlobalColor getBgColor() const;
    bool getEuclideanEnabled() const;
    bool getAffineEnabled() const;
    bool getProjectiveEnabled() const;
};

#endif // AGFGRAPHICSVIEW_H
