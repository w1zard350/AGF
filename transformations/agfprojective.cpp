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
#include "agfprojective.h"

AGFProjective::AGFProjective() {
    setX0(0);
    setY0(0);

    setXx(600); setYx(0);
    setXy(0); setYy(600);

    setW0(400);
    setWx(1);
    setWy(1);
}

QPointF AGFProjective::transform(QPointF point) {
    qreal x = point.x();
    qreal y = point.y();

    qreal n=0, m=0, x_=0, y_=0;

    n = x0*W0 + Xx*Wx*x + Xy*Wy*y;
    m = W0 + Wx*x + Wy*y;
    x_ = n/m;

    n = y0*W0 + Yx*Wx*x + Yy*Wy*y;
    y_ = n/m;

    point.setX(x_);
    point.setY(y_);
    return point;
}

//--------------------------------------------------------------------------------//
/**
 * Методы-аксессоры set для полей
 */
void AGFProjective::setX0(qreal value) {
    x0 = value;
}
void AGFProjective::setY0(qreal value) {
    y0 = value;
}
void AGFProjective::setXx(qreal value) {
    Xx = value;
}
void AGFProjective::setYx(qreal value) {
    Yx = value;
}
void AGFProjective::setXy(qreal value) {
    Xy = value;
}
void AGFProjective::setYy(qreal value) {
    Yy = value;
}
void AGFProjective::setW0(qreal value) {
    W0 = value;
}
void AGFProjective::setWx(qreal value) {
    Wx = value;
}
void AGFProjective::setWy(qreal value) {
    Wy = value;
}

//--------------------------------------------------------------------------------//
/**
 * Методы-аксессоры get для полей
 */
qreal AGFProjective::getX0() const {
    return x0;
}
qreal AGFProjective::getY0() const {
    return y0;
}
qreal AGFProjective::getXx() const {
    return Xx;
}
qreal AGFProjective::getYx() const {
    return Yx;
}
qreal AGFProjective::getXy() const {
    return Xy;
}
qreal AGFProjective::getYy() const {
    return Yy;
}
qreal AGFProjective::getW0() const {
    return W0;
}
qreal AGFProjective::getWx() const {
    return Wx;
}
qreal AGFProjective::getWy() const {
    return Wy;
}
