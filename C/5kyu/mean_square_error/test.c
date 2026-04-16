#include <criterion/criterion.h>
#include <stdlib.h>
#include <stdio.h>

double mean_square_error(size_t n, const int a[n], const int b[n]);
static void tester(size_t n, const int a[n], const int b[n], double expected);

Test(should_pass_all_the_tests_provided, Example_Tests) {
  {
    const int a[3] = {1, 2, 3};
    const int b[3] = {4, 5, 6};
    double expected = 9.0;
    tester(3, a, b, expected);
  }
  {
    const int a[4] = {10, 20, 10, 2};
    const int b[4] = {10, 25, 5, -2};
    double expected = 16.5;
    tester(4, a, b, expected);
  }
  {
    const int a[2] = {0, -1};
    const int b[2] = {-1, 0};
    double expected = 1.0;
    tester(2, a, b, expected);
  }
  {
    const int a[2] = {10, 10};
    const int b[2] = {10, 10};
    double expected = 0.0;
    tester(2, a, b, expected);
  }
}

static char *stringify_array(size_t n, const int array[n]) {
    char *s = malloc(sizeof "{  }" + n * (20 + sizeof ", " - 1)), *p = s;
    p += sprintf(p, "{ ");
    for (size_t i = 0; i < n; i++)
        p += sprintf(p, "%d%s", array[i], (i == n - 1) ? "" : ", ");
    p += sprintf(p, " }");
    return s;
}

static void tester(size_t n, const int arr_a[n], const int arr_b[n], double expected) {
    double submitted = mean_square_error(n, arr_a, arr_b);
    char *str_a = stringify_array(n, arr_a);
    char *str_b = stringify_array(n, arr_b);
    cr_assert_float_eq(submitted, expected, 1e-6,
        "arr_a = %s\n \narr_b = %s\n \nSubmitted: %.17g\nExpected:  %.17g",
        str_a, str_b, submitted, expected
    );
    free(str_a);
    free(str_b);
}