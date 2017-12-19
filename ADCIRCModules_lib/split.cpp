//------------------------------------------------------------------------//
// This file is part of Vortex.
//
// Vortex is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Vortex is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Vortex.  If not, see <http://www.gnu.org/licenses/>.
//------------------------------------------------------------------------//
#include "split.h"

void split::stringSplit(const std::string &s, char delim,
                        std::vector<std::string> &elems) {
  std::stringstream ss;
  ss.str(s);
  std::string item;
  while (getline(ss, item, delim)) {
    if (item != "" && item != " " && item != "\r")
      elems.push_back(item);
  }
}

std::vector<std::string> split::stringSplitToVector(const std::string &s,
                                                    char delim) {
  std::vector<std::string> elems;
  split::stringSplit(s, delim, elems);
  return elems;
}