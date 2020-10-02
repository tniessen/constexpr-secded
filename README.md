# constexpr-secded

This is a header-only library that implements SECDED encoding through constant
expressions only, and was designed to enhance memory safety for low-level
systems with high memory error rates.

The implementation relies on Hamming codes with an additional parity bit. The
respective parity check matrices are listed in [the code](constexpr-secded.h).

The code complies with the C89, C99, C11, C++11, C++14, and C++17 standards.

## C++ functions

These functions can be used in C++11 and newer.

<!---cpp start--->

#### `constexpr std::uint8_t secded_encode_4_bits<std::uint8_t>(std::uint8_t v)`

> Encodes the lowest 4 bits of an unsigned integer into a 8-bit unsigned integer.
>
> If the argument `v` is a constant expression, then the call to this function is a constant expression as well.
>
> For `x != y`, applying this function to `x` and `y` separately will result in two values that differ in at least 4 bits.

#### `constexpr std::uint16_t secded_encode_4_bits<std::uint16_t>(std::uint8_t v)`

> Encodes the lowest 4 bits of an unsigned integer into a 8-bit unsigned integer, which is then expanded to a 16-bit unsigned integer.
>
> If the argument `v` is a constant expression, then the call to this function is a constant expression as well.
>
> For `x != y`, applying this function to `x` and `y` separately will result in two values that differ in at least 8 bits, and these differences are distributed across at least 2 bytes.

#### `constexpr std::uint32_t secded_encode_4_bits<std::uint32_t>(std::uint8_t v)`

> Encodes the lowest 4 bits of an unsigned integer into a 8-bit unsigned integer, which is then expanded to a 32-bit unsigned integer.
>
> If the argument `v` is a constant expression, then the call to this function is a constant expression as well.
>
> For `x != y`, applying this function to `x` and `y` separately will result in two values that differ in at least 16 bits, and these differences are distributed across at least 4 bytes.

#### `constexpr std::uint64_t secded_encode_4_bits<std::uint64_t>(std::uint8_t v)`

> Encodes the lowest 4 bits of an unsigned integer into a 8-bit unsigned integer, which is then expanded to a 64-bit unsigned integer.
>
> If the argument `v` is a constant expression, then the call to this function is a constant expression as well.
>
> For `x != y`, applying this function to `x` and `y` separately will result in two values that differ in at least 32 bits, and these differences are distributed across at least 8 bytes.

#### `constexpr std::int8_t secded_encode_4_bits<std::int8_t>(std::int8_t v)`

> Encodes the lowest 4 bits of a signed integer into a 8-bit signed integer.
>
> If the argument `v` is a constant expression, then the call to this function is a constant expression as well.
>
> For `x != y`, applying this function to `x` and `y` separately will result in two values that differ in at least 4 bits.

#### `constexpr std::int16_t secded_encode_4_bits<std::int16_t>(std::int8_t v)`

> Encodes the lowest 4 bits of a signed integer into a 8-bit signed integer, which is then expanded to a 16-bit signed integer.
>
> If the argument `v` is a constant expression, then the call to this function is a constant expression as well.
>
> For `x != y`, applying this function to `x` and `y` separately will result in two values that differ in at least 8 bits, and these differences are distributed across at least 2 bytes.

#### `constexpr std::int32_t secded_encode_4_bits<std::int32_t>(std::int8_t v)`

> Encodes the lowest 4 bits of a signed integer into a 8-bit signed integer, which is then expanded to a 32-bit signed integer.
>
> If the argument `v` is a constant expression, then the call to this function is a constant expression as well.
>
> For `x != y`, applying this function to `x` and `y` separately will result in two values that differ in at least 16 bits, and these differences are distributed across at least 4 bytes.

#### `constexpr std::int64_t secded_encode_4_bits<std::int64_t>(std::int8_t v)`

> Encodes the lowest 4 bits of a signed integer into a 8-bit signed integer, which is then expanded to a 64-bit signed integer.
>
> If the argument `v` is a constant expression, then the call to this function is a constant expression as well.
>
> For `x != y`, applying this function to `x` and `y` separately will result in two values that differ in at least 32 bits, and these differences are distributed across at least 8 bytes.

#### `constexpr std::uint16_t secded_encode_11_bits<std::uint16_t>(std::uint16_t v)`

> Encodes the lowest 11 bits of an unsigned integer into a 16-bit unsigned integer.
>
> If the argument `v` is a constant expression, then the call to this function is a constant expression as well.
>
> For `x != y`, applying this function to `x` and `y` separately will result in two values that differ in at least 4 bits.

#### `constexpr std::uint32_t secded_encode_11_bits<std::uint32_t>(std::uint16_t v)`

> Encodes the lowest 11 bits of an unsigned integer into a 16-bit unsigned integer, which is then expanded to a 32-bit unsigned integer.
>
> If the argument `v` is a constant expression, then the call to this function is a constant expression as well.
>
> For `x != y`, applying this function to `x` and `y` separately will result in two values that differ in at least 8 bits, and these differences are distributed across at least 2 bytes.

#### `constexpr std::uint64_t secded_encode_11_bits<std::uint64_t>(std::uint16_t v)`

> Encodes the lowest 11 bits of an unsigned integer into a 16-bit unsigned integer, which is then expanded to a 64-bit unsigned integer.
>
> If the argument `v` is a constant expression, then the call to this function is a constant expression as well.
>
> For `x != y`, applying this function to `x` and `y` separately will result in two values that differ in at least 16 bits, and these differences are distributed across at least 4 bytes.

#### `constexpr std::int16_t secded_encode_11_bits<std::int16_t>(std::int16_t v)`

> Encodes the lowest 11 bits of a signed integer into a 16-bit signed integer.
>
> If the argument `v` is a constant expression, then the call to this function is a constant expression as well.
>
> For `x != y`, applying this function to `x` and `y` separately will result in two values that differ in at least 4 bits.

#### `constexpr std::int32_t secded_encode_11_bits<std::int32_t>(std::int16_t v)`

> Encodes the lowest 11 bits of a signed integer into a 16-bit signed integer, which is then expanded to a 32-bit signed integer.
>
> If the argument `v` is a constant expression, then the call to this function is a constant expression as well.
>
> For `x != y`, applying this function to `x` and `y` separately will result in two values that differ in at least 8 bits, and these differences are distributed across at least 2 bytes.

#### `constexpr std::int64_t secded_encode_11_bits<std::int64_t>(std::int16_t v)`

> Encodes the lowest 11 bits of a signed integer into a 16-bit signed integer, which is then expanded to a 64-bit signed integer.
>
> If the argument `v` is a constant expression, then the call to this function is a constant expression as well.
>
> For `x != y`, applying this function to `x` and `y` separately will result in two values that differ in at least 16 bits, and these differences are distributed across at least 4 bytes.

#### `constexpr std::uint32_t secded_encode_26_bits<std::uint32_t>(std::uint32_t v)`

> Encodes the lowest 26 bits of an unsigned integer into a 32-bit unsigned integer.
>
> If the argument `v` is a constant expression, then the call to this function is a constant expression as well.
>
> For `x != y`, applying this function to `x` and `y` separately will result in two values that differ in at least 4 bits.

#### `constexpr std::uint64_t secded_encode_26_bits<std::uint64_t>(std::uint32_t v)`

> Encodes the lowest 26 bits of an unsigned integer into a 32-bit unsigned integer, which is then expanded to a 64-bit unsigned integer.
>
> If the argument `v` is a constant expression, then the call to this function is a constant expression as well.
>
> For `x != y`, applying this function to `x` and `y` separately will result in two values that differ in at least 8 bits, and these differences are distributed across at least 2 bytes.

#### `constexpr std::int32_t secded_encode_26_bits<std::int32_t>(std::int32_t v)`

> Encodes the lowest 26 bits of a signed integer into a 32-bit signed integer.
>
> If the argument `v` is a constant expression, then the call to this function is a constant expression as well.
>
> For `x != y`, applying this function to `x` and `y` separately will result in two values that differ in at least 4 bits.

#### `constexpr std::int64_t secded_encode_26_bits<std::int64_t>(std::int32_t v)`

> Encodes the lowest 26 bits of a signed integer into a 32-bit signed integer, which is then expanded to a 64-bit signed integer.
>
> If the argument `v` is a constant expression, then the call to this function is a constant expression as well.
>
> For `x != y`, applying this function to `x` and `y` separately will result in two values that differ in at least 8 bits, and these differences are distributed across at least 2 bytes.

#### `constexpr std::uint64_t secded_encode_57_bits<std::uint64_t>(std::uint64_t v)`

> Encodes the lowest 57 bits of an unsigned integer into a 64-bit unsigned integer.
>
> If the argument `v` is a constant expression, then the call to this function is a constant expression as well.
>
> For `x != y`, applying this function to `x` and `y` separately will result in two values that differ in at least 4 bits.

#### `constexpr std::int64_t secded_encode_57_bits<std::int64_t>(std::int64_t v)`

> Encodes the lowest 57 bits of a signed integer into a 64-bit signed integer.
>
> If the argument `v` is a constant expression, then the call to this function is a constant expression as well.
>
> For `x != y`, applying this function to `x` and `y` separately will result in two values that differ in at least 4 bits.

<!---cpp end--->

## C/C++ macros

These macros can be used in C89 and newer. C++ code should use the safer C++
functions above instead.

<!---macros start--->

#### `SECDED_4_BITS_TO_UNSIGNED_8(v)`

> Encodes the lowest 4 bits of an unsigned integer into a 8-bit unsigned integer.
>
> Be aware that this is a macro that may evaluate `v` multiple times.
>
> For `x != y`, applying this macro to `x` and `y` separately will result in two values that differ in at least 4 bits.

#### `SECDED_4_BITS_TO_SIGNED_8(v)`

> Encodes the lowest 4 bits of a signed integer into a 8-bit signed integer.
>
> Be aware that this is a macro that may evaluate `v` multiple times.
>
> For `x != y`, applying this macro to `x` and `y` separately will result in two values that differ in at least 4 bits.

#### `SECDED_4_BITS_TO_UNSIGNED_16(v)`

> Encodes the lowest 4 bits of an unsigned integer into a 8-bit unsigned integer, which is then expanded to a 16-bit unsigned integer.
>
> Be aware that this is a macro that may evaluate `v` multiple times.
>
> For `x != y`, applying this macro to `x` and `y` separately will result in two values that differ in at least 8 bits, and these differences are distributed across at least 2 bytes.

#### `SECDED_4_BITS_TO_SIGNED_16(v)`

> Encodes the lowest 4 bits of a signed integer into a 8-bit signed integer, which is then expanded to a 16-bit signed integer.
>
> Be aware that this is a macro that may evaluate `v` multiple times.
>
> For `x != y`, applying this macro to `x` and `y` separately will result in two values that differ in at least 8 bits, and these differences are distributed across at least 2 bytes.

#### `SECDED_4_BITS_TO_UNSIGNED_32(v)`

> Encodes the lowest 4 bits of an unsigned integer into a 8-bit unsigned integer, which is then expanded to a 32-bit unsigned integer.
>
> Be aware that this is a macro that may evaluate `v` multiple times.
>
> For `x != y`, applying this macro to `x` and `y` separately will result in two values that differ in at least 16 bits, and these differences are distributed across at least 4 bytes.

#### `SECDED_4_BITS_TO_SIGNED_32(v)`

> Encodes the lowest 4 bits of a signed integer into a 8-bit signed integer, which is then expanded to a 32-bit signed integer.
>
> Be aware that this is a macro that may evaluate `v` multiple times.
>
> For `x != y`, applying this macro to `x` and `y` separately will result in two values that differ in at least 16 bits, and these differences are distributed across at least 4 bytes.

#### `SECDED_4_BITS_TO_UNSIGNED_64(v)`

> Encodes the lowest 4 bits of an unsigned integer into a 8-bit unsigned integer, which is then expanded to a 64-bit unsigned integer.
>
> Be aware that this is a macro that may evaluate `v` multiple times.
>
> For `x != y`, applying this macro to `x` and `y` separately will result in two values that differ in at least 32 bits, and these differences are distributed across at least 8 bytes.

#### `SECDED_4_BITS_TO_SIGNED_64(v)`

> Encodes the lowest 4 bits of a signed integer into a 8-bit signed integer, which is then expanded to a 64-bit signed integer.
>
> Be aware that this is a macro that may evaluate `v` multiple times.
>
> For `x != y`, applying this macro to `x` and `y` separately will result in two values that differ in at least 32 bits, and these differences are distributed across at least 8 bytes.

#### `SECDED_11_BITS_TO_UNSIGNED_16(v)`

> Encodes the lowest 11 bits of an unsigned integer into a 16-bit unsigned integer.
>
> Be aware that this is a macro that may evaluate `v` multiple times.
>
> For `x != y`, applying this macro to `x` and `y` separately will result in two values that differ in at least 4 bits.

#### `SECDED_11_BITS_TO_SIGNED_16(v)`

> Encodes the lowest 11 bits of a signed integer into a 16-bit signed integer.
>
> Be aware that this is a macro that may evaluate `v` multiple times.
>
> For `x != y`, applying this macro to `x` and `y` separately will result in two values that differ in at least 4 bits.

#### `SECDED_11_BITS_TO_UNSIGNED_32(v)`

> Encodes the lowest 11 bits of an unsigned integer into a 16-bit unsigned integer, which is then expanded to a 32-bit unsigned integer.
>
> Be aware that this is a macro that may evaluate `v` multiple times.
>
> For `x != y`, applying this macro to `x` and `y` separately will result in two values that differ in at least 8 bits, and these differences are distributed across at least 2 bytes.

#### `SECDED_11_BITS_TO_SIGNED_32(v)`

> Encodes the lowest 11 bits of a signed integer into a 16-bit signed integer, which is then expanded to a 32-bit signed integer.
>
> Be aware that this is a macro that may evaluate `v` multiple times.
>
> For `x != y`, applying this macro to `x` and `y` separately will result in two values that differ in at least 8 bits, and these differences are distributed across at least 2 bytes.

#### `SECDED_11_BITS_TO_UNSIGNED_64(v)`

> Encodes the lowest 11 bits of an unsigned integer into a 16-bit unsigned integer, which is then expanded to a 64-bit unsigned integer.
>
> Be aware that this is a macro that may evaluate `v` multiple times.
>
> For `x != y`, applying this macro to `x` and `y` separately will result in two values that differ in at least 16 bits, and these differences are distributed across at least 4 bytes.

#### `SECDED_11_BITS_TO_SIGNED_64(v)`

> Encodes the lowest 11 bits of a signed integer into a 16-bit signed integer, which is then expanded to a 64-bit signed integer.
>
> Be aware that this is a macro that may evaluate `v` multiple times.
>
> For `x != y`, applying this macro to `x` and `y` separately will result in two values that differ in at least 16 bits, and these differences are distributed across at least 4 bytes.

#### `SECDED_26_BITS_TO_UNSIGNED_32(v)`

> Encodes the lowest 26 bits of an unsigned integer into a 32-bit unsigned integer.
>
> Be aware that this is a macro that may evaluate `v` multiple times.
>
> For `x != y`, applying this macro to `x` and `y` separately will result in two values that differ in at least 4 bits.

#### `SECDED_26_BITS_TO_SIGNED_32(v)`

> Encodes the lowest 26 bits of a signed integer into a 32-bit signed integer.
>
> Be aware that this is a macro that may evaluate `v` multiple times.
>
> For `x != y`, applying this macro to `x` and `y` separately will result in two values that differ in at least 4 bits.

#### `SECDED_26_BITS_TO_UNSIGNED_64(v)`

> Encodes the lowest 26 bits of an unsigned integer into a 32-bit unsigned integer, which is then expanded to a 64-bit unsigned integer.
>
> Be aware that this is a macro that may evaluate `v` multiple times.
>
> For `x != y`, applying this macro to `x` and `y` separately will result in two values that differ in at least 8 bits, and these differences are distributed across at least 2 bytes.

#### `SECDED_26_BITS_TO_SIGNED_64(v)`

> Encodes the lowest 26 bits of a signed integer into a 32-bit signed integer, which is then expanded to a 64-bit signed integer.
>
> Be aware that this is a macro that may evaluate `v` multiple times.
>
> For `x != y`, applying this macro to `x` and `y` separately will result in two values that differ in at least 8 bits, and these differences are distributed across at least 2 bytes.

#### `SECDED_57_BITS_TO_UNSIGNED_64(v)`

> Encodes the lowest 57 bits of an unsigned integer into a 64-bit unsigned integer.
>
> Be aware that this is a macro that may evaluate `v` multiple times.
>
> For `x != y`, applying this macro to `x` and `y` separately will result in two values that differ in at least 4 bits.

#### `SECDED_57_BITS_TO_SIGNED_64(v)`

> Encodes the lowest 57 bits of a signed integer into a 64-bit signed integer.
>
> Be aware that this is a macro that may evaluate `v` multiple times.
>
> For `x != y`, applying this macro to `x` and `y` separately will result in two values that differ in at least 4 bits.

<!---macros end--->
