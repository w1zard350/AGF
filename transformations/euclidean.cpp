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
#include "euclidean.h"
#include <cmath>
using namespace std;
Euclidean::Euclidean()
{
    setXShift(0);
    setYShift(0);

    setAlpha(0);
    setBeta(0);
    setGamma(0);
}

QPointF Euclidean::shift(QPointF point) {
    point.setX(point.x() + xShift);
    point.setY(point.y() + yShift);
    return point;
}

QPointF Euclidean::rotate(QPointF point) {
    qreal x = point.x();
    qreal y = point.y();

    qreal x_ = x*cos(alpha)*cos(beta) + y*(cos(alpha)*sin(beta)*sin(gamma) - sin(alpha)*cos(gamma));
    qreal y_ = x*cos(beta)*sin(alpha) + y*(sin(alpha)*sin(beta)*sin(gamma) + cos(alpha)*cos(gamma));

    point.setX(x_);
    point.setY(y_);
    return point;
}

//--------------------------------------------------------------------------------//
/**
 * Методы-аксессоры set для полей
 */
void Euclidean::setXShift(qreal value) {
    xShift = value;
}
void Euclidean::setYShift(qreal value) {
    yShift = value;
}
void Euclidean::setAlpha(qreal value) {
    alpha = value;
}
void Euclidean::setBeta(qreal value) {
    beta = value;
}
void Euclidean::setGamma(qreal value) {
    gamma = value;
}
//--------------------------------------------------------------------------------//
/**
 * Методы-аксессоры get для полей
 */
qreal Euclidean::getXShift() const {
    return xShift;
}
qreal Euclidean::getYShift() const {
    return yShift;
}
qreal Euclidean::getAlpha() const {
    return alpha;
}
qreal Euclidean::getBeta() const {
    return beta;
}
qreal Euclidean::getGamma() const {
    return gamma;
}
