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
#ifndef AGFGRAPHICSVIEW_H
#define AGFGRAPHICSVIEW_H
#include <QGraphicsView>
#include "agfgrid.h"
/**
 * Класс виджета для рисования.
 */
class AGFgraphicsView: public QGraphicsView
{
public:
    AGFgraphicsView(QWidget* parent = 0);

    /**
     * Добавляет новый элемент (объект для прорисовки) в сцену
     */
    void addItem(AGFgraphicsItem* item);
    /**
     * Пересчитывает параметры сцены и вносит изменения в виджет для рисования View
     */
    void reconfigure();
    //--------------------------------------------------------------------------------//
    /**
     * События
     */
    void resizeEvent(QResizeEvent* event);
};

#endif // AGFGRAPHICSVIEW_H
