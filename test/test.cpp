#include "../include/constexpr-secded.h"

#ifdef NDEBUG
# error "Do not specify NDEBUG for tests."
#endif
#include <cassert>

#define COMPILE_TIME_CHECK(x) static_assert(x, "Assertion failed")

#include "generated-test-vectors.h"

#define TEST_VECTOR(fn, input, expected) \
  COMPILE_TIME_CHECK(fn(input) == expected);
#define TEST_VECTOR_8_4(input, expected) \
  TEST_VECTOR(secded_encode_4_bits<uint8_t>, input, expected)
#define TEST_VECTOR_16_11(input, expected) \
  TEST_VECTOR(secded_encode_11_bits<uint16_t>, input, expected)
#define TEST_VECTOR_32_26(input, expected) \
  TEST_VECTOR(secded_encode_26_bits<uint32_t>, input, expected)
#define TEST_VECTOR_64_57(input, expected) \
  TEST_VECTOR(secded_encode_57_bits<uint64_t>, input, expected)

static void test_generated_test_vectors(void) {
  TEST_VECTORS_8_4(TEST_VECTOR_8_4)
  TEST_VECTORS_16_11(TEST_VECTOR_16_11)
  TEST_VECTORS_32_26(TEST_VECTOR_32_26)
  TEST_VECTORS_64_57(TEST_VECTOR_64_57)
}

static void test_functions_are_constexpr() {
  enum class foo_u8 : std::uint8_t {
    v = secded_encode_4_bits<std::uint8_t>(1)
  };

  COMPILE_TIME_CHECK(
      static_cast<std::underlying_type<foo_u8>::type>(foo_u8::v) ==
          SECDED_8_4_ENCODE(1));

  enum class foo_u64 : std::uint64_t {
    v = secded_encode_57_bits<std::uint64_t>(1),
    e = secded_encode_4_bits<std::uint32_t>(1)
  };

  COMPILE_TIME_CHECK(
      static_cast<std::underlying_type<foo_u64>::type>(foo_u64::v) ==
          SECDED_64_57_ENCODE(1));
  COMPILE_TIME_CHECK(
      static_cast<std::underlying_type<foo_u64>::type>(foo_u64::e) ==
          SECDED_4_BITS_TO_UNSIGNED_32(1));
}

#if __cplusplus >= 201402L
# define CXX14_CONSTEXPR constexpr
# define CXX14_COMPILE_TIME_CHECK COMPILE_TIME_CHECK
#else
# define CXX14_CONSTEXPR
# define CXX14_COMPILE_TIME_CHECK assert
#endif

static CXX14_CONSTEXPR uint8_t encode_does_double_eval() {
  uint8_t double_eval = 1;
  secded_encode_4_bits<uint64_t>(--double_eval);
  return double_eval;
}

static void test_functions_are_real_functions() {
  CXX14_COMPILE_TIME_CHECK(encode_does_double_eval() == 0);
}

int main(void) {
  test_generated_test_vectors();
  test_functions_are_constexpr();
  test_functions_are_real_functions();
  return 0;
}
