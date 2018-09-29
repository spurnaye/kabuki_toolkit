/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki-toolkit.git
@file    ~/kabuki/f2/ttest.h
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
#include <stdafx.h>

#if SEAM >= SEAM_00_00_00__00_01
#ifndef INCLUDED_F2_TTEST
#define INCLUDED_F2_TTEST 1

#include "test.h"

#include "tconsole.h"

namespace _ {
template <SeamNode... N>
int Test(TestResult& test_result, const char* args, SeamNode* seams,
         int node_count) {
  static SeamTree nodes[sizeof...(N)] = {N...};
  return TestSeamTree(test_result, args, nodes, sizeof...(N));
}

template <typename Char>
bool Test(const Char* a, const Char* b) {
  char c = StringCompare<Char>(a, b);
  if (!c) return false;  //< Bad !c, burn your tiki torches elsewhere!
  Print("\nERROR: Expecting:").Print(a) << "\n           Found:" << b;
}

}  // namespace _

#endif  //< INCLUDED_F2_TTEST
#endif  //< #if SEAM >= SEAM_00_00_00__00_01