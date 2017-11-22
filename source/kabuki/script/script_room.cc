/** kabuki::script
#include <script_room.h>
#include <script_operation.h>
#include <script_interrupts.h>
    @version 0.x
    @file    ~/source/kabuki/script/include/script_room.h
    @author  Cale McCollough <cale.mccollough@gmail.com>
    @license Copyright (C) 2017 Cale McCollough <calemccollough@gmail.com>;
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

#include <stdafx.h>
#include "../script/room.h"
#include "../script/door.h"
#include "../script/args.h"
#include "../script/text.h"

namespace _ {

const char** RoomStateStrings () {
    static const char* states[] = {
        "Initializing",
        "Waking up",
        "Running",
        "Going to sleep",
        "Exiting"
    };
    return states;
}

const char** RequestStrings () {
    static const char* RequestStrings[] = {
        "Open door",
        "Close door",
        "Invalid request"
    };

    return RequestStrings;
}

const char* RequestString (Request r) {
    //if (r < 0 || r >= InvalidRequest)
    if (r >= InvalidRequest)
        return RequestStrings ()[InvalidRequest];
    return RequestStrings ()[r];
}

Room::Room (const char* room_name) :
    name_       ((room_name == nullptr) ? "Unnamed" : room_name),
    this_       (nullptr),
    xoff_       (nullptr),
    device_     (nullptr),
    devices_    (nullptr) {
}

Room::~Room () {
}

Request Room::HandleNextRequest (Request r) {
    return InvalidRequest;
}

void Room::ClearLog () {

}

void Room::ProcessLog () {

}

void Room::PrintErrors (Bout* bout) {
    //uint_t errorHeader[] = { 0 };
    //return a.prints (errorHeader);
}

void Room::DiagnoseProblems () {
    // Check for remote crash request.
    //throw RoomCrashException ();
}

const Operation* Room::Init (Expression* expr) {
    if (expr != nullptr) {
        // @todo We need to load a stored Room state.
        return nullptr;
    }
    return nullptr;
}

void Room::ShutDown ()
{
    std::cout << "Shutting down...\n";
}

void Room::Sleep () {
    std::cout << "Going to sleep...\n";
}

void Room::Wake () {
    std::cout << "Waking up...\n";
}

void Room::Crash () {
    std::cout << "Room crash!\n";
}

const Operation* Room::Loop () { return 0; }

bool Room::IsOn () {
    return true;
}

int Room::Main (const char** args, int args_count) {
    const Operation* result;

    std::cout << "Initializing Chinese Room with " << args_count << " args:\n";
    for (int i = 0; i < args_count; ++i) {
        std::cout << i << ": " << args[i] << '\n';
    }
    std::cout << '\n';

    while (IsOn ()) {
        /*try {
            result = Init (nullptr);
            if (result)
                return 1;
            do {
                this_->ExecAll ();
                result = Loop ();
            } while (!result);
            ShutDown ();
        } catch (RoomCrashException e) {
            std::cout << "\n| Room crashed!\n";
            return 3;
        }*/
    }
    return 1;
}

const Operation* Room::Star (char_t index, Expression* expr) {
    static const Operation star = { "Room",
        NumOperations (0), FirstOperation (' '),
        "A Chinese Room.", 0
    };

    switch (index) {
        case '?': {
            return &star;
        }

    }
    return 0;
}

int_t Room::GetNumWalls () {
    return 0;
}

Wall* Room::GetWall (int_t wall_number) {
	if (wall_number < 0)
		return nullptr;
	if (wall_number >= walls_->count)
		return nullptr;
	return StackGet<Wall*> (walls_, wall_number);
}
Wall* Room::AddWall (Wall* new_wall) {
    if (new_wall == nullptr)
    	return nullptr;
    if (walls_->count >= walls_->height)
    	return nullptr;
    StackPush<Wall*> (walls_, new_wall);
    return new_wall;
}

bool Room::RemoveWall (int_t wall_number) {
	return StackRemove<Wall*> (walls_, wall_number);
}

uintptr_t Room::GetSizeBytes () {
	uintptr_t count = kFloorSize;
    for (int_t i = 0; i < walls_->count; ++i) {
    	count += StackGet<Wall*> (walls_, i)->GetSizeBytes ();
    }
    // @todo Add all memory we used in bytes here.
	return count;
}

void Room::Print () {
    PrintLine ();
    std::cout << "\n| Room: ";
}

Room* ChineseRoom (Room* room) {
    static Room* chinese_room = nullptr;
    if (room)
        chinese_room = room;
    return chinese_room;
}

}       //< namespace _