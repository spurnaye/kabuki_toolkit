/* Kabuki Tek
    @file    $kabuki-toolkit/kabuki_toolkit/app/event.h
    @author  Cale McCollough <calemccollough.github.io>
    @license Copyright (C) 2014-2017 Cale McCollough <calemccollough@gmail.com>;
             All right reserved (R). Licensed under the Apache License, Version 
             2.0 (the "License"); you may not use this file except in 
             compliance with the License. You may obtain a copy of the License 
             [here](http://www.apache.org/licenses/LICENSE-2.0). Unless 
             required by applicable law or agreed to in writing, software
             distributed under the License is distributed on an "AS IS" BASIS,
             WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or 
             implied. See the License for the specific language governing 
             permissions and limitations under the License.
*/

#pragma once
#include <pch.h>
#if MAJOR_SEAM >= 2 && MINOR_SEAM >= 1

namespace _ {

class IEvent
/*< Interface with an event.
    
    @code
    #include <_/IEvent.h>
    struct Example: public IEvent
    {
        virtual void Trigger ()
        {
            
        }
        
        virtual Print (Expression)
        {
            
        }
    };
    @endcode
*/
{
    public:
    
    virtual void Trigger () = 0;
    /*< Triggers the event. */

    virtual void Print (Expression& slot) = 0;
    /*< Prints this object to the terminal. */
};

}       //< namespace _
#endif  //< KABUKI_TOOLKIT_APP_EVENT
#endif  //< #if MAJOR_SEAM >= 2 && MINOR_SEAM >= 1
