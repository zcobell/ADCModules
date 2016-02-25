/*-------------------------------GPL-------------------------------------//
//
// QADCModules - A library for working with ADCIRC models
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
#include "adcirc_node.h"

adcirc_node::adcirc_node(QObject *parent) : QObject(parent)
{

}


//-----------------------------------------------------------------------------------------//
//...Parses a line from the ADCIRC mesh that contains a node into
//   its positional information. Note that if the mesh needs re-numbering,
//   you will need to set ignoreMeshNumbering to true
//-----------------------------------------------------------------------------------------//
/** \brief Protected function to parse the string from an ADCIRC mesh file containing nodal information
 *
 * \author Zach Cobell
 *
 * @param line  [in]    The QString with the information read from the file to be parsed into an ADCIRC node
 *
 * This function can parse a single line from an ADCIRC mesh file to break it into the nodal information
 **/
//-----------------------------------------------------------------------------------------//
int adcirc_node::readNode(QString line)
{
    QStringList tempList;
    QString     tempString;
    int         tempInt;
    double      tempDouble;
    bool        err;

    tempList   = line.simplified().split(" ");
    tempString = tempList.value(0);
    tempInt    = tempString.toInt(&err);
    if(!err)
        return ADCMESH_MESHREAD_NODERR;
    this->id = tempInt;

    tempString = tempList.value(1);
    tempDouble = tempString.simplified().toDouble(&err);
    if(!err)
        return ADCMESH_MESHREAD_NODERR;
    this->x = tempDouble;
    tempString = tempList.value(2);
    tempDouble = tempString.simplified().toDouble(&err);
    if(!err)
        return ADCMESH_MESHREAD_NODERR;
    this->y = tempDouble;
    tempString = tempList.value(3);
    tempDouble = tempString.simplified().toDouble(&err);
    if(!err)
        return ADCMESH_MESHREAD_NODERR;
    this->z = tempDouble;

    return ADCMESH_NOERROR;
}
//-----------------------------------------------------------------------------------------//
