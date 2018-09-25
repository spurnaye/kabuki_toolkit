/* Kabuki Toolkit
@version 0.x
@file    ~/tests/test_seam_0_0_2.cc
@author  Cale McCollough <cale.mccollough@gmail.com>
@license Copyright (C) 2014-2017 Cale McCollough <calemccollough.github.io>;
All right reserved (R). Licensed under the Apache License, Version 2.0 (the
"License"); you may not use this file except in compliance with the License.
You may obtain a copy of the License at www.apache.org/licenses/LICENSE-2.0.
Unless required by applicable law or agreed to in writing, software distributed
under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
CONDITIONS OF ANY KIND, either express or implied. See the License for the
specific language governing permissions and limitations under the License. */

#include <stdafx.h>

#if SEAM >= SEAM_0_0_2

#include <random>

#include "../../kabuki/crabs/global.h"

#if SEAM_MAJOR == 0 && SEAM_MINOR == 2
#define PRINT(item) Print(item)
#define PRINTF(format, ...) Printf(format, __VA_ARGS__)
#define PAUSE(message) Pause(message)
#define PRINT_HEADING(message) PrintHeading(message)
#define PRINT_LINE(c) PrintLine(c)
#else
#define PRINT(item)
#define PRINTF(x, ...)
#define PAUSE(message)
#define PRINT_HEADING(c)
#define PRINT_LINE(c)
#endif

using namespace _;

TEST_GROUP(SEAM_0_0_2){void setup(){}

                       void teardown(){Pause("\n");
}
}
;

TEST(SEAM_0_0_2, SEAM_0_0_2A) {
  PRINT_HEADING("Testing SEAM_0_0_2...");

  PRINTF("\n\nTesting Text...");
#if CRABS_TEXT
  enum {
    kCompareStringsCount = 5,
    kSize = 2048,
  };

  static const char* test_strings[kCompareStringsCount][2] = {
      {"?", ""},
      {"?", "?"},
      {"? ", "?"},
      {"Apples", "Apples"},
      {"Apples", "Apples"},
  };

  static const char* kCompareStrings[] = {
      "Testing",
      "Texting",
      "Testing@",
      "Texting@",
  };

  static const char kTestingString[] = "Testing one, two, three.";

  static const char* kStringsRightAligned[] = {
      "    Testing one, two, three.", "Test...", ".", "..", "...", "T...",
  };

  static const char kStringNumbers[] = "1234567890\0";

  static const char* kStringsCentered[] = {" 1234567890\0", " 1234567890 \0",
                                           "  1234567890 \0", "123...\0"};

  const char* end;
  char buffer[kSize + 1], buffer_b[kSize + 1];

  Utf8 utf(buffer, kSize);

  for (int i = 0; i < kCompareStringsCount; ++i) {
    end = Print(buffer, buffer + kSize, test_strings[i][0]);
    Assert(end);

    end = StringEquals(buffer, test_strings[i][0]);
    Assert(end);
  }

  static const char kTesting123[] = "Testing 1, 2, 3\0";

  PRINT_HEADING("    Testing Utf...");
  PRINTF("    Expecting \"%s\"...", kTesting123);

  utf.Set(buffer) << "Testing " << 1 << ", " << 2 << ", " << 3;

  STRCMP_EQUAL(kTesting123, buffer);

  PRINT_HEADING("    Running HexTest...");
  for (int i = 0; i < 16; ++i) {
    int value = HexToByte(HexNibbleToLowerCase(i));
    Compare(i, value);
    PRINTF("\n    %i.) %i", i, value);
    value = HexToByte(HexNibbleToUpperCase(i));
    PRINTF(" value is now:%i", value);
    Compare(i, value);
  }

  for (int i = 0; i < 256; ++i) {
    uint16_t c = HexByteToLowerCase(i);
    PRINTF("\n    %i.) expecting: %x        HexByteToLowerCase:%c%c", i, i,
           (char)c, (char)(c >> 8));
    int value = HexToByte(c);
    PRINTF("        HexToByte:%i", value);
    Compare(i, value);
    value = HexToByte(HexByteToUpperCase(i));
    PRINTF("     value is now:%i", value);
    Compare(i, value);
  }

  PRINT_HEADING("    Testing string utils...");

  Assert(!StringEquals(kCompareStrings[0], kCompareStrings[1]));
  Assert(!StringEquals(kCompareStrings[0], kCompareStrings[3]));
  Assert(StringEquals(kCompareStrings[0], kCompareStrings[0]));
  Assert(!StringEquals(kCompareStrings[2], kCompareStrings[3]));
  Assert(StringEquals(kCompareStrings[2], kCompareStrings[2]));

  Compare(9, TextLength("123456789"));

  Assert(StringFind(kTestingString, "one"));
  Assert(StringFind(kTestingString, "three."));

  PRINTF("\n\n    Testing PrintRight...");

  Assert(PrintRight(buffer, buffer + kSize, kTestingString, 28));
  PRINTF("\n    Wrote:\"%s\":%i", buffer, TextLength(buffer));
  STRCMP_EQUAL(kStringsRightAligned[0], buffer);

  Assert(PrintRight(buffer, buffer + kSize, kTestingString, 7));
  STRCMP_EQUAL(kStringsRightAligned[1], buffer);

  Assert(PrintRight(buffer, buffer + kSize, kTestingString, 1));
  STRCMP_EQUAL(kStringsRightAligned[2], buffer);

  Assert(PrintRight(buffer, buffer + kSize, kTestingString, 2));
  STRCMP_EQUAL(kStringsRightAligned[3], buffer);

  Assert(PrintRight(buffer, buffer + kSize, kTestingString, 3));
  STRCMP_EQUAL(kStringsRightAligned[4], buffer);

  Assert(PrintRight(buffer, buffer + kSize, kTestingString, 4));
  STRCMP_EQUAL(kStringsRightAligned[5], buffer);

  PRINTF("\n\n    Testing PrintCentered...");

  for (int i = 0; i < 4; ++i) {
    PRINTF("\n    %i.)\"%s\"", i, kStringsCentered[i]);
  }

  utf.Set(buffer) << Center(kStringNumbers, 10);
  STRCMP_EQUAL(kStringNumbers, buffer);

  utf.Set(buffer) << Center(kStringNumbers, 11);
  STRCMP_EQUAL(kStringsCentered[0], buffer);

  utf.Set(buffer) << Center(kStringNumbers, 12);
  STRCMP_EQUAL(kStringsCentered[1], buffer);

  utf.Set(buffer) << Center(kStringNumbers, 13);
  STRCMP_EQUAL(kStringsCentered[2], buffer);

  utf.Set(buffer) << Center(kStringNumbers, 6);
  STRCMP_EQUAL(kStringsCentered[3], buffer);

  PRINT_LINE('-');
  PRINTF("\n\n Testing PrintMemory (void*, int size)...");

  for (int i = 1; i <= kSize; ++i) buffer_b[i - 1] = '0' + i % 10;
  buffer_b[kSize] = 0;
  Assert(PrintMemory(buffer, buffer + kSize, buffer_b, buffer_b + 160));
  PRINTF("\n    Printed:\n%s", buffer);

  PRINT_LINE('-');
  PRINTF("\n\n    Testing TextScanTime...");

  Tms t, t_found;
  const char* result;

  // @note The following dates must be the current day to work right in order
  //       to auto-detect the year.
  const char* strings[] = {
      "8/9",
      "08/09",
      "8/9/18",
      "8/09/18",
      "8/9/2018",
      "8/09/2018",
      "8/09/2018",
      "08/9/2018",
      "8/09/2018@00",
      "8.09.2018@00AM",
      "8/09/2018@00:00",
      "8/09/18@00:0AM",
      "8/09/2018@00:00:00",
      "8/09/2018@00:00:00AM",
      "2018-08-09@00:00:00AM",
      "2018-08-09@00:00:00am",
      "2018-08-09@00:00:00A",
      "2018-08-09@00:00:00a ",
  };

  for (int i = 0; i < 18; ++i) {
    PRINT_LINE('-');
    PRINTF("\n    %i", i);
    Tms t = 0;
    result = TextScanTime(strings[i], t);
    // Assert (!ClockCompare (t, 2018, 8, 9, 0, 0, 0))
  }

  PRINTF("\n\n    Testing more valid input...\n");

  t = ClockTimeTMS(8, 9, 17, 4, 20);
  Print(buffer, buffer + kSize, t);
  result = TextScanTime(buffer, t_found);
  Assert(ClockCompare(t_found, t))

  t = ClockTimeTMS(2020, 4, 20, 4, 20);
  Print(buffer, buffer + kSize, t);
  result = TextScanTime(buffer, t_found);
  Assert(ClockCompare(t, t_found))

  t = ClockTimeTMS(1947, 12, 7, 23, 5, 7);
  Print(buffer, buffer + kSize, t);
  result = TextScanTime(buffer, t_found);
  Assert(ClockCompare(t, t_found));

  PRINT_HEADING("\nTesting invalid input...\n");
  TextScanTime("cat", t);

  TextScanTime("2017-30-40", t);

  PRINTF("\nDone testing date parsing utils! :-)\n");

  PRINT_HEADING("\n\nTest MemoryCopy and MemoryCompare...\n\n");
  enum {
    kTestCharsCount = 1024,
    kTestCharsOffsetCount = 16,
  };
  char test_chars[kTestCharsCount];
  char test_chars_result[kTestCharsCount + kTestCharsOffsetCount];

  PRINTF("\ntest_chars[0] = %p , test_chars_result[n] = %p  ", test_chars,
         test_chars_result);

  for (int i = 0; i < kTestCharsOffsetCount; ++i) {
    for (int j = 0; j < kTestCharsCount; ++j) test_chars[j] = (char)(j % 256);
    char* result = SocketCopy(test_chars_result + i, kTestCharsCount,
                              test_chars, kTestCharsCount);
    Assert(result);
    Assert(!SocketCompare(test_chars + i, kTestCharsCount, test_chars_result,
                         kTestCharsCount));
  }

  PRINTF("\n\nDone testing MemoryCopy!\n");
#endif  //< #if CRABS_TEXT
  PAUSE("Done testing SEAM_0_0_2! (:-)-+=<");
}

#undef PAUSE
#undef PRINTF
#else
void TestSeam_1_2() {}
#endif  //< #if SEAM >= SEAM_0_0_2
