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

AGFGraphicsView::AGFGraphicsView(QWidget* parent)
{
    Q_UNUSED(parent);
    // создаем и настраиваем сцену
    QGraphicsScene* scene = new QGraphicsScene();
    scene->setSceneRect(QRectF(0, 0, width(), height()));
    setScene(scene);
}

