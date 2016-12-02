/** Kabuki Software Development Kit
    @file       /.../KabukiSDK-Impl/_Math/Complex.cpp
    @author  Cale McCollough <https://calemccollough.github.io>
    @license Copyright 2016 (C) Cale McCollough <cale.mccollough@gmail.com>

                          All right reserved (R).

        Licensed under the Apache License, Version 2.0 (the "License"); you may
        not use this file except in compliance with the License. You may obtain
        a copy of the License at

                http://www.apache.org/licenses/LICENSE-2.0

        Unless required by applicable law or agreed to in writing, software
        distributed under the License is distributed on an "AS IS" BASIS,
        WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
        See the License for the specific language governing permissions and
        limitations under the License.
*/

#include <_Math/Complex.hpp>

#include <_Math/Calc.hpp>
using namespace _Math;

namespace _Math {

Complex_f::Complex_f ()
{
    /// Nothing to do here! :-)
}

Complex_f::Complex_f (float a, float b)
:   a (a),
    b (b)
{
}

float Complex_f::calcAngle ()
{
    return atan (a/b);
}

float Complex_f::calcMagnitude ()
{
    return squareRoot (a * a + b * b);
}

void Complex_f::print (I2P::Terminal& slot)
{
}

//-----------------------------------------------------------------------------

Complex_d::Complex_d ()
{
    /// Nothing to do here! :-)
}

Complex_d::Complex_d (double a, double b)
:   a (a),
    b (b)
{
}

double Complex_d::calcAngle ()
{
    return atan (a/b);
}

double Complex_d::calcMagnitude ()
{
    return squareRoot (a * a + b * b);
}

void Complex_d::print (I2P::Terminal& slot)
{

}

}   //< namespace _Math
