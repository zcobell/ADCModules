/*-------------------------------GPL-------------------------------------//
//
// adcircmodules - A library for working with ADCIRC models
// Copyright (C) 2016  Zach Cobell
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
//-----------------------------------------------------------------------*/
/**
 * \class QKdtree2
 *
 * \brief Class that serves as an interface to the kdtree2 library
 *
 * This function serves as the C++ interface to the kdtree2 library. Kdtree2
 * requires the boost library headers that are included with this code. This
 * implementatin
 * currently only supports 2-dimensional searches, though the kd-tree library
 * this interfaces with does not have such a limitation
 *
 * \author Zach Cobell
 *
 * Contact: zcobell@gmail.com
 *
 */
#ifndef QKDTREE2_H
#define QKDTREE2_H

#include <QObject>
#include <QPointF>
#include <QSharedPointer>
#include <QVector>

#ifdef QT_GUI_LIB
#include <QVector3D>
#endif

class kdtree2;

class QKdtree2 : public QObject {
  Q_OBJECT
public:
  enum _errors { NoError, SizeMismatch };

  explicit QKdtree2(QObject *parent = 0);

  int build(QVector<QPointF> &pointCloud);
  int build(QVector<qreal> &x, QVector<qreal> &y);
#ifdef QT_GUI_LIB
  int build(QVector<QVector3D> &pointCloud);
#endif

  int findNearest(QPointF pointLocation, int &index);
  int findNearest(qreal x, qreal y, int &index);

#ifdef QT_GUI_LIB
  int findNearest(QVector3D pointLocation, int &index);
#endif

  int findXNearest(QPointF pointLocation, int nn, QVector<int> &indicies);
  int findXNearest(qreal x, qreal y, int nn, QVector<int> &indicies);

#ifdef QT_GUI_LIB
  int findXNearest(QVector3D pointLocation, int nn, QVector<int> &indicies);
#endif

  int size() const;

  bool isInitialized() const;

private:
  /// Variable holding the total number of points in the search tree
  int m_numDataPoints;

  /// Variable that ensures the search tree is initialized
  bool m_initialized;

  /// Pointer to variable holding the kdtree search tree
  QSharedPointer<kdtree2> m_tree;
};

#endif // QKDTREE2_H