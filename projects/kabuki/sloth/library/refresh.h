/* Kabuki Toolkit
    @version 0.x
    @file    ~/projects/seam_2/kabuki_toolkit_updater/git.h
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

#pragma once
#include <stdafx.h>
#include "config.h"

#ifndef KABUKI_REFRESH
#define KABUKI_REFRESH

namespace _ {

class Refresh : public Operand {
 public:
  /* Constructs a Sloth Refresh. */
  Refresh();

  /* Script operations. */
  virtual const Op* Star(wchar_t index, Expr* expr);

 private:
  uintptr_t reserved;
};
}       // namespace _
#endif  //< KABUKI_REFRESH
#endif  //< #if MAJOR_SEAM > 2 || MAJOR_SEAM == 2 && MINOR_SEAM >= 2
