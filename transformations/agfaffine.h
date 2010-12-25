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
#ifndef AGFAFFINE_H
#define AGFAFFINE_H

#include <QObject>
#include <QPointF>

/**
 * Класс представляющий из себя систему аффинных преобразований
 */
class AGFAffine : public QObject
{
    Q_OBJECT
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
     * @var Масштаб по осям X и Y
     */
    qreal Mx;
    qreal My;

    /**
     * @var Симметрия относительно X и Y
     */
    bool invertX;
    bool invertY;

public:
    AGFAffine();

    /**
     * Масштабирование координаты точки
     * @param point точка для преобразования координат
     * @return point точка с новыми, преобразованными координатами
     */
    QPointF scale(QPointF point);

    /**
     * Выполняет аффинное преобразование
     * @param point точка для преобразования координат
     * @return point точка с новыми, преобразованными координатами
     */
    QPointF transform(QPointF point);

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
    qreal getMx() const;
    qreal getMy() const;

    bool getInvertX() const;
    bool getInvertY() const;

//--------------------------------------------------------------------------------//
public slots:
    /**
     * Методы-аксессоры set
     */
    void setX0(double value);
    void setY0(double value);
    void setXx(double value);
    void setXy(double value);
    void setYx(double value);
    void setYy(double value);
    void setMx(double value);
    void setMy(double value);
    void setMg(double value);
    void setInvertX(bool value);
    void setInvertY(bool value);

signals:
    void changed();
};

#endif // AGFAFFINE_H
