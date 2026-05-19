#include <criterion/criterion.h>

typedef struct prime_stream prime_stream_t;

prime_stream_t *prime_stream_new(void);
unsigned prime_stream_next(prime_stream_t *);
void prime_stream_destroy(prime_stream_t *);

Test(example_tests, should_generate_first_primes) {
  prime_stream_t *stream = prime_stream_new();
  cr_assert_eq(prime_stream_next(stream), 2);
  cr_assert_eq(prime_stream_next(stream), 3);
  cr_assert_eq(prime_stream_next(stream), 5);
  cr_assert_eq(prime_stream_next(stream), 7);
  cr_assert_eq(prime_stream_next(stream), 11);
  cr_assert_eq(prime_stream_next(stream), 13);
  cr_assert_eq(prime_stream_next(stream), 17);
  cr_assert_eq(prime_stream_next(stream), 19);
  cr_assert_eq(prime_stream_next(stream), 23);
  cr_assert_eq(prime_stream_next(stream), 29);
  prime_stream_destroy(stream);
}
