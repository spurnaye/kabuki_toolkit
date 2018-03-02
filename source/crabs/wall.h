/** Kabuki Toolkit
    @version 0.x
    @file    ~/source/crabs/wall.h
    @author  Cale McCollough <cale.mccollough@gmail.com>
    @license Copyright (C) 2017-2018 Cale McCollough <calemccollough@gmail.com>;
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
#include <stdafx.h>

#ifndef CRABS_WALL_H
#define CRABS_WALL_H

#include "door.h"

#if MAJOR_SEAM >= 1 && MINOR_SEAM >= 4

#include "op.h"

namespace _ {

/** A singled contiguous buffer in a Chinese Room.
    Only one single wall is required for a Chinese Room, but when more memory 
    is needed a new Wall may be created and destroyed dynamically. This gives 
    the user .
    
    @code

    |==============|
    |  Terminals   |
    |      |       |
    |      v       |
    |==============|
    |    Buffer    |
    |==============|
    |      ^       |
    |      |       |
    |  TSTack of   |
    |    Doors     |
    |   Offsets    |
    |==============|
    |    Header    |
    |==============|


    @endcode
    
    */
class Wall : public Op {

    public:

    enum {
        kMinSizeBytes = 512, //< Min functional Wall size.
    };

    virtual ~Wall ();

    Wall (TStack<Door*>* doors);

    /** Constructs a wall from the given buffer. */
    Wall (size_t size_bytes = kMinSizeBytes);

    /** Constructs a wall from the given buffer. */
    Wall (uintptr_t* buffer, size_t size_bytes);

    /** Gets the size of the wall in bytes. */
    size_t GetSizeBytes ();

    /** Gets a pointer to the array of pointers to Door(string). */
    TStack<Door*>* Doors ();

    /** Gets the Door from the Door at the given index. */
    Door* GetDoor (int index);

    /** Adds a Door to the slot.
    @return Returns nil if the Door is full and a pointer to the Door in the
            buffer upon success. */
    int OpenDoor (Door* door);

    /** Deletes the Door from the Door at the given index. */
    bool CloseDoor (int index);

    /** Prints the given Door to the stdout. */
    _::Slot& Print (_::Slot& slot);

    private:

    bool           is_dynamic_; //< Flag for if using dynamic memory.
    size_t         size_bytes_; //< Size of the Wall in bytes.
    uintptr_t    * buffer_;     //< The Wall's buffer.
    TStack<Door*>* doors_;      //< The doors in the room.
};

}       //< namespace _
#endif  //< #if MAJOR_SEAM >= 1 && MINOR_SEAM >= 4
#endif  //< CRABS_WALL_H
