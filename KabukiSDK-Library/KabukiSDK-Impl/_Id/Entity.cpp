/** Kabuki Software Development Kit
    @file    /.../KabukiSDK-Impl/_Id/Enity.cpp
    @author  Cale McCollough <cale.mccollough@gmail.com>
    @license Copyright (C) 2016 [Cale McCollough](calemccollough.github.io)

                            All right reserved (R).

        Licensed under the Apache License, Version 2.0 (the "License"); you may
        not use this file except in compliance with the License. You may obtain
        a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

        Unless required by applicable law or agreed to in writing, software
        distributed under the License is distributed on an "AS IS" BASIS,
        WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
        See the License for the specific language governing permissions and
        limitations under the License.
*/

#include <_Id/Enity.hpp>

namespace _Id {

Enity::Enity (string anEmailAdress, string aFirstName, string aLastName, 
    string aPrimaryPhoneNum, string aStreetAdress1, string aZipCode1, 
    string aStreetAdress2, string aZipCode2)
:   firstName     (aFirstName),
    lastName      (aLastName),
    phoneNumber   (aPrimaryPhoneNum),
    emailAdress   (anEmailAdress),
    streetAdress1 (aStreetAdress1),
    zipCode1      (aZipCode1)
{
    
}

string Enity::getName () { return name; }

void Enity::setName (string S) { name = S }

int Enity::contains (string query)
{
    for_each (tags.begin (), tags.end (), [](string& s(
    {
        if (s == query) return 1;
    });

    for_each (tags.begin (), tags.end (), [](Address& a(
    {
        if (a == query) return 1;
    });

    for_each (tags.begin (), tags.end (), [](Enity& e(
    {
        if (e == query) return 1;
    });

    for_each (tags.begin (), tags.end (), [](Profile& p(
    {
        if (p == query) return 1;
    });

    for_each (tags.begin (), tags.end (), [](string& s(
    {
        if (s == query) return 1;
    });
    
    return 0;
}

}   //< namespace _Id
