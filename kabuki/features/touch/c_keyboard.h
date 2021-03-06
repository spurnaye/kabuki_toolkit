/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki-toolkit.git
@file    /kabuki/features/touch/c_keyboard.cc
@author  Cale McCollough <https://calemccollough.github.io>
@license Copyright (C) 2014-19 Cale McCollough <cale@astartup.net>;
All right reserved (R). Licensed under the Apache License, Version 2.0 (the
"License"); you may not use this file except in compliance with the License.
You may obtain a copy of the License at www.apache.org/licenses/LICENSE-2.0.
Unless required by applicable law or agreed to in writing, software distributed
under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
CONDITIONS OF ANY KIND, either express or implied. See the License for the
specific language governing permissions and limitations under the License. */

#pragma once
#include <pch.h>
#if SEAM >= KABUKI_TEK_1
namespace _ {

/* A computer keyboard.
 */
class CKeyboard {
  enum {
    DefaultBufferSize = 256,    //< The default buffer size.
    MinBufferSize = 64,         //< Min buffer size.
    MaxBufferSize = 1024 * 10,  //< Max buffer size.
  };

  /* Default constructor. **/
  CKeyboard(SI4 a = DefaultBufferSize) {
    if (a < MinBufferSize)
      bufferSize = MinBufferSize;
    else if (a > MaxBufferSize)
      bufferSize = MaxBufferSize;
    else
      bufferSize = a;

    start = stop = begin;
  }

  /* Resets the event buffer. */
  void Clear() { start = stop = begin; }

  /* Inserts an event into the buffer. */
  void Insert(Event a) {
    if (stop + 1 > end) {
      Debug.Assert(start != begin, "Insert  (byte): Buffer overflow.");
      stop = begin;
      buffer[stop] = a;
    }
    Debug.Assert(stop + 1 == start, "Insert  (byte): Buffer overflow.");

    buffer[++stop] = a;
  }

  /* Updates the  */
  void Update() {
    if (start > stop) {
      for (SI4 i = start; i <= end; ++i) buffer[i]();
      for (SI4 i = begin; i <= stop; ++i) buffer[i]();
      start = stop = begin;
      return;
    }

    for (SI4 i = start; i <= end; ++i) buffer[i]();
    start = stop = begin;
  }

 private:
  SI4 begin,       //< The begning of the
      end,         //< The end of the
      start,       //< The start of the events.
      stop,        //< The stop of the events.
      bufferSize;  //< The buffer size.

  CKeyEvent buffer[];  //< An ring-buffer of real-time events from the keyboard.
};                    //< CKeyboard
}  // namespace _
}  //< namespace _ {tek
#endif  //< #if SEAM >= KABUKI_TEK_1
