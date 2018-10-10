/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/kabuki-toolkit.git
<<<<<<< HEAD:seam_0/seam_tree.cc
@file    /seam_0/seam_tree.h
=======
@file    /seam_00/seam_tree_node.h
>>>>>>> af98cdd86f8b7b5188063c203df0e9dd4e771336:seam_tree.cc
@author  Cale McCollough <cale.mccollough@gmail.com>
@license Copyright (C) 2014-2017 Cale McCollough <calemccollough.github.io>;
All right reserved (R). Licensed under the Apache License, Version 2.0 (the
"License"); you may not use this file except in compliance with the License.
You may obtain a copy of the License at www.apache.org/licenses/LICENSE-2.0.
Unless required by applicable law or agreed to in writing, software distributed
under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
CONDITIONS OF ANY KIND, either express or implied. See the License for the
specific language governing permissions and limitations under the License. */

#include <pch.h>

#include <kabuki/f2/ttest.h>

#include "seam_0/seam_kabuki.h"

namespace _ {

int main(int arg_count, char** args) {
  enum { kSeamLogSize = 1024 };
  char seam_log[kSeamLogSize];
  return TestTree<Seam_0>(seam_log, args) ? APP_EXIT_SUCCESS : APP_EXIT_FAILURE;
}
}  // namespace _
