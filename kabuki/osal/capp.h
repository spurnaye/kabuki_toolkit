/* Kabuki Toolkit
    @file    $kabuki-toolkit/kabuki_toolkit/app/app.h
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

#ifndef KABUKI_TOOLKIT_APP
#define KABUKI_TOOLKIT_APP

#include "config.h"

namespace _ {

/* Interface for an Kabuki Starship app.
*/
struct App {
    /*
    const SI4 MaxWindows = 256;
        
    uint32_t UID;
    numWindows;
        
    Window windows[];
    Window activeWindow;
    */
    
    /* Initializer. */
    virtual void Initialize () = 0;
        
    /* Returns the process ID of this App. */
    virtual uint32_t GetUID () = 0;

    /* Sets the activeWindow to the new index. */
    virtual SI4 ActivateWindow (SI4 i) = 0;
        
    /* Sets the activeWindow to the new window. */
    virtual SI4 ActivateWindow (Window w) = 0;

    /*  */
    virtual ProcessTree GetWindows () = 0;

    /*  */
    virtual SI4 Show () = 0;
        
    /*  */
    virtual SI4 Hide () = 0;
        
    /*  */
    virtual SI4 Close () = 0;

    /* Returns a link to this application's osal context. */
    virtual _g::Cell& GetDrawCell () = 0;
        
    /*  */
    virtual void Draw (_g::Cell& c) = 0;
        
    /*  */
    virtual void Redraw () = 0;
        
    /* Prints this object to a Expression.  */
    virtual void Print () = 0;
};      //< struct App

}       //< namespace _
#endif  //< KABUKI_TOOLKIT_APP_APP
#endif  //< #if MAJOR_SEAM >= 2 && MINOR_SEAM >= 1
