/* Kabuki Toolkit
@version 0.x
@file    $kabuki-toolkit/kabuki/crabs/clock.h
@author  Cale McCollough <cale.mccollough@gmail.com>
@license Copyright (C) 2014-8 Cale McCollough <calemccollough@gmail.com>;
@license Copyright (C) 2014-2017 Cale McCollough <calemccollough.github.io>;
All right reserved (R). Licensed under the Apache License, Version 2.0 (the
"License"); you may not use this file except in compliance with the License.
You may obtain a copy of the License at www.apache.org/licenses/LICENSE-2.0.
Unless required by applicable law or agreed to in writing, software distributed
under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
CONDITIONS OF ANY KIND, either express or implied. See the License for the
specific language governing permissions and limitations under the License. */

#pragma once
#include <stdafx.h>
#if SEAM_MAJOR > 0 || SEAM_MAJOR == 0 && SEAM_MINOR >= 2
#ifndef HEADER_FOR_CRABS_CLOCK
#define HEADER_FOR_CRABS_CLOCK
// Dependencies:
#include "config.h"
// End dependencies.

namespace _ {

HANDLE done_event;

VOID CALLBACK TimerRoutine(PVOID lpParam, BOOLEAN TimerOrWaitFired) {
    if (!lpParam) {
        printf("TimerRoutine lpParam is NULL\n");
    }
    else {
        // lpParam points to the argument; in this case it is an int

        printf ("Timer routine called. Parameter is %d.\n",
                *(int*)lpParam);
        if(TimerOrWaitFired) {
            printf("The wait timed out.\n");
        }
        else {
            printf("The wait event was signaled.\n");
        }
    }

    SetEvent(done_event);
}

int main() {
    HANDLE hTimer = NULL;
    HANDLE hTimerQueue = NULL;
    int arg = 123;

    // Use an event object to track the TimerRoutine execution
    done_event = CreateEvent(NULL, TRUE, FALSE, NULL);
    if (NULL == done_event)
    {
        printf("CreateEvent failed (%d)\n", GetLastError());
        return 1;
    }

    // Create the timer queue.
    hTimerQueue = CreateTimerQueue();
    if (NULL == hTimerQueue)
    {
        printf("CreateTimerQueue failed (%d)\n", GetLastError());
        return 2;
    }

    // Set a timer to call the timer routine in 10 seconds.
    if (!CreateTimerQueueTimer( &hTimer, hTimerQueue,
            (WAITORTIMERCALLBACK)TimerRoutine, &arg , 10000, 0, 0))
    {
        printf("CreateTimerQueueTimer failed (%d)\n", GetLastError());
        return 3;
    }

    // TODO: Do other useful work here

    printf("Call timer routine in 10 seconds...\n");

    // Wait for the timer-queue thread to complete using an event
    // object. The thread will signal the event at that time.

    if (WaitForSingleObject(done_event, INFINITE) != WAIT_OBJECT_0)
        printf("WaitForSingleObject failed (%d)\n", GetLastError());

    CloseHandle(done_event);

    // Delete all timers in the timer queue.
    if (!DeleteTimerQueue(hTimerQueue))
        printf("DeleteTimerQueue failed (%d)\n", GetLastError());

    return 0;
}

}  // namespace _

#endif  //< #if SEAM_MAJOR > 0 || SEAM_MAJOR == 0 && SEAM_MINOR >= 5
#endif  //< HEADER_FOR_HAL_TIMER
