/* Kabuki Toolkit @version 0.x
@link    https://github.com/kabuki-starship/script2.git
@file    /project/0_0_0.store_server/webcam/global_config.inl
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

#ifndef STORE_SERVER_GLOBAL_CONFIG_INL
#define STORE_SERVER_GLOBAL_CONFIG_INL 1
#include <script2/global_config.inl>

#define STORE_SERVER 123
#define STORE_SERVER_0 STORE_SERVER_0 + 1
#define STORE_SERVER_1 STORE_SERVER_0 + 2
#define STORE_SERVER_N STORE_SERVER_0 + 2
#endif
