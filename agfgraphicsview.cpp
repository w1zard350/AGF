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
#include "agfgraphicsview.h"
#include "agfgraphicsitem.h"
#include "transformations/agfaffine.h"
#include "transformations/agfeuclidean.h"
#include "transformations/agfprojective.h"
#include <cmath>
#include <QDebug>
using namespace std;
AGFGraphicsView::AGFGraphicsView(QWidget* parent): QGraphicsView(parent) {
    // создаем и настраиваем сцену
    QGraphicsScene* scene = new QGraphicsScene();
    setScene(scene);
    reconfigure();

    affine = new AGFAffine();
    euclidean = new AGFEuclidean();
    projective = new AGFProjective();

    setBgColor(Qt::gray);
    setBackgroundBrush(bgColor);

    setEuclideanEnabled(false);
    setAffineEnabled(false);
    setProjectiveEnabled(false);

    setCenter(QPointF(0,0));
}

void AGFGraphicsView::addItem(AGFGraphicsItem* item) {
    item->setGraphicsView(this);
    scene()->addItem(item);
}

void AGFGraphicsView::resizeEvent(QResizeEvent* event) {
    reconfigure();
    scene()->update();
    QGraphicsView::resizeEvent(event);
}

void AGFGraphicsView::wheelEvent(QWheelEvent* event) {
    if(event->delta() > 0) emit zoomedIn();
    else emit zoomedOut();
    QGraphicsView::wheelEvent(event);
}

void AGFGraphicsView::reconfigure() {
    scene()->setSceneRect(QRectF(0, 0, width()-5, height()-5));
}

QPointF AGFGraphicsView::tc(QPointF point) {

    // эвклидовые преобразования
    if(euclideanEnabled) {
        point = euclidean->shift(point);
        point = euclidean->rotate(point);
    }

    // аффинные преобразования
    if(affineEnabled) {
        point = affine->scale(point);
        point = affine->transform(point);
    }

    // проективные преобразования
    if(projectiveEnabled) {
        point = projective->transform(point);
    }

    // смещение центра сцены
    point += center;

    // преобразование математической (мировой) системы координат (МСК) в экранную систему координат (ЭСК)
    point.setX(point.x() + width()/2);
    point.setY(-point.y() + height()/2);

    return point;
}
//--------------------------------------------------------------------------------//
/**
 * Методы-аксессоры set для полей
 */
void AGFGraphicsView::setAffine(AGFAffine* value) {
    affine = value;
}
void AGFGraphicsView::setEuclidean(AGFEuclidean* value) {
    euclidean = value;
}
void AGFGraphicsView::setProjective(AGFProjective* value) {
    projective = value;
}
void AGFGraphicsView::setBgColor(Qt::GlobalColor value) {
    setBackgroundBrush(value);
    bgColor = value;
    scene()->update();
}
void AGFGraphicsView::setEuclideanEnabled(bool value) {
    euclideanEnabled = value;
    scene()->update();
}
void AGFGraphicsView::setAffineEnabled(bool value) {
    affineEnabled = value;
    scene()->update();
}
void AGFGraphicsView::setProjectiveEnabled(bool value) {
    projectiveEnabled = value;
    scene()->update();
}
void AGFGraphicsView::setMx(double value) {
    affine->setMx(value);
    scene()->update();
}
void AGFGraphicsView::setMy(double value) {
    affine->setMy(value);
    scene()->update();
}
void AGFGraphicsView::setMg(double value) {
    affine->setMg(value);
    scene()->update();
}
void AGFGraphicsView::setAlphaDegree(double value) {
    euclidean->setAlpha(value*M_PI/180);
    scene()->update();
}
void AGFGraphicsView::setBetaDegree(double value) {
    euclidean->setBeta(value*M_PI/180);
    scene()->update();
}
void AGFGraphicsView::setGammaDegree(double value) {
    euclidean->setGamma(value*M_PI/180);
    scene()->update();
}
void AGFGraphicsView::setXShift(double value) {
    euclidean->setXShift(value);
    scene()->update();
}
void AGFGraphicsView::setYShift(double value) {
    euclidean->setYShift(value);
    scene()->update();
}
void AGFGraphicsView::setAffineXx(double value) {
    affine->setXx(value);
    scene()->update();
}
void AGFGraphicsView::setAffineYx(double value) {
    affine->setYx(value);
    scene()->update();
}
void AGFGraphicsView::setAffineXy(double value) {
    affine->setXy(value);
    scene()->update();
}
void AGFGraphicsView::setAffineYy(double value) {
    affine->setYy(value);
    scene()->update();
}
void AGFGraphicsView::setAffineX0(double value) {
    affine->setX0(value);
    scene()->update();
}
void AGFGraphicsView::setAffineY0(double value) {
    affine->setY0(value);
    scene()->update();
}
void AGFGraphicsView::setProjectiveXx(double value) {
    projective->setXx(value);
    scene()->update();
}
void AGFGraphicsView::setProjectiveYx(double value) {
    projective->setYx(value);
    scene()->update();
}
void AGFGraphicsView::setProjectiveXy(double value) {
    projective->setXy(value);
    scene()->update();
}
void AGFGraphicsView::setProjectiveYy(double value) {
    projective->setYy(value);
    scene()->update();
}
void AGFGraphicsView::setProjectiveX0(double value) {
    projective->setX0(value);
    scene()->update();
}
void AGFGraphicsView::setProjectiveY0(double value) {
    projective->setY0(value);
    scene()->update();
}
void AGFGraphicsView::setProjectiveW0(int value) {
    projective->setW0(value);
    scene()->update();
}
void AGFGraphicsView::setProjectiveWx(double value) {
    projective->setWx(value);
    scene()->update();
}
void AGFGraphicsView::setProjectiveWy(double value) {
    projective->setWy(value);
    scene()->update();
}
void AGFGraphicsView::setCenter(QPointF value) {
    center = value;
    scene()->update();
}
void AGFGraphicsView::setCenterX(double value) {
    center.setX(value);
    scene()->update();
}
void AGFGraphicsView::setCenterY(double value) {
    center.setY(value);
    scene()->update();
}
//--------------------------------------------------------------------------------//
/**
 * Методы-аксессоры get для полей
 */
AGFAffine* AGFGraphicsView::getAffine() const {
    return affine;
}
AGFEuclidean* AGFGraphicsView::getEuclidean() const {
    return euclidean;
}
AGFProjective* AGFGraphicsView::getProjective() const {
    return projective;
}
Qt::GlobalColor AGFGraphicsView::getBgColor() const {
    return bgColor;
}
bool AGFGraphicsView::getEuclideanEnabled() const {
    return euclideanEnabled;
}
bool AGFGraphicsView::getAffineEnabled() const {
    return affineEnabled;
}
bool AGFGraphicsView::getProjectiveEnabled() const {
    return projectiveEnabled;
}
QPointF AGFGraphicsView::getCenter() const {
    return center;
}

