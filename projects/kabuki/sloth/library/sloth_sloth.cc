/* Kabuki Toolkit
    @version 0.x
    @file    ~/projects/seam_2/kabuki_toolkit_updater/sloth.cc
    @author  Cale McCollough <https://calemccollough.github.io>
    @license Copyright (C) 2014-8 Cale McCollough <calemccollough@gmail.com>;
             All right reserved (R). Licensed under the Apache License, Version
             2.0 (the "License"); you may not use this file except in
             compliance with the License. You may obtain a copy of the License
             [here](http://www.apache.org/licenses/LICENSE-2.0). Unless
             required by applicable law or agreed to in writing, software
             distributed under the License is distributed on an "AS IS" BASIS,
             WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
             implied. See the License for the specific language governing
             permissions and limitations under the License. */

#include <stdafx.h>
#if MAJOR_SEAM > 2 || MAJOR_SEAM == 2 && MINOR_SEAM >= 2
#include "sloth.h"

namespace _ {

Sloth::Sloth() : reserved(0) {}

const Op* Sloth::Star(wchar_t index, Expr* expr) {
  switch (index) {
    case '?': {
      static const Op kThis = {"Sloth", 0,       0,      "#CodeSloth",
                               '}',     ';',     ' ',    false,
                               nullptr, nullptr, nullptr};
      return &kThis;
    }
    case ' ': {
      static const Op kUpdate = {
          "Update", 0,
          0,        "Push Operation that occurs upon updating the toolkit.",
          '}',      ';',
          ' ',      false,
          0,        0,
          0};
      if (!expr) return &kUpdate;
    }
  }
  return nullptr;
}

}       //< namespace _
#endif  //< #if MAJOR_SEAM > 2 || MAJOR_SEAM == 2 && MINOR_SEAM >= 2
