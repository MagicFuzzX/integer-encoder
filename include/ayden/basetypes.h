/* 
 * Copyright Mehdi Sotoodeh.  All rights reserved. 
 * <mehdisotoodeh@gmail.com>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that source code retains the 
 * above copyright notice and following disclaimer.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#pragma once

#include <stdint.h>

// Little-endian as default
#ifndef CONFIG_BIG_ENDIAN
#define CONFIG_LITTLE_ENDIAN
#endif

typedef unsigned char       U8;
typedef signed   char       S8;
#if defined(_MSC_VER)
typedef unsigned __int16    U16;
typedef signed   __int16    S16;
typedef unsigned __int32    U32;
typedef signed   __int32    S32;
typedef unsigned __int64    U64;
typedef signed   __int64    S64;
#else
typedef uint16_t            U16;
typedef int16_t             S16;
typedef uint32_t            U32;
typedef int32_t             S32;
typedef uint64_t            U64;
typedef int64_t             S64;
#endif

typedef unsigned int        SZ;

#ifdef CONFIG_BIG_ENDIAN
typedef union
{
    U16 u16;
    S16 s16;
    U8 bytes[2];
    struct { U8 b1, b0; } u8;
    struct { S8 b1; U8 b0; } s8;
} M16;
typedef union
{
    U32 u32;
    S32 s32;
    U8 bytes[4];
    struct { U16 w1, w0; } u16;
    struct { S16 w1; U16 w0; } s16;
    struct { U8 b3, b2, b1, b0; } u8;
    struct { M16 hi, lo; } m16;
} M32;
typedef union
{
    U64 u64;
    S64 s64;
    U8 bytes[8];
    struct { U32 hi, lo; } u32;
    struct { S32 hi; U32 lo; } s32;
    struct { U16 w3, w2, w1, w0; } u16;
    struct { U8 b7, b6, b5, b4, b3, b2, b1, b0; } u8;
    struct { M32 hi, lo; } m32;
} M64;
#else
typedef union
{
    U16 u16;
    S16 s16;
    U8 bytes[2];
    struct { U8 b0, b1; } u8;
    struct { U8 b0; S8 b1; } s8;
} M16;
typedef union
{
    U32 u32;
    S32 s32;
    U8 bytes[4];
    struct { U16 w0, w1; } u16;
    struct { U16 w0; S16 w1; } s16;
    struct { U8 b0, b1, b2, b3; } u8;
    struct { M16 lo, hi; } m16;
} M32;
typedef union
{
    U64 u64;
    S64 s64;
    U8 bytes[8];
    struct { U32 lo, hi; } u32;
    struct { U32 lo; S32 hi; } s32;
    struct { U16 w0, w1, w2, w3; } u16;
    struct { U8 b0, b1, b2, b3, b4, b5, b6, b7; } u8;
    struct { M32 lo, hi; } m32;
} M64;
#endif

#define IN
#define OUT

// KryptoPlus error codes

#define SUCCESS                  0
#define ERR_OUT_OF_MEMORY        (-1)
#define ERR_INVALID_PARAMETER    (-2)
#define ERR_INVALID_FORMAT       (-3)
#define ERR_FORMAT_MISMATCH      (-4)
#define ERR_OUT_OF_RANGE         (-5)
#define ERR_INVALID_CHARSET      (-6)
