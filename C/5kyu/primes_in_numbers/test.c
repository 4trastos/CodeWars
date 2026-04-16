#include <stdlib.h>
#include <criterion/criterion.h>

extern char *factors(int n);
static void dotest(int n, const char *expected);

Test(tests_suite, sample_tests) {
    dotest(2, "(2)");
    dotest(1 << 30, "(2**30)");
    dotest(2 * 3 * 5 * 7 * 11 * 13 * 17 * 19 * 23, "(2)(3)(5)(7)(11)(13)(17)(19)(23)");
    dotest(7775460, "(2**2)(3**3)(5)(7)(11**2)(17)");
    dotest(7919, "(7919)");
    dotest(17 * 17 * 93 * 677, "(3)(17**2)(31)(677)");
    dotest(933555431, "(7537)(123863)");
    dotest(342217392, "(2**4)(3)(11)(43)(15073)");
    dotest(35791357, "(7)(5113051)");
    dotest(782611830, "(2)(3**2)(5)(7**2)(11)(13)(17)(73)");
    dotest(775878912, "(2**8)(3**4)(17)(31)(71)");
    dotest(483499306, "(2)(41**2)(143813)");
}

static void dotest(int n, const char *expected) {
    char *actual = factors(n);
    cr_assert_str_eq(actual, expected,
        "for n = %d\nexpected: \"%s\"\nbut got:  \"%s\"",
        n, expected, actual
    );
    free(actual);
}
