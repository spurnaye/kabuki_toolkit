/* Script^2 @version 0.x
@link    https://github.com/kabuki-starship/script2.git
@file    /kabuki/features/tek/global_config.inl
@author  Cale McCollough <cale.mccollough@gmail.com>
@license Copyright (C) 2014-2019 Cale McCollough <calemccollough.github.io>;
All right reserved (R). Licensed under the Apache License, Version 2.0 (the
"License"); you may not use this file except in compliance with the License.
You may obtain a copy of the License at www.apache.org/licenses/LICENSE-2.0.
Unless required by applicable law or agreed to in writing, software distributed
under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
CONDITIONS OF ANY KIND, either express or implied. See the License for the
specific language governing permissions and limitations under the License. */

#pragma once

#ifndef KABUKI_FEATURES_TEK_GLOBAL_CONFIG_INL
#define KABUKI_FEATURES_TEK_GLOBAL_CONFIG_INL 1
#include "../../script2/global_config.inl"

typedef UI1 offset_t;
typedef UI2 ch_t;

enum {
  // Number of bits to shift to get the UI1 offset.
  kBitToByteShift = sizeof (UI1) * 8,
  // Mask for the bit number, which is UI1.
  kBitNumberMask = 0xff,
};

#define _0_0_0__00 1   //< all
#define SEAM_N 17
#endif  //< #ifndef SCRIPT2_GLOBAL_INLINE_CONFIG
