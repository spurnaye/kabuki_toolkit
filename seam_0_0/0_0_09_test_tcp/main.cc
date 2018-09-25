/* Kabuki Toolkit
@file    ~/tests/tests_main.cc
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

#include <stdafx.h>


int main(int args_count, char** args) {
    return 0;
}

/*
HANDLE gDoneEvent;

VOID CALLBACK TimerRoutine (PVOID lpParam, BOOLEAN TimerOrWaitFired) {
    if (lpParam == NULL) {
        Printf ("TimerRoutine lpParam is NULL\n");
    }
    else
    {
        // lpParam points to the argument; in this case it is an int

        Printf ("Timer routine called. Parameter is %d.\n",
                *(int*)lpParam);
        if (TimerOrWaitFired) {
            Printf ("The wait timed out.\n");
        }
        else
        {
            Printf ("The wait event was signaled.\n");
        }
    }

    SetEvent (gDoneEvent);
}
int main () {
    HANDLE hTimer = NULL;
    HANDLE hTimerQueue = NULL;
    int arg = 123;

    // Use an event object to track the TimerRoutine execution
    gDoneEvent = CreateEvent (NULL, TRUE, FALSE, NULL);
    if (!gDoneEvent) {
        Printf ("CreateEvent failed (%d)\n", GetLastError ());
        return 1;
    }

    // Create the timer queue.
    hTimerQueue = CreateTimerQueue ();
    if (hTimerQueue) {
        Printf ("CreateTimerQueue failed (%d)\n", GetLastError ());
        return 2;
    }

    // Set a timer to call the timer routine in 10 seconds.
    if (!CreateTimerQueueTimer (&hTimer, hTimerQueue,
        (WAITORTIMERCALLBACK)TimerRoutine, &arg, 10000, 0, 0)) {
        Printf ("CreateTimerQueueTimer failed (%d)\n", GetLastError ());
        return 3;
    }

    // TODO: Do other useful work here

    Printf ("Call timer routine in 10 seconds...\n");

    // Wait for the timer-queue thread to complete using an event
    // object. The thread will signal the event at that time.

    if (WaitForSingleObj (gDoneEvent, INFINITE) != WAIT_OBJECT_0)
        Printf ("WaitForSingleObj failed (%d)\n", GetLastError ());

    CloseHandle (gDoneEvent);

    // Delete all timers in the timer queue.
    if (!DeleteTimerQueue (hTimerQueue))
        Printf ("DeleteTimerQueue failed (%d)\n", GetLastError ());
}
*/
