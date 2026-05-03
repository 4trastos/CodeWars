#include <criterion/criterion.h>

char *factorial(int);

Test(the_factorial_function, should_work_for_small_numbers) {
  cr_assert_str_eq(factorial(1), "1");
  cr_assert_str_eq(factorial(5), "120");
  cr_assert_str_eq(factorial(9), "362880");
  cr_assert_str_eq(factorial(15), "1307674368000");
}