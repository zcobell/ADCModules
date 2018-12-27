/*------------------------------GPL---------------------------------------//
// This file is part of ADCIRCModules.
//
// (c) 2015-2018 Zachary Cobell
//
// ADCIRCModules is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// ADCIRCModules is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with ADCIRCModules.  If not, see <http://www.gnu.org/licenses/>.
//------------------------------------------------------------------------*/
#ifndef NODE_H
#define NODE_H

#include <string>
#include "adcircmodules_global.h"
#include "point.h"

namespace Adcirc {
namespace Geometry {

/**
 * @class Node
 * @author Zachary Cobell
 * @copyright Copyright 2018 Zachary Cobell. All Rights Reserved. This project
 * is released under the terms of the GNU General Public License v3
 * @brief The Node class describes the x, y, z position of a single mesh
 * node
 *
 */

class Node {
 public:
  ADCIRCMODULES_EXPORT Node();
  ADCIRCMODULES_EXPORT Node(size_t id, double x, double y, double z);

  void ADCIRCMODULES_EXPORT setNode(size_t id, double x, double y, double z);

  double ADCIRCMODULES_EXPORT x() const;
  void ADCIRCMODULES_EXPORT setX(double x);

  double ADCIRCMODULES_EXPORT y() const;
  void ADCIRCMODULES_EXPORT setY(double y);

  double ADCIRCMODULES_EXPORT z() const;
  void ADCIRCMODULES_EXPORT setZ(double z);

  size_t ADCIRCMODULES_EXPORT id() const;
  void ADCIRCMODULES_EXPORT setId(size_t id);

  std::string ADCIRCMODULES_EXPORT toAdcircString(bool geographicCoordinates);
  std::string ADCIRCMODULES_EXPORT to2dmString(bool geographicCoordinates);

  Point ADCIRCMODULES_EXPORT toPoint();

 private:
  size_t m_id;  /// Integer name of a mesh node
  double m_x;   /// x position of a node
  double m_y;   /// y position of a node
  double m_z;   /// z position of a node
};
}  // namespace Geometry
}  // namespace Adcirc
#endif  // NODE_H