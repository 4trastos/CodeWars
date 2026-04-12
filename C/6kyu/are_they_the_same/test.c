#include <stdio.h>
#include <stdbool.h>
#include <criterion/criterion.h>

static void dotest (size_t n, const int a[/*n*/], const int b[/*n*/], bool expected);

#define ARR_LEN(array) (sizeof(array) / sizeof *(array))

#define fixedTest(a, b, expected) dotest(ARR_LEN(a), a, b, expected)

Test(comp, SampleTests) {
    fixedTest(((int[])
        {-121, 144, -19, 161, -19, 144, 19, -11}), ((int[])
        {14641, 20736, 361, 25921, 361, 20736, 361, 121}),
    true);

    fixedTest(((int[])
        {-121, 144, -19, 161, 19, -144, 19, 11}), ((int[])
        {14641, 20736, 361, 25921, 361, 20736, 362, 121}),
    false);

    fixedTest(((int[])
        {121, -144, -19, 161, 19, -144, 19, 11, -1008}), ((int[])
        {14641, 20736, 361, 25921, 361, 20736, 362, 121, 12340}),
    false);

    fixedTest(((int[])
        {121, -1440, 191, -161, 19, -144, 195, 11}), ((int[])
        {121, 14641, 2073600, 36481, 25921, 361, 20736, 38025}),
    true);

    fixedTest(((int[])
        {-2, -2, -3}), ((int[])
        {4, 4, 9}),
    true);

    fixedTest(((int[])
        {-2, -2, -3}), ((int[])
        {4, 9, 9}),
    false);

    fixedTest(((int[])
        { 0, 0, -2, -1, 0 }), ((int[])
        { 0, 0, 2, -3, 0 }),
    false);

    fixedTest(((int[])
        { 3, 4 }), ((int[])
        { -16, -9 }),
    false);

    fixedTest(((int[])
        { 4, 4 }), ((int[])
        { 1, 31 }),
    false);
}

extern bool comp(const int a[/*n*/], const int b[/*n*/], size_t n);

static void printArray (size_t length, const int array[/* length */]) {
    printf("{");
    for (size_t i = 0; i < length; i++)
        printf("%d%s", array[i], (i == length - 1) ? "" : ", ");
    printf("}");
}

static void dotest (size_t n, const int a[/*n*/], const int b[/*n*/], bool expected) {
    bool actual = comp(a, b, n);
    if (actual != expected) {
        printf("a = ");
        printArray(n, a);
        printf("\nb = ");
        printArray(n, b);
        printf("\n");
        fflush(stdout);
    }
    cr_assert_eq(actual, expected,
        "expected %s, but got %s",
        expected ? "true" : "false", actual ? "true" : "false"
    );
}