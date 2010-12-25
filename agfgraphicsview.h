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
#include "AGF/transformations/agfaffine.h"
#include "AGF/transformations/agfeuclidean.h"
#include "AGF/transformations/agfprojective.h"

/**
 * Класс виджета для рисования.
 */
class AGFGraphicsView: public QGraphicsView
{
    Q_OBJECT
protected:
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
     * @var Объекты систем преобразований
     */
    AGFAffine* affine;
    AGFEuclidean* euclidean;
    AGFProjective* projective;

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
    void updateScene();

    void setEuclideanEnabled(bool value);
    void setAffineEnabled(bool value);
    void setProjectiveEnabled(bool value);



    void setCenterX(double value);
    void setCenterY(double value);

public:
    bool getEuclideanEnabled() const;
    bool getAffineEnabled() const;
    bool getProjectiveEnabled() const;

    Qt::GlobalColor getBgColor() const;
    QPointF getCenter() const;
};

#endif // AGFGRAPHICSVIEW_H
