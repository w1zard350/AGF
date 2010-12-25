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
#include "agfaffine.h"

AGFAffine::AGFAffine() {
    setX0(0);
    setY0(0);

    setXx(1); setYx(0);
    setXy(0); setYy(1);

    setMx(1);
    setMy(1);

    setInvertX(false);
    setInvertY(false);
}

QPointF AGFAffine::scale(QPointF point) {
    point.setX(point.x()*Mx);
    point.setY(point.y()*My);
    return point;
}

QPointF AGFAffine::transform(QPointF point) {
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
void AGFAffine::setX0(double value) {
    x0 = value;
    emit changed();
}
void AGFAffine::setY0(double value) {
    y0 = value;
    emit changed();
}
void AGFAffine::setXx(double value) {
    Xx = value;
    emit changed();
}
void AGFAffine::setYx(double value) {
    Yx = value;
    emit changed();
}
void AGFAffine::setXy(double value) {
    Xy = value;
    emit changed();
}
void AGFAffine::setYy(double value) {
    Yy = value;
    emit changed();
}
void AGFAffine::setMx(double value) {
    Mx = value;
    emit changed();
}
void AGFAffine::setMy(double value) {
    My = value;
    emit changed();
}
void AGFAffine::setMg(double value) {
    Mx = My = value;
    emit changed();
}
void AGFAffine::setInvertX(bool value) {
    invertX = value;
    emit changed();
}
void AGFAffine::setInvertY(bool value) {
    invertY = value;
    emit changed();
}

//--------------------------------------------------------------------------------//
/**
 * Методы-аксессоры get для полей
 */
qreal AGFAffine::getX0() const {
    return x0;
}
qreal AGFAffine::getY0() const {
    return y0;
}
qreal AGFAffine::getXx() const {
    return Xx;
}
qreal AGFAffine::getYx() const {
    return Yx;
}
qreal AGFAffine::getXy() const {
    return Xy;
}
qreal AGFAffine::getYy() const {
    return Yy;
}
qreal AGFAffine::getMx() const {
    return Mx;
}
qreal AGFAffine::getMy() const {
    return My;
}
bool AGFAffine::getInvertX() const {
    return invertX;
}
bool AGFAffine::getInvertY() const {
    return invertY;
}
