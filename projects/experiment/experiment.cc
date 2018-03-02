// experiment.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;
using namespace std::chrono;

#define DEBUG 0
#if DEBUG
#define PRINTF(format, ...) printf(format, __VA_ARGS__);
#else
#define PRINTF(format, ...)
#endif

int main() {
    enum {
        kNumTests = 100 * 1000 * 1000,
        kSize = 16
    };
    /** Lookup table of ASCII char pairs for 00, 01, ..., 99.
        To convert this algorithm to big-endian, flip the digit pair bytes. */
    static const uint16_t kDigits00To99[100] = {
        0x3030, 0x3130, 0x3230, 0x3330, 0x3430, 0x3530, 0x3630, 0x3730, 0x3830,
        0x3930, 0x3031, 0x3131, 0x3231, 0x3331, 0x3431, 0x3531, 0x3631, 0x3731,
        0x3831, 0x3931, 0x3032, 0x3132, 0x3232, 0x3332, 0x3432, 0x3532, 0x3632,
        0x3732, 0x3832, 0x3932, 0x3033, 0x3133, 0x3233, 0x3333, 0x3433, 0x3533,
        0x3633, 0x3733, 0x3833, 0x3933, 0x3034, 0x3134, 0x3234, 0x3334, 0x3434,
        0x3534, 0x3634, 0x3734, 0x3834, 0x3934, 0x3035, 0x3135, 0x3235, 0x3335,
        0x3435, 0x3535, 0x3635, 0x3735, 0x3835, 0x3935, 0x3036, 0x3136, 0x3236,
        0x3336, 0x3436, 0x3536, 0x3636, 0x3736, 0x3836, 0x3936, 0x3037, 0x3137,
        0x3237, 0x3337, 0x3437, 0x3537, 0x3637, 0x3737, 0x3837, 0x3937, 0x3038,
        0x3138, 0x3238, 0x3338, 0x3438, 0x3538, 0x3638, 0x3738, 0x3838, 0x3938,
        0x3039, 0x3139, 0x3239, 0x3339, 0x3439, 0x3539, 0x3639, 0x3739, 0x3839,
        0x3939, };

    auto start1 = high_resolution_clock::now (),
         start2 = start1,
         stop1  = start1,
         stop2  = stop1;
    auto delta1 = duration_cast<milliseconds> (stop1 - start1).count (),
         delta2 = delta1;

    uint32_t value,
             scalar;
    uint16_t digits1and2,
             digits3and4,
             digits5and6,
             digits7and8;

    std::random_device rd;
    std::mt19937_64 eng (rd ());
    std::uniform_int_distribution<uint32_t> distr;

    char buffer[kSize];
    uint16_t* text16 = reinterpret_cast<uint16_t*> (buffer + 6);
    /*
    for (uint32_t i = 0; i < 20; ++i) {
        uint8_t psudomod10 = i & 0xf;
        cout << "\n\n    psudomod10 = i & 0xf = " << (uint32_t)psudomod10
             << "\n    i % 10 = " << (i %10);
        if (psudomod10 > 10) {
            psudomod10 -= 10;
        }
        cout << "\n    psudomod10 = " << (uint32_t)psudomod10;
    }
    cout << '\n';
    system ("PAUSE");*/
    
    cout << "\n\n   Benchmarking nil:";
    start1 = high_resolution_clock::now ();
    for (uint32_t i = kNumTests; i > 0; --i) {
    }
    stop1  = high_resolution_clock::now ();
    delta1 = duration_cast<milliseconds> (stop1 - start1).count ();
    cout << "\n    Finished in " << delta1 << " ms";
    
    cout << "\n\n   Benchmarking nil:";
    start1 = high_resolution_clock::now ();
    for (uint32_t i = kNumTests; i > 0; --i) {
    }
    stop1  = high_resolution_clock::now ();
    delta1 = duration_cast<milliseconds> (stop1 - start1).count ();
    cout << "\n    Finished in " << delta1 << " ms";
    
    cout << "\n\n   Benchmarking nil:";
    start1 = high_resolution_clock::now ();
    for (uint32_t i = kNumTests; i > 0; --i) {
    }
    stop1  = high_resolution_clock::now ();
    delta1 = duration_cast<milliseconds> (stop1 - start1).count ();
    cout << "\n    Finished in " << delta1 << " ms";

    for (int j = 100; j > 0; --j) {
        cout << "\n\n\n    Testing parallel division...";

        start1 = high_resolution_clock::now ();
        for (uint32_t i = kNumTests; i > 0; --i) {
            value = 12345678;
            #if DEBUG
            for (int i = 0; i < 8; ++i) {
                buffer[i] = 'x';
            }
            *(buffer + 8) = 0;
            #endif

            PRINTF ("\n    Divide and conquer value:%u", value);
            scalar = 10000;
            digits5and6 = (uint16_t)(value / scalar);
            PRINTF ("\n    digits5and6 = (uint16_t)(value / scalar) = %u", digits5and6);

            digits1and2 = value - scalar * digits5and6;
            PRINTF ("\n    digits1and2 = value - scalar * digits5and6 = %u", digits1and2);
        
            digits7and8 = digits5and6 / 100;
            PRINTF ("\n\n    digits7and8 = digits5and6 / 100 = %u", digits7and8);
        
            digits3and4 = digits1and2 / 100;
            PRINTF ("\n    digits3and4 = digits1and2 / 100 = %u", digits3and4);

            digits5and6 -= 100 * digits7and8;
            PRINTF ("\n\n    digits5and6 -= 100 * digits7and8 = %u", digits5and6);

            digits1and2 -= 100 * digits3and4;
            PRINTF ("\n    digits1and2 -= 100 * digits3and4 = %u", digits1and2);
            
            text16 = reinterpret_cast<uint16_t*> (buffer + 6);
            *text16-- = kDigits00To99[digits1and2];
            *text16-- = kDigits00To99[digits3and4];
            *text16-- = kDigits00To99[digits5and6];
            *text16-- = kDigits00To99[digits7and8];

            PRINTF ("\n    Printed:\"%s\"\n\n", buffer)
        }
        stop1  = high_resolution_clock::now ();
        delta1 = duration_cast<milliseconds> (stop1 - start1).count ();

        cout << "\n    Finished in " << delta1 << " ms\n\n";
    //}
    //while (1) {
        cout << "\n\n   Benchmarking series modulo 100:";
        start1 = high_resolution_clock::now ();
        for (uint32_t i = kNumTests; i > 0; --i) {
            value = 12345678;
            *(buffer + 8) = 0;
            text16 = reinterpret_cast<uint16_t*> (buffer + 6);
            *text16-- = kDigits00To99[value % 100];
            value /= 100;
            *text16-- = kDigits00To99[value % 100];
            value /= 100;
            *text16-- = kDigits00To99[value % 100];
            value /= 100;
            *text16-- = kDigits00To99[value];
        }
        stop1  = high_resolution_clock::now ();
        delta1 = duration_cast<milliseconds> (stop1 - start1).count ();
        cout << "\n    Finished in " << delta1 << " ms";
    }

    system ("PAUSE");
    
    return 0;
}
