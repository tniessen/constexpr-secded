#include "../include/constexpr-secded.h"

#ifdef NDEBUG
# error "Do not specify NDEBUG for tests."
#endif
#include <assert.h>

#ifdef static_assert
# define COMPILE_TIME_CHECK(x) static_assert(x, "Assertion failed")
#else
# define COMPILE_TIME_CHECK assert
#endif

#include "generated-test-vectors.h"

#define TEST_VECTOR(fn, input, expected) \
  COMPILE_TIME_CHECK(fn(input) == expected);
#define TEST_VECTOR_8_4(input, expected) \
  TEST_VECTOR(SECDED_8_4_ENCODE, input, expected)
#define TEST_VECTOR_16_11(input, expected) \
  TEST_VECTOR(SECDED_16_11_ENCODE, input, expected)
#define TEST_VECTOR_32_26(input, expected) \
  TEST_VECTOR(SECDED_32_26_ENCODE, input, expected)
#define TEST_VECTOR_64_57(input, expected) \
  TEST_VECTOR(SECDED_64_57_ENCODE, input, expected)

static void test_generated_test_vectors(void) {
  TEST_VECTORS_8_4(TEST_VECTOR_8_4)
  TEST_VECTORS_16_11(TEST_VECTOR_16_11)
  TEST_VECTORS_32_26(TEST_VECTOR_32_26)
  TEST_VECTORS_64_57(TEST_VECTOR_64_57)
}

static void test_additive_identity(void) {
  COMPILE_TIME_CHECK(SECDED_8_4_ENCODE(0) == 0);
  COMPILE_TIME_CHECK(SECDED_16_11_ENCODE(0) == 0);
  COMPILE_TIME_CHECK(SECDED_32_26_ENCODE(0) == 0);
  COMPILE_TIME_CHECK(SECDED_64_57_ENCODE(0) == 0);
}

static unsigned int weight(uint64_t v) {
  unsigned int n = 0;
  while ((n += v != 0) && (v &= v - 1));
  return n;
}

static unsigned int distance_u(uint64_t a, uint64_t b) {
  return weight(a ^ b);
}

static void test_8_bit_minimum_distance(void) {
  uint8_t i, j;
  for (i = 0; i <= 0xf; i++) {
    for (j = i + 1; j <= 0xf; j++) {
      assert(4 <= distance_u(SECDED_4_BITS_TO_UNSIGNED_8(i),
                             SECDED_4_BITS_TO_UNSIGNED_8(j)));
      assert(8 <= distance_u(SECDED_4_BITS_TO_UNSIGNED_16(i),
                             SECDED_4_BITS_TO_UNSIGNED_16(j)));
      assert(16 <= distance_u(SECDED_4_BITS_TO_UNSIGNED_32(i),
                              SECDED_4_BITS_TO_UNSIGNED_32(j)));
      assert(32 <= distance_u(SECDED_4_BITS_TO_UNSIGNED_64(i),
                              SECDED_4_BITS_TO_UNSIGNED_64(j)));
    }
  }
}

static void test_16_bit_minimum_distance(void) {
  uint16_t i, j;
  for (i = 0; i <= 0x7ff; i++) {
    for (j = i + 1; j <= 0x7ff; j++) {
      assert(4 <= distance_u(SECDED_11_BITS_TO_UNSIGNED_16(i),
                             SECDED_11_BITS_TO_UNSIGNED_16(j)));
      assert(8 <= distance_u(SECDED_11_BITS_TO_UNSIGNED_32(i),
                             SECDED_11_BITS_TO_UNSIGNED_32(j)));
      assert(16 <= distance_u(SECDED_11_BITS_TO_UNSIGNED_64(i),
                              SECDED_11_BITS_TO_UNSIGNED_64(j)));
    }
  }
}

static void test_32_bit_low_weight(void) {
  uint32_t i, v;
  for (i = 0; i < 26; i++) {
    v = SECDED_26_BITS_TO_UNSIGNED_32(1 << i);
    assert(4 <= v);
    assert(3 <= weight(v & ((uint32_t) 0x3f << 26)));
  }
}

static void test_64_bit_low_weight(void) {
  uint64_t i, v;
  for (i = 0; i < 57; i++) {
    v = SECDED_57_BITS_TO_UNSIGNED_64(1 << i);
    assert(4 <= v);
    assert(3 <= weight(v & ((uint64_t) 0x7f << 57)));
  }
}

int main(void) {
  test_generated_test_vectors();
  test_additive_identity();
  test_8_bit_minimum_distance();
  test_16_bit_minimum_distance();
  test_32_bit_low_weight();
  test_64_bit_low_weight();
  return 0;
}
