#pragma once

#if defined(_MSC_VER)
#define NOMINMAX
#endif // _MSC_VER

#include <cassert>
#include <string>

// Unsigned int types.
using u8 = uint8_t;
using u16 = uint16_t;
using u32 = uint32_t;
using u64 = uint64_t;

// Signed int types.
using i8 = int8_t;
using i16 = int16_t;
using i32 = int32_t;
using i64 = int64_t;

// Floating point types
using f32 = float;
using f64 = double;
using f128 = double long;

using c8 = char ;

// Ensure all types are of the correct size.
static_assert(sizeof(u32) == sizeof(unsigned), "Expected u32 equals to unsigned size.");
static_assert(sizeof(i32) == sizeof(long), "Expected i32 equals to long size.");
static_assert(sizeof(u32) == sizeof(unsigned long), "Expected u32 equals to unsigned long size.");

static_assert(sizeof(u8) == 1, "Expected u8 to be 1 byte.");
static_assert(sizeof(u16) == 2, "Expected u16 to be 2 bytes.");
static_assert(sizeof(u32) == 4, "Expected u32 to be 4 bytes.");
static_assert(sizeof(u64) == 8, "Expected u64 to be 8 bytes.");

static_assert(sizeof(i8) == 1, "Expected i8 to be 1 byte.");
static_assert(sizeof(i16) == 2, "Expected i16 to be 2 bytes.");
static_assert(sizeof(i32) == 4, "Expected i32 to be 4 bytes.");
static_assert(sizeof(i64) == 8, "Expected i64 to be 8 bytes.");

static_assert(sizeof(f32) == 4, "Expected f32 to be 4 bytes.");
static_assert(sizeof(f64) == 8, "Expected f64 to be 8 bytes.");
static_assert(sizeof(f128) == 8, "Expected f128 to be 8 bytes.");
