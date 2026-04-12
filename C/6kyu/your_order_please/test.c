#include <stdlib.h>
#include <string.h>
#include <criterion/criterion.h>

static void do_test (const char *input, const char *expected);

Test(tests_suite, sample_tests)
{
	do_test("is2 Thi1s T4est 3a", "Thi1s is2 3a T4est");
	do_test("4of Fo1r pe6ople g3ood th5e the2", "Fo1r the2 g3ood 4of th5e pe6ople");
	do_test("d4o dru7nken sh2all w5ith s8ailor wha1t 3we a6", "wha1t sh2all 3we d4o w5ith a6 dru7nken s8ailor");
	do_test("", "");
	do_test("3 6 4 2 8 7 5 1 9", "1 2 3 4 5 6 7 8 9");
}

extern char *order_words (char *ordered, const char *words);

static void do_test (const char *input, const char *expected)
{
	size_t size = 1 + strlen(input);
	char *user_string = memset(malloc(size), '@', size);
	char *actual = order_words(user_string, input);

	if (actual != user_string)
		cr_assert_fail("you must return the given string");

	cr_assert_str_eq(actual, expected,
		"for words:\n\"%s\"\nexpected:\n\"%s\"\nbut got:\n\"%s\"",
		input, expected, actual
	);
	free(user_string);
}