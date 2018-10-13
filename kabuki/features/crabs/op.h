/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki-toolkit.git
@file    /kabuki/crabs/op.h
@author  Cale McCollough <cale.mccollough@gmail.com>
@license Copyright (C) 2014-2017 Cale McCollough <calemccollough.github.io>;
All right reserved (R). Licensed under the Apache License, Version 2.0 (the
"License"); you may not use this file except in compliance with the License.
You may obtain a copy of the License at www.apache.org/licenses/LICENSE-2.0.
Unless required by applicable law or agreed to in writing, software distributed
under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
CONDITIONS OF ANY KIND, either express or implied. See the License for the
specific language governing permissions and limitations under the License. */

#pragma once
#include <pch.h>

<<<<<<< HEAD
#if SEAM >= SEAM_0_0_4_0__00_00
=======
#if SEAM >= SEAM_00_00_01__00
>>>>>>> af98cdd86f8b7b5188063c203df0e9dd4e771336

#ifndef INCLUDED_CRABS_OP
#define INCLUDED_CRABS_OP

#include <kabuki/f2/str1.h>

#include "error.h"

namespace _ {

// enum {
//    kOpPush          = 0, //< Operation Type 0: Stack push .
//    kOpOperation     = 1, //< Operation Type 1: Abstract Operation.
//    KOpOperationPush = 2, //< Operation Type 2: Operation with stack push.
//};

struct BOut;

/* An expression Operation with name key, multiple input params,
    result, and optional description of a data set.
    @code
    static const Op kThis = { "Key",
        Params<1, 2>::Header, Params<1, 2>::Header,
        "Description", '}', ';', ' ', nullptr, "-", nullptr };

    static const Op kOpExample =   { "Key2",
        NumOps (0), FirstOp ('A'),
        "Description", '}', ';', ' ', true, nullptr, "-", nullptr };
    @endcode */
struct API Op {
  const char* name;          //< Op name.
  const uint_t *in,          //< Input BSQ params or OpFirst.
      *out;                  //< Output BSQ params or OpLast.
  const char* description;   //< Op description.
  wchar_t pop,               //< Index of the Pop Operation.
      close,                 //< Index of the Close Operation.
      default_op;            //< Index of the Default Operation.
  bool using_numbers;        //< Flag for if tokens may use numbers.
  const char *ignore_chars,  //< String of chars to ignore.
      *allowed_chars;        //< String of allowed symbols.
  const BOut* evaluation;    //< Evaluated expression Slot.
};

/* Converts the given value to a pointer. */
inline intptr_t OpCount(const Op& op) { return op.out - op.in; }

/* Converts the given value to a pointer. */
inline const uint_t* OpFirst(wchar_t index) {
  return reinterpret_cast<const uint_t*>(index);
}

/* Converts the given value to a pointer. */
inline wchar_t OpFirst(const Op* op) {
  ASSERT(op);
  return (wchar_t) reinterpret_cast<uintptr_t>(op->in);
}

/* Converts the given value to a pointer. */
inline const uint_t* OpLast(wchar_t index) {
  return reinterpret_cast<const uint_t*>(index);
}

/* Converts the given value to a pointer. */
inline wchar_t OpLast(const Op* op) {
  ASSERT(op);
  return (wchar_t) reinterpret_cast<uintptr_t>(op->out);
}

#if CRABS_TEXT
Utf8& Print(Utf8& print, const Op* op);
#endif

}  // namespace _

inline _::Utf8& operator<<(_::Utf8& print, const _::Op* op) {
  return _::Print(print, op);
}

<<<<<<< HEAD
=======
#endif  //< #if SEAM >= SEAM_00_00_01__00
>>>>>>> af98cdd86f8b7b5188063c203df0e9dd4e771336
#endif  //< INCLUDED_CRABS_OP
#endif  //< #if SEAM >= SEAM_0_0_4_0__00_00