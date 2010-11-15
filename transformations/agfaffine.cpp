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
void AGFAffine::setX0(qreal value) {
    x0 = value;
}
void AGFAffine::setY0(qreal value) {
    y0 = value;
}
void AGFAffine::setXx(qreal value) {
    Xx = value;
}
void AGFAffine::setYx(qreal value) {
    Yx = value;
}
void AGFAffine::setXy(qreal value) {
    Xy = value;
}
void AGFAffine::setYy(qreal value) {
    Yy = value;
}
void AGFAffine::setMx(qreal value) {
    Mx = value;
}
void AGFAffine::setMy(qreal value) {
    My = value;
}
void AGFAffine::setMg(qreal value) {
	Mx = My = value;
}
void AGFAffine::setInvertX(bool value) {
    invertX = value;
}
void AGFAffine::setInvertY(bool value) {
    invertY = value;
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
