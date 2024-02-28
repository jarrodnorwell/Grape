#ifndef DEFINES_H
#define DEFINES_H

#include <cstdio>

// #define DEBUG

// Enable or disable debug log printing
#ifdef DEBUG
#define LOG(...) printf(__VA_ARGS__)
#else
#define LOG(...) (0)
#endif

// Macro to force inlining
#ifdef _MSC_VER
#define FORCE_INLINE __forceinline
#else
#define FORCE_INLINE inline __attribute__((always_inline))
#endif

// Simple bit macro
#define BIT(i) (1 << (i))

// Macro to swap two values
#define SWAP(a, b) \
{                  \
    auto c = a;    \
    a = b;         \
    b = c;         \
}

// Macros that read a value larger than 8 bits from an 8-bit array
#define U8TO16(data, index) ((data)[index] | ((data)[(index) + 1] << 8))
#define U8TO32(data, index) ((data)[index] | ((data)[(index) + 1] << 8) | ((data)[(index) + 2] << 16) | ((data)[(index) + 3] << 24))
#define U8TO64(data, index) ((uint64_t)U8TO32(data, (index) + 4) << 32) | (uint32_t)U8TO32(data, index)

// Macro that stores a 32-bit value to an 8-bit array
#define U32TO8(data, index, value)                  \
    (data)[(index) + 0] = (uint8_t)((value) >>  0); \
    (data)[(index) + 1] = (uint8_t)((value) >>  8); \
    (data)[(index) + 2] = (uint8_t)((value) >> 16); \
    (data)[(index) + 3] = (uint8_t)((value) >> 24);

#endif // DEFINES_H
