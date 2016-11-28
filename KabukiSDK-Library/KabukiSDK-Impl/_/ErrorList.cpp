/** Kabuki Software Development Kit
    @file    /.../_/ErrorList.cpp
    @author  Cale McCollough <cale.mccollough@gmail.com>
    @license Copyright  (C) 2016 [Cale McCollough](calemccollough.github.io)

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

#include <_/ErrorList.hpp>

namespace _ {

ErrorList::ErrorList (char** errorBuffer, int maximumNumErrors)
:   numErrors  (0),
    maxNumErrors (maximumNumErrors < 0 ? DefaultNumErrors : maximumNumErrors)
{
    /// Nothing to do here! :-)
}

void ErrorList::clear () { numErrors = 0; }

unsigned int ErrorList::getNumErrors () { return numErrors; }

void ErrorList::report  (const char* s)
{
    if  (numErrors >= MaxNumErrors) return;
    errors[numErrors++] = s;
    return this;
}
    
ErrorList& operator +=  (const char* s)
{
    report  (s);
    return this;
}

const char* ErrorList::getErrors () { return errors; }
    
void ErrorList::print (I2P::Terminal& slot)
{
    for  (int i = 0; i < numErrors; ++i)
        printLine (errors[i]);
}

}   //< namespace _