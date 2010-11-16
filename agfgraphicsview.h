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
#include <QWheelEvent>
#include "items/agfgrid.h"

class AGFAffine;
class AGFEuclidean;
class AGFProjective;

/**
 * Класс виджета для рисования.
 */
class AGFGraphicsView: public QGraphicsView
{
    Q_OBJECT
protected:
    /**
     * @var Объекты систем преобразований
     */
    AGFAffine* affine;
    AGFEuclidean* euclidean;
    AGFProjective* projective;

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

    /**
     * @var Координата центра сцены
     */
    QPointF center;
public:
    AGFGraphicsView(QWidget* parent = 0);

    /**
     * Добавляет новый элемент (объект для прорисовки) в сцену
     */
    void addItem(AGFGraphicsItem* item);

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
    void wheelEvent(QWheelEvent *event);

    //--------------------------------------------------------------------------------//
    /**
     * Методы-аксессоры set
     */
    void setAffine(AGFAffine* value);
    void setEuclidean(AGFEuclidean* value);
    void setProjective(AGFProjective* value);

    void setBgColor(Qt::GlobalColor value);
    void setCenter(QPointF value);

signals:
    /**
     * Сигналы, возникающие при прокрутке колесиком
     */
    void zoomedIn();
    void zoomedOut();

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

    void setAffineXx(double value);
    void setAffineYx(double value);
    void setAffineXy(double value);
    void setAffineYy(double value);

    void setAffineX0(double value);
    void setAffineY0(double value);

    void setProjectiveXx(double value);
    void setProjectiveYx(double value);
    void setProjectiveXy(double value);
    void setProjectiveYy(double value);

    void setProjectiveX0(double value);
    void setProjectiveY0(double value);

    void setProjectiveW0(double value);
    void setProjectiveWx(double value);
    void setProjectiveWy(double value);

    void setCenterX(double value);
    void setCenterY(double value);
    //--------------------------------------------------------------------------------//
    /**
     * Методы-аксессоры get
     */

public:
    AGFAffine* getAffine() const;
    AGFEuclidean* getEuclidean() const;
    AGFProjective* getProjective() const;

    bool getEuclideanEnabled() const;
    bool getAffineEnabled() const;
    bool getProjectiveEnabled() const;

    Qt::GlobalColor getBgColor() const;
    QPointF getCenter() const;
};

#endif // AGFGRAPHICSVIEW_H
