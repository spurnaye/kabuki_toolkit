/** Kabuki Toolkit
    @version 0.x
    @file    ~/source/script/script_hash.cc
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

#include "hash.h"

namespace _ {

hash16_t Hash16 (const char* string, hash16_t hash) {
    byte c = *string;
    while (c) {
        hash = Hash16 (c, hash);
        ++string;
        c = *string;
    }
    return hash;
}

hash16_t Hash32 (const char* string, hash32_t hash) {
    byte c = *string;
    while (c) {
        hash = Hash32 (c, hash);
        ++string;
        c = *string;
    }
    return hash;
}

hash64_t Hash64 (const char* string, hash64_t hash) {
    byte c = *string;
    while (c) {
        hash = Hash64 (c, hash);
        ++string;
        c = *string;
    }
    return hash;
}

hash16_t Hash16UI2 (uint16_t value, hash16_t hash) {
    hash = ((value & 0xff) * kLargest16BitPrime) + hash;
    hash = ((value >> 8  ) * kLargest16BitPrime) + hash;
    return hash;
}

hash16_t Hash16UI4 (uint32_t value, hash16_t hash) {
    hash = ((value & 0xff        ) * kLargest16BitPrime) + hash;
    hash = (((value >> 8 ) & 0xff) * kLargest16BitPrime) + hash;
    hash = (((value >> 16) & 0xff) * kLargest16BitPrime) + hash;
    hash = (((value >> 24) & 0xff) * kLargest16BitPrime) + hash;
    return hash;
}

hash16_t Hash16UI8 (uint64_t value, hash16_t hash) {
    hash = ((value & 0xff        ) * kLargest16BitPrime) + hash;
    hash = (((value >> 8 ) & 0xff) * kLargest16BitPrime) + hash;
    hash = (((value >> 16) & 0xff) * kLargest16BitPrime) + hash;
    hash = (((value >> 24) & 0xff) * kLargest16BitPrime) + hash;
    hash = (((value >> 32) & 0xff) * kLargest16BitPrime) + hash;
    hash = (((value >> 40) & 0xff) * kLargest16BitPrime) + hash;
    hash = (((value >> 48) & 0xff) * kLargest16BitPrime) + hash;
    hash = (((value >> 56) & 0xff) * kLargest16BitPrime) + hash;
    return hash;
}

}       //< namespace _
