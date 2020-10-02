/*
* MIT License
*
* Copyright (c) 2020 Tobias Nießen
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*/

#ifndef CONSTEXPR_SECDED_H
#define CONSTEXPR_SECDED_H

#include <stdint.h>

/*
 * SECDED code for m = 3, n = 8, k = 4.
 *
 * (4x8) parity check matrix:
 *
 *   1 0 1 1 1 0 0 0
 *   1 1 0 1 0 1 0 0
 *   1 1 1 0 0 0 1 0
 *   0 1 1 1 0 0 0 1
 */
#define SECDED_8_4_ENCODE(v) ((uint8_t)(((uint8_t)(v)) | (((((v) & ((((uint8_t)(1))) << (((uint8_t)(0))))) >> (((uint8_t)(0)))) ^ (((v) & ((((uint8_t)(1))) << (((uint8_t)(2))))) >> (((uint8_t)(2)))) ^ (((v) & ((((uint8_t)(1))) << (((uint8_t)(3))))) >> (((uint8_t)(3))))) << (((uint8_t)(4)))) | (((((v) & ((((uint8_t)(1))) << (((uint8_t)(0))))) >> (((uint8_t)(0)))) ^ (((v) & ((((uint8_t)(1))) << (((uint8_t)(1))))) >> (((uint8_t)(1)))) ^ (((v) & ((((uint8_t)(1))) << (((uint8_t)(3))))) >> (((uint8_t)(3))))) << (((uint8_t)(5)))) | (((((v) & ((((uint8_t)(1))) << (((uint8_t)(0))))) >> (((uint8_t)(0)))) ^ (((v) & ((((uint8_t)(1))) << (((uint8_t)(1))))) >> (((uint8_t)(1)))) ^ (((v) & ((((uint8_t)(1))) << (((uint8_t)(2))))) >> (((uint8_t)(2))))) << (((uint8_t)(6)))) | (((((v) & ((((uint8_t)(1))) << (((uint8_t)(1))))) >> (((uint8_t)(1)))) ^ (((v) & ((((uint8_t)(1))) << (((uint8_t)(2))))) >> (((uint8_t)(2)))) ^ (((v) & ((((uint8_t)(1))) << (((uint8_t)(3))))) >> (((uint8_t)(3))))) << (((uint8_t)(7))))))

/*
 * Encodes the lower 4 bits into a 8 bit unsigned integer.
 * The results are guaranteed to have a hamming distance of at least 4.
 */
#define SECDED_4_BITS_TO_UNSIGNED_8 SECDED_8_4_ENCODE

/*
 * Encodes the lower 4 bits into a 8 bit signed integer.
 * The results are guaranteed to have a hamming distance of at least 4.
 */
#define SECDED_4_BITS_TO_SIGNED_8(v) ((int8_t)(SECDED_8_4_ENCODE((uint8_t)(v))))

/*
 * Encodes the lower 4 bits into a 8 bit unsigned integer, which is then
 * expanded to 16 bits.
 * The results are guaranteed to have a hamming distance of at least 8.
 */
#define SECDED_4_BITS_TO_UNSIGNED_16(v) (((((uint16_t)(SECDED_4_BITS_TO_UNSIGNED_8(v)))) << (((uint16_t)(8)))) | ((uint16_t)(SECDED_4_BITS_TO_UNSIGNED_8(v))))

/*
 * Encodes the lower 4 bits into a 8 bit signed integer, which is then
 * expanded to 16 bits.
 * The results are guaranteed to have a hamming distance of at least 8.
 */
#define SECDED_4_BITS_TO_SIGNED_16(v) (((((int16_t)(SECDED_4_BITS_TO_SIGNED_8(v)))) << (((int16_t)(8)))) | ((int16_t)(SECDED_4_BITS_TO_SIGNED_8(v))))

/*
 * Encodes the lower 4 bits into a 8 bit unsigned integer, which is then
 * expanded to 32 bits.
 * The results are guaranteed to have a hamming distance of at least 16.
 */
#define SECDED_4_BITS_TO_UNSIGNED_32(v) (((((uint32_t)(SECDED_4_BITS_TO_UNSIGNED_16(v)))) << (((uint32_t)(16)))) | ((uint32_t)(SECDED_4_BITS_TO_UNSIGNED_16(v))))

/*
 * Encodes the lower 4 bits into a 8 bit signed integer, which is then
 * expanded to 32 bits.
 * The results are guaranteed to have a hamming distance of at least 16.
 */
#define SECDED_4_BITS_TO_SIGNED_32(v) (((((int32_t)(SECDED_4_BITS_TO_SIGNED_16(v)))) << (((int32_t)(16)))) | ((int32_t)(SECDED_4_BITS_TO_SIGNED_16(v))))

/*
 * Encodes the lower 4 bits into a 8 bit unsigned integer, which is then
 * expanded to 64 bits.
 * The results are guaranteed to have a hamming distance of at least 32.
 */
#define SECDED_4_BITS_TO_UNSIGNED_64(v) (((((uint64_t)(SECDED_4_BITS_TO_UNSIGNED_32(v)))) << (((uint64_t)(32)))) | ((uint64_t)(SECDED_4_BITS_TO_UNSIGNED_32(v))))

/*
 * Encodes the lower 4 bits into a 8 bit signed integer, which is then
 * expanded to 64 bits.
 * The results are guaranteed to have a hamming distance of at least 32.
 */
#define SECDED_4_BITS_TO_SIGNED_64(v) (((((int64_t)(SECDED_4_BITS_TO_SIGNED_32(v)))) << (((int64_t)(32)))) | ((int64_t)(SECDED_4_BITS_TO_SIGNED_32(v))))

/*
 * SECDED code for m = 4, n = 16, k = 11.
 *
 * (5x16) parity check matrix:
 *
 *   1 1 0 1 1 1 0 1 0 1 0 1 0 0 0 0
 *   1 1 0 1 0 0 1 1 1 0 1 0 1 0 0 0
 *   1 0 1 0 1 1 1 1 1 0 0 0 0 1 0 0
 *   1 1 1 0 1 0 0 0 1 1 1 0 0 0 1 0
 *   1 0 1 1 0 1 1 0 0 1 1 0 0 0 0 1
 */
#define SECDED_16_11_ENCODE(v) ((uint16_t)(((uint16_t)(v)) | (((((v) & ((((uint16_t)(1))) << (((uint16_t)(0))))) >> (((uint16_t)(0)))) ^ (((v) & ((((uint16_t)(1))) << (((uint16_t)(1))))) >> (((uint16_t)(1)))) ^ (((v) & ((((uint16_t)(1))) << (((uint16_t)(3))))) >> (((uint16_t)(3)))) ^ (((v) & ((((uint16_t)(1))) << (((uint16_t)(4))))) >> (((uint16_t)(4)))) ^ (((v) & ((((uint16_t)(1))) << (((uint16_t)(5))))) >> (((uint16_t)(5)))) ^ (((v) & ((((uint16_t)(1))) << (((uint16_t)(7))))) >> (((uint16_t)(7)))) ^ (((v) & ((((uint16_t)(1))) << (((uint16_t)(9))))) >> (((uint16_t)(9))))) << (((uint16_t)(11)))) | (((((v) & ((((uint16_t)(1))) << (((uint16_t)(0))))) >> (((uint16_t)(0)))) ^ (((v) & ((((uint16_t)(1))) << (((uint16_t)(1))))) >> (((uint16_t)(1)))) ^ (((v) & ((((uint16_t)(1))) << (((uint16_t)(3))))) >> (((uint16_t)(3)))) ^ (((v) & ((((uint16_t)(1))) << (((uint16_t)(6))))) >> (((uint16_t)(6)))) ^ (((v) & ((((uint16_t)(1))) << (((uint16_t)(7))))) >> (((uint16_t)(7)))) ^ (((v) & ((((uint16_t)(1))) << (((uint16_t)(8))))) >> (((uint16_t)(8)))) ^ (((v) & ((((uint16_t)(1))) << (((uint16_t)(10))))) >> (((uint16_t)(10))))) << (((uint16_t)(12)))) | (((((v) & ((((uint16_t)(1))) << (((uint16_t)(0))))) >> (((uint16_t)(0)))) ^ (((v) & ((((uint16_t)(1))) << (((uint16_t)(2))))) >> (((uint16_t)(2)))) ^ (((v) & ((((uint16_t)(1))) << (((uint16_t)(4))))) >> (((uint16_t)(4)))) ^ (((v) & ((((uint16_t)(1))) << (((uint16_t)(5))))) >> (((uint16_t)(5)))) ^ (((v) & ((((uint16_t)(1))) << (((uint16_t)(6))))) >> (((uint16_t)(6)))) ^ (((v) & ((((uint16_t)(1))) << (((uint16_t)(7))))) >> (((uint16_t)(7)))) ^ (((v) & ((((uint16_t)(1))) << (((uint16_t)(8))))) >> (((uint16_t)(8))))) << (((uint16_t)(13)))) | (((((v) & ((((uint16_t)(1))) << (((uint16_t)(0))))) >> (((uint16_t)(0)))) ^ (((v) & ((((uint16_t)(1))) << (((uint16_t)(1))))) >> (((uint16_t)(1)))) ^ (((v) & ((((uint16_t)(1))) << (((uint16_t)(2))))) >> (((uint16_t)(2)))) ^ (((v) & ((((uint16_t)(1))) << (((uint16_t)(4))))) >> (((uint16_t)(4)))) ^ (((v) & ((((uint16_t)(1))) << (((uint16_t)(8))))) >> (((uint16_t)(8)))) ^ (((v) & ((((uint16_t)(1))) << (((uint16_t)(9))))) >> (((uint16_t)(9)))) ^ (((v) & ((((uint16_t)(1))) << (((uint16_t)(10))))) >> (((uint16_t)(10))))) << (((uint16_t)(14)))) | (((((v) & ((((uint16_t)(1))) << (((uint16_t)(0))))) >> (((uint16_t)(0)))) ^ (((v) & ((((uint16_t)(1))) << (((uint16_t)(2))))) >> (((uint16_t)(2)))) ^ (((v) & ((((uint16_t)(1))) << (((uint16_t)(3))))) >> (((uint16_t)(3)))) ^ (((v) & ((((uint16_t)(1))) << (((uint16_t)(5))))) >> (((uint16_t)(5)))) ^ (((v) & ((((uint16_t)(1))) << (((uint16_t)(6))))) >> (((uint16_t)(6)))) ^ (((v) & ((((uint16_t)(1))) << (((uint16_t)(9))))) >> (((uint16_t)(9)))) ^ (((v) & ((((uint16_t)(1))) << (((uint16_t)(10))))) >> (((uint16_t)(10))))) << (((uint16_t)(15))))))

/*
 * Encodes the lower 11 bits into a 16 bit unsigned integer.
 * The results are guaranteed to have a hamming distance of at least 4.
 */
#define SECDED_11_BITS_TO_UNSIGNED_16 SECDED_16_11_ENCODE

/*
 * Encodes the lower 11 bits into a 16 bit signed integer.
 * The results are guaranteed to have a hamming distance of at least 4.
 */
#define SECDED_11_BITS_TO_SIGNED_16(v) ((int16_t)(SECDED_16_11_ENCODE((uint16_t)(v))))

/*
 * Encodes the lower 11 bits into a 16 bit unsigned integer, which is then
 * expanded to 32 bits.
 * The results are guaranteed to have a hamming distance of at least 8.
 */
#define SECDED_11_BITS_TO_UNSIGNED_32(v) (((((uint32_t)(SECDED_11_BITS_TO_UNSIGNED_16(v)))) << (((uint32_t)(16)))) | ((uint32_t)(SECDED_11_BITS_TO_UNSIGNED_16(v))))

/*
 * Encodes the lower 11 bits into a 16 bit signed integer, which is then
 * expanded to 32 bits.
 * The results are guaranteed to have a hamming distance of at least 8.
 */
#define SECDED_11_BITS_TO_SIGNED_32(v) (((((int32_t)(SECDED_11_BITS_TO_SIGNED_16(v)))) << (((int32_t)(16)))) | ((int32_t)(SECDED_11_BITS_TO_SIGNED_16(v))))

/*
 * Encodes the lower 11 bits into a 16 bit unsigned integer, which is then
 * expanded to 64 bits.
 * The results are guaranteed to have a hamming distance of at least 16.
 */
#define SECDED_11_BITS_TO_UNSIGNED_64(v) (((((uint64_t)(SECDED_11_BITS_TO_UNSIGNED_32(v)))) << (((uint64_t)(32)))) | ((uint64_t)(SECDED_11_BITS_TO_UNSIGNED_32(v))))

/*
 * Encodes the lower 11 bits into a 16 bit signed integer, which is then
 * expanded to 64 bits.
 * The results are guaranteed to have a hamming distance of at least 16.
 */
#define SECDED_11_BITS_TO_SIGNED_64(v) (((((int64_t)(SECDED_11_BITS_TO_SIGNED_32(v)))) << (((int64_t)(32)))) | ((int64_t)(SECDED_11_BITS_TO_SIGNED_32(v))))

/*
 * SECDED code for m = 5, n = 32, k = 26.
 *
 * (6x32) parity check matrix:
 *
 *   1 0 1 1 0 1 0 1 1 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 1 0 0 0 0 0
 *   1 1 1 1 0 0 1 1 0 0 1 1 0 0 1 1 1 0 1 1 0 0 1 1 0 0 0 1 0 0 0 0
 *   1 0 0 0 1 1 1 1 1 0 0 0 1 1 1 1 1 0 0 0 1 1 1 1 0 0 0 0 1 0 0 0
 *   1 1 1 0 1 0 0 0 1 1 1 1 1 1 1 1 1 0 0 0 0 0 0 0 1 1 0 0 0 1 0 0
 *   1 1 1 0 1 0 0 0 1 0 0 0 0 0 0 0 1 1 1 1 1 1 1 1 1 1 0 0 0 0 1 0
 *   0 0 1 1 0 1 1 0 1 1 1 0 1 0 0 1 1 1 1 0 1 0 0 1 1 0 0 0 0 0 0 1
 */
#define SECDED_32_26_ENCODE(v) ((uint32_t)(((uint32_t)(v)) | (((((v) & ((((uint32_t)(1))) << (((uint32_t)(0))))) >> (((uint32_t)(0)))) ^ (((v) & ((((uint32_t)(1))) << (((uint32_t)(2))))) >> (((uint32_t)(2)))) ^ (((v) & ((((uint32_t)(1))) << (((uint32_t)(3))))) >> (((uint32_t)(3)))) ^ (((v) & ((((uint32_t)(1))) << (((uint32_t)(5))))) >> (((uint32_t)(5)))) ^ (((v) & ((((uint32_t)(1))) << (((uint32_t)(7))))) >> (((uint32_t)(7)))) ^ (((v) & ((((uint32_t)(1))) << (((uint32_t)(8))))) >> (((uint32_t)(8)))) ^ (((v) & ((((uint32_t)(1))) << (((uint32_t)(9))))) >> (((uint32_t)(9)))) ^ (((v) & ((((uint32_t)(1))) << (((uint32_t)(11))))) >> (((uint32_t)(11)))) ^ (((v) & ((((uint32_t)(1))) << (((uint32_t)(13))))) >> (((uint32_t)(13)))) ^ (((v) & ((((uint32_t)(1))) << (((uint32_t)(15))))) >> (((uint32_t)(15)))) ^ (((v) & ((((uint32_t)(1))) << (((uint32_t)(17))))) >> (((uint32_t)(17)))) ^ (((v) & ((((uint32_t)(1))) << (((uint32_t)(19))))) >> (((uint32_t)(19)))) ^ (((v) & ((((uint32_t)(1))) << (((uint32_t)(21))))) >> (((uint32_t)(21)))) ^ (((v) & ((((uint32_t)(1))) << (((uint32_t)(23))))) >> (((uint32_t)(23)))) ^ (((v) & ((((uint32_t)(1))) << (((uint32_t)(25))))) >> (((uint32_t)(25))))) << (((uint32_t)(26)))) | (((((v) & ((((uint32_t)(1))) << (((uint32_t)(0))))) >> (((uint32_t)(0)))) ^ (((v) & ((((uint32_t)(1))) << (((uint32_t)(1))))) >> (((uint32_t)(1)))) ^ (((v) & ((((uint32_t)(1))) << (((uint32_t)(2))))) >> (((uint32_t)(2)))) ^ (((v) & ((((uint32_t)(1))) << (((uint32_t)(3))))) >> (((uint32_t)(3)))) ^ (((v) & ((((uint32_t)(1))) << (((uint32_t)(6))))) >> (((uint32_t)(6)))) ^ (((v) & ((((uint32_t)(1))) << (((uint32_t)(7))))) >> (((uint32_t)(7)))) ^ (((v) & ((((uint32_t)(1))) << (((uint32_t)(10))))) >> (((uint32_t)(10)))) ^ (((v) & ((((uint32_t)(1))) << (((uint32_t)(11))))) >> (((uint32_t)(11)))) ^ (((v) & ((((uint32_t)(1))) << (((uint32_t)(14))))) >> (((uint32_t)(14)))) ^ (((v) & ((((uint32_t)(1))) << (((uint32_t)(15))))) >> (((uint32_t)(15)))) ^ (((v) & ((((uint32_t)(1))) << (((uint32_t)(16))))) >> (((uint32_t)(16)))) ^ (((v) & ((((uint32_t)(1))) << (((uint32_t)(18))))) >> (((uint32_t)(18)))) ^ (((v) & ((((uint32_t)(1))) << (((uint32_t)(19))))) >> (((uint32_t)(19)))) ^ (((v) & ((((uint32_t)(1))) << (((uint32_t)(22))))) >> (((uint32_t)(22)))) ^ (((v) & ((((uint32_t)(1))) << (((uint32_t)(23))))) >> (((uint32_t)(23))))) << (((uint32_t)(27)))) | (((((v) & ((((uint32_t)(1))) << (((uint32_t)(0))))) >> (((uint32_t)(0)))) ^ (((v) & ((((uint32_t)(1))) << (((uint32_t)(4))))) >> (((uint32_t)(4)))) ^ (((v) & ((((uint32_t)(1))) << (((uint32_t)(5))))) >> (((uint32_t)(5)))) ^ (((v) & ((((uint32_t)(1))) << (((uint32_t)(6))))) >> (((uint32_t)(6)))) ^ (((v) & ((((uint32_t)(1))) << (((uint32_t)(7))))) >> (((uint32_t)(7)))) ^ (((v) & ((((uint32_t)(1))) << (((uint32_t)(8))))) >> (((uint32_t)(8)))) ^ (((v) & ((((uint32_t)(1))) << (((uint32_t)(12))))) >> (((uint32_t)(12)))) ^ (((v) & ((((uint32_t)(1))) << (((uint32_t)(13))))) >> (((uint32_t)(13)))) ^ (((v) & ((((uint32_t)(1))) << (((uint32_t)(14))))) >> (((uint32_t)(14)))) ^ (((v) & ((((uint32_t)(1))) << (((uint32_t)(15))))) >> (((uint32_t)(15)))) ^ (((v) & ((((uint32_t)(1))) << (((uint32_t)(16))))) >> (((uint32_t)(16)))) ^ (((v) & ((((uint32_t)(1))) << (((uint32_t)(20))))) >> (((uint32_t)(20)))) ^ (((v) & ((((uint32_t)(1))) << (((uint32_t)(21))))) >> (((uint32_t)(21)))) ^ (((v) & ((((uint32_t)(1))) << (((uint32_t)(22))))) >> (((uint32_t)(22)))) ^ (((v) & ((((uint32_t)(1))) << (((uint32_t)(23))))) >> (((uint32_t)(23))))) << (((uint32_t)(28)))) | (((((v) & ((((uint32_t)(1))) << (((uint32_t)(0))))) >> (((uint32_t)(0)))) ^ (((v) & ((((uint32_t)(1))) << (((uint32_t)(1))))) >> (((uint32_t)(1)))) ^ (((v) & ((((uint32_t)(1))) << (((uint32_t)(2))))) >> (((uint32_t)(2)))) ^ (((v) & ((((uint32_t)(1))) << (((uint32_t)(4))))) >> (((uint32_t)(4)))) ^ (((v) & ((((uint32_t)(1))) << (((uint32_t)(8))))) >> (((uint32_t)(8)))) ^ (((v) & ((((uint32_t)(1))) << (((uint32_t)(9))))) >> (((uint32_t)(9)))) ^ (((v) & ((((uint32_t)(1))) << (((uint32_t)(10))))) >> (((uint32_t)(10)))) ^ (((v) & ((((uint32_t)(1))) << (((uint32_t)(11))))) >> (((uint32_t)(11)))) ^ (((v) & ((((uint32_t)(1))) << (((uint32_t)(12))))) >> (((uint32_t)(12)))) ^ (((v) & ((((uint32_t)(1))) << (((uint32_t)(13))))) >> (((uint32_t)(13)))) ^ (((v) & ((((uint32_t)(1))) << (((uint32_t)(14))))) >> (((uint32_t)(14)))) ^ (((v) & ((((uint32_t)(1))) << (((uint32_t)(15))))) >> (((uint32_t)(15)))) ^ (((v) & ((((uint32_t)(1))) << (((uint32_t)(16))))) >> (((uint32_t)(16)))) ^ (((v) & ((((uint32_t)(1))) << (((uint32_t)(24))))) >> (((uint32_t)(24)))) ^ (((v) & ((((uint32_t)(1))) << (((uint32_t)(25))))) >> (((uint32_t)(25))))) << (((uint32_t)(29)))) | (((((v) & ((((uint32_t)(1))) << (((uint32_t)(0))))) >> (((uint32_t)(0)))) ^ (((v) & ((((uint32_t)(1))) << (((uint32_t)(1))))) >> (((uint32_t)(1)))) ^ (((v) & ((((uint32_t)(1))) << (((uint32_t)(2))))) >> (((uint32_t)(2)))) ^ (((v) & ((((uint32_t)(1))) << (((uint32_t)(4))))) >> (((uint32_t)(4)))) ^ (((v) & ((((uint32_t)(1))) << (((uint32_t)(8))))) >> (((uint32_t)(8)))) ^ (((v) & ((((uint32_t)(1))) << (((uint32_t)(16))))) >> (((uint32_t)(16)))) ^ (((v) & ((((uint32_t)(1))) << (((uint32_t)(17))))) >> (((uint32_t)(17)))) ^ (((v) & ((((uint32_t)(1))) << (((uint32_t)(18))))) >> (((uint32_t)(18)))) ^ (((v) & ((((uint32_t)(1))) << (((uint32_t)(19))))) >> (((uint32_t)(19)))) ^ (((v) & ((((uint32_t)(1))) << (((uint32_t)(20))))) >> (((uint32_t)(20)))) ^ (((v) & ((((uint32_t)(1))) << (((uint32_t)(21))))) >> (((uint32_t)(21)))) ^ (((v) & ((((uint32_t)(1))) << (((uint32_t)(22))))) >> (((uint32_t)(22)))) ^ (((v) & ((((uint32_t)(1))) << (((uint32_t)(23))))) >> (((uint32_t)(23)))) ^ (((v) & ((((uint32_t)(1))) << (((uint32_t)(24))))) >> (((uint32_t)(24)))) ^ (((v) & ((((uint32_t)(1))) << (((uint32_t)(25))))) >> (((uint32_t)(25))))) << (((uint32_t)(30)))) | (((((v) & ((((uint32_t)(1))) << (((uint32_t)(2))))) >> (((uint32_t)(2)))) ^ (((v) & ((((uint32_t)(1))) << (((uint32_t)(3))))) >> (((uint32_t)(3)))) ^ (((v) & ((((uint32_t)(1))) << (((uint32_t)(5))))) >> (((uint32_t)(5)))) ^ (((v) & ((((uint32_t)(1))) << (((uint32_t)(6))))) >> (((uint32_t)(6)))) ^ (((v) & ((((uint32_t)(1))) << (((uint32_t)(8))))) >> (((uint32_t)(8)))) ^ (((v) & ((((uint32_t)(1))) << (((uint32_t)(9))))) >> (((uint32_t)(9)))) ^ (((v) & ((((uint32_t)(1))) << (((uint32_t)(10))))) >> (((uint32_t)(10)))) ^ (((v) & ((((uint32_t)(1))) << (((uint32_t)(12))))) >> (((uint32_t)(12)))) ^ (((v) & ((((uint32_t)(1))) << (((uint32_t)(15))))) >> (((uint32_t)(15)))) ^ (((v) & ((((uint32_t)(1))) << (((uint32_t)(16))))) >> (((uint32_t)(16)))) ^ (((v) & ((((uint32_t)(1))) << (((uint32_t)(17))))) >> (((uint32_t)(17)))) ^ (((v) & ((((uint32_t)(1))) << (((uint32_t)(18))))) >> (((uint32_t)(18)))) ^ (((v) & ((((uint32_t)(1))) << (((uint32_t)(20))))) >> (((uint32_t)(20)))) ^ (((v) & ((((uint32_t)(1))) << (((uint32_t)(23))))) >> (((uint32_t)(23)))) ^ (((v) & ((((uint32_t)(1))) << (((uint32_t)(24))))) >> (((uint32_t)(24))))) << (((uint32_t)(31))))))

/*
 * Encodes the lower 26 bits into a 32 bit unsigned integer.
 * The results are guaranteed to have a hamming distance of at least 4.
 */
#define SECDED_26_BITS_TO_UNSIGNED_32 SECDED_32_26_ENCODE

/*
 * Encodes the lower 26 bits into a 32 bit signed integer.
 * The results are guaranteed to have a hamming distance of at least 4.
 */
#define SECDED_26_BITS_TO_SIGNED_32(v) ((int32_t)(SECDED_32_26_ENCODE((uint32_t)(v))))

/*
 * Encodes the lower 26 bits into a 32 bit unsigned integer, which is then
 * expanded to 64 bits.
 * The results are guaranteed to have a hamming distance of at least 8.
 */
#define SECDED_26_BITS_TO_UNSIGNED_64(v) (((((uint64_t)(SECDED_26_BITS_TO_UNSIGNED_32(v)))) << (((uint64_t)(32)))) | ((uint64_t)(SECDED_26_BITS_TO_UNSIGNED_32(v))))

/*
 * Encodes the lower 26 bits into a 32 bit signed integer, which is then
 * expanded to 64 bits.
 * The results are guaranteed to have a hamming distance of at least 8.
 */
#define SECDED_26_BITS_TO_SIGNED_64(v) (((((int64_t)(SECDED_26_BITS_TO_SIGNED_32(v)))) << (((int64_t)(32)))) | ((int64_t)(SECDED_26_BITS_TO_SIGNED_32(v))))

/*
 * SECDED code for m = 6, n = 64, k = 57.
 *
 * (7x64) parity check matrix:
 *
 *   1 1 0 1 1 1 0 1 0 1 0 1 0 1 0 1 1 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 0 0 0 0 0
 *   1 0 1 1 1 0 1 1 0 0 1 1 0 0 1 1 0 0 1 1 0 0 1 1 0 0 1 1 0 0 1 1 1 0 1 1 0 0 1 1 0 0 1 1 0 0 1 1 0 0 1 1 0 0 1 1 0 0 1 0 0 0 0 0
 *   1 0 0 0 0 1 1 1 1 0 0 0 1 1 1 1 1 0 0 0 1 1 1 1 0 0 0 0 1 1 1 1 1 0 0 0 1 1 1 1 0 0 0 0 1 1 1 1 0 0 0 0 1 1 1 1 0 0 0 1 0 0 0 0
 *   1 1 1 0 1 0 0 0 1 1 1 1 1 1 1 1 1 0 0 0 0 0 0 0 1 1 1 1 1 1 1 1 1 0 0 0 0 0 0 0 1 1 1 1 1 1 1 1 0 0 0 0 0 0 0 0 1 0 0 0 1 0 0 0
 *   1 1 1 0 1 0 0 0 1 0 0 0 0 0 0 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 1 1 1 1 1 1 1 0 0 0 0 1 0 0
 *   1 1 1 0 1 0 0 0 1 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 0 0 0 1 0
 *   1 1 1 1 0 1 1 0 1 1 1 0 1 0 0 1 0 1 1 0 1 0 0 1 1 0 0 1 0 1 1 0 0 1 1 0 1 0 0 1 1 0 0 1 0 1 1 0 1 0 0 1 0 1 1 0 0 0 0 0 0 0 0 1
 */
#define SECDED_64_57_ENCODE(v) ((uint64_t)(((uint64_t)(v)) | (((((v) & ((((uint64_t)(1))) << (((uint64_t)(0))))) >> (((uint64_t)(0)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(1))))) >> (((uint64_t)(1)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(3))))) >> (((uint64_t)(3)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(4))))) >> (((uint64_t)(4)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(5))))) >> (((uint64_t)(5)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(7))))) >> (((uint64_t)(7)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(9))))) >> (((uint64_t)(9)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(11))))) >> (((uint64_t)(11)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(13))))) >> (((uint64_t)(13)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(15))))) >> (((uint64_t)(15)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(16))))) >> (((uint64_t)(16)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(17))))) >> (((uint64_t)(17)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(19))))) >> (((uint64_t)(19)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(21))))) >> (((uint64_t)(21)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(23))))) >> (((uint64_t)(23)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(25))))) >> (((uint64_t)(25)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(27))))) >> (((uint64_t)(27)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(29))))) >> (((uint64_t)(29)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(31))))) >> (((uint64_t)(31)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(33))))) >> (((uint64_t)(33)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(35))))) >> (((uint64_t)(35)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(37))))) >> (((uint64_t)(37)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(39))))) >> (((uint64_t)(39)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(41))))) >> (((uint64_t)(41)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(43))))) >> (((uint64_t)(43)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(45))))) >> (((uint64_t)(45)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(47))))) >> (((uint64_t)(47)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(49))))) >> (((uint64_t)(49)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(51))))) >> (((uint64_t)(51)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(53))))) >> (((uint64_t)(53)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(55))))) >> (((uint64_t)(55))))) << (((uint64_t)(57)))) | (((((v) & ((((uint64_t)(1))) << (((uint64_t)(0))))) >> (((uint64_t)(0)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(2))))) >> (((uint64_t)(2)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(3))))) >> (((uint64_t)(3)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(4))))) >> (((uint64_t)(4)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(6))))) >> (((uint64_t)(6)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(7))))) >> (((uint64_t)(7)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(10))))) >> (((uint64_t)(10)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(11))))) >> (((uint64_t)(11)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(14))))) >> (((uint64_t)(14)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(15))))) >> (((uint64_t)(15)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(18))))) >> (((uint64_t)(18)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(19))))) >> (((uint64_t)(19)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(22))))) >> (((uint64_t)(22)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(23))))) >> (((uint64_t)(23)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(26))))) >> (((uint64_t)(26)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(27))))) >> (((uint64_t)(27)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(30))))) >> (((uint64_t)(30)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(31))))) >> (((uint64_t)(31)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(32))))) >> (((uint64_t)(32)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(34))))) >> (((uint64_t)(34)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(35))))) >> (((uint64_t)(35)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(38))))) >> (((uint64_t)(38)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(39))))) >> (((uint64_t)(39)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(42))))) >> (((uint64_t)(42)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(43))))) >> (((uint64_t)(43)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(46))))) >> (((uint64_t)(46)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(47))))) >> (((uint64_t)(47)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(50))))) >> (((uint64_t)(50)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(51))))) >> (((uint64_t)(51)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(54))))) >> (((uint64_t)(54)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(55))))) >> (((uint64_t)(55))))) << (((uint64_t)(58)))) | (((((v) & ((((uint64_t)(1))) << (((uint64_t)(0))))) >> (((uint64_t)(0)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(5))))) >> (((uint64_t)(5)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(6))))) >> (((uint64_t)(6)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(7))))) >> (((uint64_t)(7)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(8))))) >> (((uint64_t)(8)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(12))))) >> (((uint64_t)(12)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(13))))) >> (((uint64_t)(13)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(14))))) >> (((uint64_t)(14)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(15))))) >> (((uint64_t)(15)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(16))))) >> (((uint64_t)(16)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(20))))) >> (((uint64_t)(20)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(21))))) >> (((uint64_t)(21)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(22))))) >> (((uint64_t)(22)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(23))))) >> (((uint64_t)(23)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(28))))) >> (((uint64_t)(28)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(29))))) >> (((uint64_t)(29)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(30))))) >> (((uint64_t)(30)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(31))))) >> (((uint64_t)(31)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(32))))) >> (((uint64_t)(32)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(36))))) >> (((uint64_t)(36)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(37))))) >> (((uint64_t)(37)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(38))))) >> (((uint64_t)(38)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(39))))) >> (((uint64_t)(39)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(44))))) >> (((uint64_t)(44)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(45))))) >> (((uint64_t)(45)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(46))))) >> (((uint64_t)(46)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(47))))) >> (((uint64_t)(47)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(52))))) >> (((uint64_t)(52)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(53))))) >> (((uint64_t)(53)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(54))))) >> (((uint64_t)(54)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(55))))) >> (((uint64_t)(55))))) << (((uint64_t)(59)))) | (((((v) & ((((uint64_t)(1))) << (((uint64_t)(0))))) >> (((uint64_t)(0)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(1))))) >> (((uint64_t)(1)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(2))))) >> (((uint64_t)(2)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(4))))) >> (((uint64_t)(4)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(8))))) >> (((uint64_t)(8)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(9))))) >> (((uint64_t)(9)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(10))))) >> (((uint64_t)(10)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(11))))) >> (((uint64_t)(11)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(12))))) >> (((uint64_t)(12)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(13))))) >> (((uint64_t)(13)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(14))))) >> (((uint64_t)(14)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(15))))) >> (((uint64_t)(15)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(16))))) >> (((uint64_t)(16)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(24))))) >> (((uint64_t)(24)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(25))))) >> (((uint64_t)(25)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(26))))) >> (((uint64_t)(26)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(27))))) >> (((uint64_t)(27)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(28))))) >> (((uint64_t)(28)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(29))))) >> (((uint64_t)(29)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(30))))) >> (((uint64_t)(30)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(31))))) >> (((uint64_t)(31)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(32))))) >> (((uint64_t)(32)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(40))))) >> (((uint64_t)(40)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(41))))) >> (((uint64_t)(41)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(42))))) >> (((uint64_t)(42)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(43))))) >> (((uint64_t)(43)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(44))))) >> (((uint64_t)(44)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(45))))) >> (((uint64_t)(45)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(46))))) >> (((uint64_t)(46)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(47))))) >> (((uint64_t)(47)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(56))))) >> (((uint64_t)(56))))) << (((uint64_t)(60)))) | (((((v) & ((((uint64_t)(1))) << (((uint64_t)(0))))) >> (((uint64_t)(0)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(1))))) >> (((uint64_t)(1)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(2))))) >> (((uint64_t)(2)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(4))))) >> (((uint64_t)(4)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(8))))) >> (((uint64_t)(8)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(16))))) >> (((uint64_t)(16)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(17))))) >> (((uint64_t)(17)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(18))))) >> (((uint64_t)(18)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(19))))) >> (((uint64_t)(19)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(20))))) >> (((uint64_t)(20)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(21))))) >> (((uint64_t)(21)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(22))))) >> (((uint64_t)(22)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(23))))) >> (((uint64_t)(23)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(24))))) >> (((uint64_t)(24)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(25))))) >> (((uint64_t)(25)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(26))))) >> (((uint64_t)(26)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(27))))) >> (((uint64_t)(27)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(28))))) >> (((uint64_t)(28)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(29))))) >> (((uint64_t)(29)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(30))))) >> (((uint64_t)(30)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(31))))) >> (((uint64_t)(31)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(32))))) >> (((uint64_t)(32)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(48))))) >> (((uint64_t)(48)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(49))))) >> (((uint64_t)(49)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(50))))) >> (((uint64_t)(50)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(51))))) >> (((uint64_t)(51)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(52))))) >> (((uint64_t)(52)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(53))))) >> (((uint64_t)(53)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(54))))) >> (((uint64_t)(54)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(55))))) >> (((uint64_t)(55)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(56))))) >> (((uint64_t)(56))))) << (((uint64_t)(61)))) | (((((v) & ((((uint64_t)(1))) << (((uint64_t)(0))))) >> (((uint64_t)(0)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(1))))) >> (((uint64_t)(1)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(2))))) >> (((uint64_t)(2)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(4))))) >> (((uint64_t)(4)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(8))))) >> (((uint64_t)(8)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(16))))) >> (((uint64_t)(16)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(32))))) >> (((uint64_t)(32)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(33))))) >> (((uint64_t)(33)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(34))))) >> (((uint64_t)(34)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(35))))) >> (((uint64_t)(35)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(36))))) >> (((uint64_t)(36)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(37))))) >> (((uint64_t)(37)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(38))))) >> (((uint64_t)(38)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(39))))) >> (((uint64_t)(39)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(40))))) >> (((uint64_t)(40)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(41))))) >> (((uint64_t)(41)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(42))))) >> (((uint64_t)(42)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(43))))) >> (((uint64_t)(43)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(44))))) >> (((uint64_t)(44)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(45))))) >> (((uint64_t)(45)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(46))))) >> (((uint64_t)(46)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(47))))) >> (((uint64_t)(47)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(48))))) >> (((uint64_t)(48)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(49))))) >> (((uint64_t)(49)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(50))))) >> (((uint64_t)(50)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(51))))) >> (((uint64_t)(51)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(52))))) >> (((uint64_t)(52)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(53))))) >> (((uint64_t)(53)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(54))))) >> (((uint64_t)(54)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(55))))) >> (((uint64_t)(55)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(56))))) >> (((uint64_t)(56))))) << (((uint64_t)(62)))) | (((((v) & ((((uint64_t)(1))) << (((uint64_t)(0))))) >> (((uint64_t)(0)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(1))))) >> (((uint64_t)(1)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(2))))) >> (((uint64_t)(2)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(3))))) >> (((uint64_t)(3)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(5))))) >> (((uint64_t)(5)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(6))))) >> (((uint64_t)(6)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(8))))) >> (((uint64_t)(8)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(9))))) >> (((uint64_t)(9)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(10))))) >> (((uint64_t)(10)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(12))))) >> (((uint64_t)(12)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(15))))) >> (((uint64_t)(15)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(17))))) >> (((uint64_t)(17)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(18))))) >> (((uint64_t)(18)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(20))))) >> (((uint64_t)(20)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(23))))) >> (((uint64_t)(23)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(24))))) >> (((uint64_t)(24)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(27))))) >> (((uint64_t)(27)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(29))))) >> (((uint64_t)(29)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(30))))) >> (((uint64_t)(30)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(33))))) >> (((uint64_t)(33)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(34))))) >> (((uint64_t)(34)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(36))))) >> (((uint64_t)(36)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(39))))) >> (((uint64_t)(39)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(40))))) >> (((uint64_t)(40)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(43))))) >> (((uint64_t)(43)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(45))))) >> (((uint64_t)(45)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(46))))) >> (((uint64_t)(46)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(48))))) >> (((uint64_t)(48)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(51))))) >> (((uint64_t)(51)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(53))))) >> (((uint64_t)(53)))) ^ (((v) & ((((uint64_t)(1))) << (((uint64_t)(54))))) >> (((uint64_t)(54))))) << (((uint64_t)(63))))))

/*
 * Encodes the lower 57 bits into a 64 bit unsigned integer.
 * The results are guaranteed to have a hamming distance of at least 4.
 */
#define SECDED_57_BITS_TO_UNSIGNED_64 SECDED_64_57_ENCODE

/*
 * Encodes the lower 57 bits into a 64 bit signed integer.
 * The results are guaranteed to have a hamming distance of at least 4.
 */
#define SECDED_57_BITS_TO_SIGNED_64(v) ((int64_t)(SECDED_64_57_ENCODE((uint64_t)(v))))

#endif  /* CONSTEXPR_SECDED_H */
