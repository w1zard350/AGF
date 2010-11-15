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
#ifndef AGFEUCLIDEAN_H
#define AGFEUCLIDEAN_H
#include <QPointF>

/**
 * Класс представляющий из себя систему эвклидовых преобразований
 */
class AGFEuclidean
{
protected:
    /**
     * @var Сдвиг по осям X и Y
     */
    qreal xShift;
    qreal yShift;

    /**
     * @var Углы вращения относительно всех осей
     */
    qreal alpha;
    qreal beta;
    qreal gamma;

public:
    AGFEuclidean();

    /**
     * Выполняет перенос (смещение) фигуры. Меняет координаты точки, реализуя смещение
     * @param point точка для преобразования координат
     * @return point точка с новыми, преобразованными координатами
     */
    QPointF shift(QPointF point);

    /**
     * Вращает фигуру. Меняет координаты точки, реализуя вращение
     * @param point точка для преобразования координат
     * @return point точка с новыми, преобразованными координатами
     */
    QPointF rotate(QPointF point);

    //--------------------------------------------------------------------------------//
    /**
     * Методы-аксессоры set
     */
    void setXShift(qreal value);
    void setYShift(qreal value);
    void setAlpha(qreal value);
    void setBeta(qreal value);
    void setGamma(qreal value);

    //--------------------------------------------------------------------------------//
    /**
     * Методы-аксессоры get
     */
    qreal getXShift() const;
    qreal getYShift() const;
    qreal getAlpha() const;
    qreal getBeta() const;
    qreal getGamma() const;
};

#endif // AGFEUCLIDEAN_H
