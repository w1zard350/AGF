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
#include "transformations/affine.h"
#include "transformations/euclidean.h"
#include "transformations/projective.h"
#include <cmath>
#include <QDebug>
using namespace std;
AGFgraphicsView::AGFgraphicsView(QWidget* parent): QGraphicsView(parent) {
    // создаем и настраиваем сцену
    QGraphicsScene* scene = new QGraphicsScene();
    setScene(scene);
    reconfigure();
    affine = new Affine();
    euclidean = new Euclidean();
    projective = new Projective();
    setBgColor(Qt::gray);
    setBackgroundBrush(bgColor);
    setEuclideanEnabled(false);
    setAffineEnabled(false);
    setProjectiveEnabled(false);
}

void AGFgraphicsView::addItem(AGFgraphicsItem* item) {
    item->setGraphicsView(this);
    scene()->addItem(item);
}

void AGFgraphicsView::resizeEvent(QResizeEvent* event) {
    Q_UNUSED(event);
    reconfigure();
    scene()->update();
}

void AGFgraphicsView::reconfigure() {
    scene()->setSceneRect(QRectF(0, 0, width(), height()));
}

QPointF AGFgraphicsView::tc(QPointF point) {

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

    // преобразование математической (мировой) системы координат (МСК) в экранную систему координат (ЭСК)
    point.setX(point.x() + width()/2);
    point.setY(-point.y() + height()/2);

    return point;
}
//--------------------------------------------------------------------------------//
/**
 * Методы-аксессоры set для полей
 */
void AGFgraphicsView::setAffine(Affine* value) {
    affine = value;
}
void AGFgraphicsView::setEuclidean(Euclidean* value) {
    euclidean = value;
}
void AGFgraphicsView::setProjective(Projective* value) {
    projective = value;
}
void AGFgraphicsView::setBgColor(Qt::GlobalColor value) {
    setBackgroundBrush(value);
    bgColor = value;
    scene()->update();
}
void AGFgraphicsView::setEuclideanEnabled(bool value) {
    euclideanEnabled = value;
    scene()->update();
}
void AGFgraphicsView::setAffineEnabled(bool value) {
    affineEnabled = value;
    scene()->update();
}
void AGFgraphicsView::setProjectiveEnabled(bool value) {
    projectiveEnabled = value;
    scene()->update();
}
void AGFgraphicsView::setMx(double value) {
    affine->setMx(value);
    scene()->update();
}
void AGFgraphicsView::setMy(double value) {
    affine->setMy(value);
    scene()->update();
}
//--------------------------------------------------------------------------------//
/**
 * Методы-аксессоры get для полей
 */
Affine* AGFgraphicsView::getAffine() const {
    return affine;
}
Euclidean* AGFgraphicsView::getEuclidean() const {
    return euclidean;
}
Projective* AGFgraphicsView::getProjective() const {
    return projective;
}
Qt::GlobalColor AGFgraphicsView::getBgColor() const {
    return bgColor;
}
bool AGFgraphicsView::getEuclideanEnabled() const {
    return euclideanEnabled;
}
bool AGFgraphicsView::getAffineEnabled() const {
    return affineEnabled;
}
bool AGFgraphicsView::getProjectiveEnabled() const {
    return projectiveEnabled;
}
qreal AGFgraphicsView::getMx() const {
    return affine->getMx();
}
qreal AGFgraphicsView::getMy() const {
    return affine->getMy();
}


