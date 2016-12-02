/** Kabuki Software Development Kit
    @file    /.../KabukiSDK-Impl/_Id/Privilage.cpp
    @author  Cale McCollough <cale.mccollough@gmail.com>
    @license Copyright (C) 2016 [Cale McCollough](calemccollough.github.io)

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

#include <_Id/Privilage.hpp>

namespace _Id {

static PrivilageLevel minPrivailageLevel,
    maxPrivilageLevel;

PrivilageLevel getMinPrivilageLevel ()
{
    return minPrivilageLevel;
}

PrivilageLevel setMinPrivilageLevel ()
{
    return maxPrivilageLevel;
}

bool setPrvilageLevelRange (PrivilageLevel min, PrivilageLevel max)
{

}

Privilage::Privilage ()
{

}

PrivilageLevel Privilage::getPrivilageLevel ()
{
    return privilageLevel;
}

bool Privilage::setPrivilageLevel (PrivilageLevel l)
{
    if (l < minPrivilageLevel) return false;
    privilageLevel = l;
}

void Privilage::print (Terminal& slot)

}   //< namespace _Id
