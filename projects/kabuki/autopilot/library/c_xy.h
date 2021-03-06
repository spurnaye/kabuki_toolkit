/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki-toolkit.git
@file    /projects/kabuki/autopilot/xy.h
@author  Cale McCollough <cale.mccollough@gmail.com>
@license Copyright (C) 2014-19 Cale McCollough <cale@astartup.net>;
All right reserved (R). Licensed under the Apache License, Version 2.0 (the
"License"); you may not use this file except in compliance with the License.
You may obtain a copy of the License at www.apache.org/licenses/LICENSE-2.0.
Unless required by applicable law or agreed to in writing, software distributed
under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
CONDITIONS OF ANY KIND, either express or implied. See the License for the
specific language governing permissions and limitations under the License. */

#include <pch.h>
#ifndef INCLUDED_KABUKI_CRABS_XY
#define INCLUDED_KABUKI_CRABS_XY 1

namespace _ {

enum {
  kXYRight = 0,   //< Direction 0: Right @ 0 degrees.
  kXYUpperRight,  //< Direction 1: Upper Right @ 45 degrees.
  kXYUp,          //< Direction 2: Up @ 90 degrees.
  kXYUpperLeft,   //< Direction 3: Upper Left @ 135 degrees.
  kXYLeft,        //< Direction 4: Left @ 180 degrees.
  kXYLowerLeft,   //< Direction 5: Lower Left @ 225 degrees.
  kXYDown,        //< Direction 6: Down @ 270 degrees.
  kXYLowerRight,  //< Direction 7: Lower Right @ 315 degrees.
  kXYCenter,      //< Direction 7: Center @ i degrees.
};

/* 4-bit aligned Acronym strings for the directions.
@code
R, UR, U, LR, R, LR, D, LR
@endcode */
const CH1* XYDirectionAcronyms();

/* Decodes an XY quadrant packed in +/0/- format.
@param quad The quadrant.
@param value If value < 0 then only the lower angle node has been traversed. If
value == 0 then only the higher value node has been traversed. If value > 0 then
both nodes have been traversed. */
const CH1* XYDirectionString(SI4 direction);

const CH1* XYDirectionAcronyms();

void XYDirectionHistoryPrint(SI4 bits);

/* Gets the dx and dy values for the given direction.
@return DeltaX.
@param  a  The a-axis.
@param  dy DeltaY. */
SI4 XYVector(SI4 a, SI4& dy);

/* Gets the direction based on in the dx and dy.
@return A direction.
@param  dx Delta x.
@param  dy Delta y. */
SI4 XYDirection(SI4 dx, SI4 dy);

}  //< namespace _

#endif  //< #ifndef INCLUDED_KABUKI_CRABS_XY
