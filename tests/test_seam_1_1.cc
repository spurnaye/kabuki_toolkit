/** Kabuki Toolkit
    @version 0.x
    @file    ~/tests/test_seam_1_1.cc
    @author  Cale McCollough <calemccollough.github.io>
    @license Copyright (C) 2017 Cale McCollough <calemccollough.github.io>;
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
#include "tests_global.h"

#if MAJOR_SEAM == 1 && MINOR_SEAM == 1

using namespace _;
using namespace std;

#define PRINT_PAUSE(message)\
    printf ("\n%s               ", message); system ("PAUSE");

TEST_GROUP (SEAM_1_2_TESTS) {
    void setup () {
        puts ("\n\n\nTesting SEAM_1_2");
    }

    void teardown () {
        PRINT_PAUSE ("\n")
    }
};

TEST (SEAM_1_2_TESTS, TestPrinter) {
    static const uint32_t k10ToThe[20] = {
        1,//< 10^0
        10,//< 10^1
        100,//< 10^2
        1000,//< 10^3
        10000,//< 10^4
        100000,//< 10^5
        1000000,//< 10^6
        10000000,//< 10^7
        100000000,//< 10^8
        1000000000,//< 10^9
    };

    static const uint32_t test_value[] = {
        1,
        12,
        123,
        1234,
        12345,
        123456,
        1234567,
        12345678,
        123456789,
        k10ToThe[0] - 1, k10ToThe[0], k10ToThe[0] + 1,
        k10ToThe[1] - 1, k10ToThe[1], k10ToThe[1] + 1,
        k10ToThe[1] + k10ToThe[1] / 2,
        k10ToThe[2] - 1, k10ToThe[2], k10ToThe[2] + 1,
        k10ToThe[2] + k10ToThe[2] / 2,
        k10ToThe[3] - 1, k10ToThe[3], k10ToThe[3] + 1,
        k10ToThe[3] + k10ToThe[3] / 2,
        k10ToThe[4] - 1, k10ToThe[4], k10ToThe[4] + 1,
        k10ToThe[4] + k10ToThe[4] / 2,
        k10ToThe[5] - 1, k10ToThe[5], k10ToThe[5] + 1,
        k10ToThe[5] + k10ToThe[5] / 2,
        k10ToThe[6] - 1, k10ToThe[6], k10ToThe[6] + 1,
        k10ToThe[6] + k10ToThe[6] / 2,
        k10ToThe[7] - 1, k10ToThe[7], k10ToThe[7] + 1,
        k10ToThe[7] + k10ToThe[7] / 2,
        k10ToThe[8] - 1, k10ToThe[8], k10ToThe[8] + 1,
        k10ToThe[8] + k10ToThe[8] / 2,
        k10ToThe[9] - 1, k10ToThe[9], k10ToThe[9] + 1,
        k10ToThe[9] + k10ToThe[9] / 2,
    };

    /*
    printf ("\nTesting quick MSD lookup...\n    Length 1:");
    static const uint32_t delta_one_bits[] = { 4, 7, 10, 14, 17, 20, 24, 27, 30 };
    uint32_t max,
             num_bits,
             msd_bit_range;
    printf ("\n| Length | MSD Offset | Min Value  |"
            "\n|:------:|:----------:|:----------:|");
    for (int length = 3; length < 10; ++length) {
        num_bits = delta_one_bits[length - 2];
        msd_bit_range = (length == 10 || length == 20) ? 16: 8;
        for (uint32_t i = 1;  i <= 8; ++i) {
            printf ("\n|   %u    |     %u      | %10u |", length, i, i << num_bits);
        }
    }
    putchar ('\n');
    system ("PAUSE");*/

    static const uint32_t problem_children[] = {
        0,
    };
    enum {
        kNumProblemChildren = 0,
        kSize = 24
    };

    char     text[kSize],
             expecting[kSize];
    //found[kSize];
    char*    result;
    uint32_t value;
    
    // Setup C++1x random number generator.
    std::random_device rd;
    std::mt19937_64 eng (rd ());
    std::uniform_int_distribution<uint32_t> distr;

    printf ("\n\nTesting Script ItoS Algorithm...\n\n");

    //PrintDigits99To99Lut ();

    printf ("\n\nTesting problem children...\n\n");
    for (int i = 0; i < kNumProblemChildren; ++i) {
        value = problem_children[i];
        sprintf_s (expecting, 24, "%u", value);
        printf ("\n%i.) Expecting \"%s\":%u", i + 1, expecting,
                (uint)strlen (expecting));
        result = Print (value, text, text + kSize);
        if (!result) {
            PRINT_PAUSE ("An error occurred :-(")
            break;
        }
        *result = 0;
        if (strcmp (expecting, text)) {
            printf ("\n\nERROR: Expecting \"%s\":%u and found \"%s\":%u",
                    expecting, (uint)strlen (expecting), text,
                    (uint)strlen (text));
            PRINT_PAUSE ("\n")
        }
        PrintLine ();
    }

    printf ("\n\nTesting edge conditions...\n\n");
    for (int i = 0; i < 28; ++i) {
        value = test_value[i];
        sprintf_s (expecting, 24, "%u", value);
        printf ("\n%i.) Expecting \"%s\":%u", i + 1, expecting,
                (uint)strlen (expecting));
        result = Print (value, text, text + kSize);
        if (!result) {
            PRINT_PAUSE ("An error occurred :-(")
            break;
        }
        *result = 0;
        if (strcmp (expecting, text)) {
            printf ("\n\nERROR: Expecting \"%s\":%u and found \"%s\":%u",
                    expecting, (uint)strlen (expecting), text,
                    (uint)strlen (text));
            PRINT_PAUSE ("\n")
        }
        PrintLine ();
    }

    printf ("\n\nTesting random numbers...\n\n");

    for (int i = 0; i < 0x00ffffff; ++i) {
        value = distr (eng);
        sprintf_s (expecting, 24, "%u", value);
        printf ("\n%i.) Expecting \"%s\":%u", i + 1, expecting,
                (uint)strlen (expecting));
        result = Print (value, text, text + kSize);
        if (!result) {
            PRINT_PAUSE ("An error occurred :-(")
            break;
        }
        *result = 0;
        if (strcmp (expecting, text)) {
            printf ("\n\nERROR: Expecting \"%s\":%u and found \"%s\":%u",
                    expecting, (uint)strlen (expecting), text,
                    (uint)strlen (text));
            PRINT_PAUSE ("\n")
        }
        PrintLine ();
    }

    printf ("\n Done testing ItoS :)\n\n");
}

#undef PRINT_PAUSE
#endif  //< #if MAJOR_SEAM == 1 && MINOR_SEAM == 1
