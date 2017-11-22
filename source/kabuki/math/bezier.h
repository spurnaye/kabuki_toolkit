/** Kabuki Starship
    @file    /.../Source/_Math/Bezier.h
    @author  Cale McCollough
    @author  Cale McCollough <cale.mccollough@gmail.com>
    @license Copyright (C) 2017 Cale McCollough <https://calemccollough.github.io>

                            All right reserved  (R).

        Licensed under the Apache License, Version 2.0  (the "License"); you may
        not use this file except in compliance with the License. You may obtain
        a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

        Unless required by applicable law or agreed to in writing, software
        distributed under the License is distributed on an "AS IS" BASIS,
        WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
        See the License for the specific language governing permissions and
        limitations under the License.
*/

#pragma once


#include <KabukiTheater-Config.h>

#include "Point.h"

#include <vector>
#include <string>
#include <memory>

namespace _Math {

class _KabukiTheater_ Bezier_f
/*< Class that represents a n order Bezier. */
{
    public:

    enum { 
        MinmumNumPoints = 3     //< The minimum number of points reqruied for a bezier curve.
    };

    Bezier_f  (float* initXPoints, float* initYPoints, int initNumPoints);
    /*< Constructor.
    @pre The length of XPoints and YPoints must equal NumPoints or curve will not be created correctly. */

    Bezier_f  (const float* initXPoints, const float* initYPoints, int initNumPoints);
    /*< Constructor.
        @pre The length of XPoints and YPoints must equal NumPoints or curve will not be created correctly. */

    Bezier_f  (float initX0, float initY0, float initX1, float initY1, float initX2, float initY2, float initX3, float initY3);
    /*< Constructs a quadratic bezier curve with the given points. */

    Bezier_f  (const Bezier_f& o);
    /*< Copy constructor initializes curve with the given points. */

    ~Bezier_f ();
    /*< Destructs dynamic memory if used. */

    float* getXPoints ();
    /*< Retuns a pointer to the x points. */

    float* getYPoints ();
    /*< Retuns a pointer to the y points. */

    int getNumPoints ();
    /*< Gets the number of points. */

    Point<float> getPoint  (float P);
    /*< Gets a Point<float> along the path of the of curve at time t. */

    inline void print (Expression& io);
    /*< Prints this object to the terminal. */

    private:

    float* xPoints,                 //< Array of X points.
        * yPoints;                  //< Array of Y points.

    int numPoints;                  //< The number of points in the polygon.
};

}   //  _Math