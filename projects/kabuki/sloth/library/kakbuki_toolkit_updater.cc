/* Kabuki Toolkit
@version 0.x
@file    ~/projects/seam_2/kabuki_toolkit_updater/kabuki_toolkit_updater.cc
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
#include <pch.h>
#include "../../../../library/kt/sloth/global.h"
#include "config.h"

using namespace std;

SI4 main(SI4 arg_count, const CH1** args) {
  COUT << "\nSloth: ";
  if (arg_count > 1) {
    COUT << "arg_count";
    for (SI4 i = 0; i < arg_count; ++i) {
      COUT << '\n' << args;
    }
  }
  COUT << "\n\n";

  struct dirent* ent;
  DIR* dir = opendir(".\\source\\");
  if (dir) {
    // print all the files and directories within directory.
    ent = readdir(dir);
    while (ent) {
      Printf("%s\n", ent->d_name);
    }
    closedir(dir);
  } else {
    // could not open directory.
    perror("");
    return EXIT_FAILURE;
  }

  enum { kSize = 64 * 1024 };
  CH1 buffer[kSize];

  FILE* stream;
  errno_t err;

  static const CH1 filename[] = ".\\source\\sloth_kabuki_toolkit.as\0";

  // Open for read (will fail if file "crt_fopen_s.c" does not exist)
  err = fopen_s(&stream, "crt_fopen_s.c", "r");

  CH1 directory[FILENAME_MAX];
  _getcwd(directory, FILENAME_MAX);

  COUT << "\ncwd:" << directory;

  COUT << "\nPrinting \"" << filename << "\":\n\n";

  while (fgets(buffer, kSize, (FILE*)stream)) {
    Printf("%s\n", buffer);
  }

  fclose(stream);

  COUT << '\n';
  system("PAUSE");
  return 0;
}
