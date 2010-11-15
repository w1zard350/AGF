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
#include "affine.h"

Affine::Affine()
{
    setX0(0);
    setY0(0);

    setXx(1); setYx(0);
    setXy(0); setYy(1);

    setMx(1);
    setMy(1);

    setInvertX(false);
    setInvertY(false);
}

QPointF Affine::scale(QPointF point) {
    point.setX(point.x()*Mx);
    point.setY(point.y()*My);
    return point;
}

QPointF Affine::transform(QPointF point) {
    qreal x = point.x();
    qreal y = point.y();

    // симметрия
    if(invertX) y = -y;
    if(invertY) x = -x;

    // математическая модель
    qreal x_ = x0 + Xx*x + Xy*y;
    qreal y_ = y0 + Yx*x + Yy*y;

    point.setX(x_);
    point.setY(y_);
    return point;
}


//--------------------------------------------------------------------------------//
/**
 * Методы-аксессоры set для полей
 */
void Affine::setX0(qreal value) {
    x0 = value;
}
void Affine::setY0(qreal value) {
    y0 = value;
}
void Affine::setXx(qreal value) {
    Xx = value;
}
void Affine::setYx(qreal value) {
    Yx = value;
}
void Affine::setXy(qreal value) {
    Xy = value;
}
void Affine::setYy(qreal value) {
    Yy = value;
}
void Affine::setMx(qreal value) {
    Mx = value;
}
void Affine::setMy(qreal value) {
    My = value;
}
void Affine::setInvertX(bool value) {
    invertX = value;
}
void Affine::setInvertY(bool value) {
    invertY = value;
}
//--------------------------------------------------------------------------------//
/**
 * Методы-аксессоры get для полей
 */
qreal Affine::getX0() const {
    return x0;
}
qreal Affine::getY0() const {
    return y0;
}
qreal Affine::getXx() const {
    return Xx;
}
qreal Affine::getYx() const {
    return Yx;
}
qreal Affine::getXy() const {
    return Xy;
}
qreal Affine::getYy() const {
    return Yy;
}
qreal Affine::getMx() const {
    return Mx;
}
qreal Affine::getMy() const {
    return My;
}
bool Affine::getInvertX() const {
    return invertX;
}
bool Affine::getInvertY() const {
    return invertY;
}
