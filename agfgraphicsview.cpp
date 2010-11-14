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
#include "affine.h"
AGFgraphicsView::AGFgraphicsView(QWidget* parent) {
    Q_UNUSED(parent);
    // создаем и настраиваем сцену
    QGraphicsScene* scene = new QGraphicsScene();
    setScene(scene);
    reconfigure();
    affine = new Affine();
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

    // аффинные преобразования
    point = affine->scale(point);
    point = affine->transform(point);

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
//--------------------------------------------------------------------------------//
/**
 * Методы-аксессоры get для полей
 */
Affine* AGFgraphicsView::getAffine() const {
    return affine;
}


