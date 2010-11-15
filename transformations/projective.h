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
#ifndef PROJECTIVE_H
#define PROJECTIVE_H
#include <QPointF>
/**
 * Класс представляющий из себя систему аффинных преобразований
 */
class Projective
{
protected:
    /**
     * @var Координаты начала осей X и Y
     */
    qreal x0;
    qreal y0;

    /**
     * @var Координаты конца оси X
     */
    qreal Xx;
    qreal Yx;

    /**
     * @var Координаты конца оси Y
     */
    qreal Xy;
    qreal Yy;

    /**
     * @var Веса координатных осей
     */
    qreal W0;
    qreal Wx;
    qreal Wy;
public:
    Projective();
    QPointF transform(QPointF point);
    //--------------------------------------------------------------------------------//
    /**
     * Методы-аксессоры set
     */
    void setX0(qreal value);
    void setY0(qreal value);
    void setXx(qreal value);
    void setXy(qreal value);
    void setYx(qreal value);
    void setYy(qreal value);
    void setW0(qreal value);
    void setWx(qreal value);
    void setWy(qreal value);
    //--------------------------------------------------------------------------------//
    /**
     * Методы-аксессоры get
     */
    qreal getX0() const;
    qreal getY0() const;
    qreal getXx() const;
    qreal getXy() const;
    qreal getYx() const;
    qreal getYy() const;
    qreal getW0() const;
    qreal getWx() const;
    qreal getWy() const;
};

#endif // PROJECTIVE_H
