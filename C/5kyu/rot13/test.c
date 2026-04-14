#include <stdlib.h>
#include <string.h>
#include <criterion/criterion.h>

extern char *rot13(char *str_out, const char *str_in);
static void do_test(const char *input, const char *expected);

Test(tests_suite, sample_tests)
{
  do_test("EBG13 rknzcyr.", "ROT13 example.");
  do_test(
    "How can you tell an extrovert from an\nintrovert at NSA? Va gur ryringbef,\ngur rkgebireg ybbxf ng gur BGURE thl'f fubrf.",
    "Ubj pna lbh gryy na rkgebireg sebz na\nvagebireg ng AFN? In the elevators,\nthe extrovert looks at the OTHER guy's shoes."
  );
  do_test("123", "123");
  do_test(
    "Guvf vf npghnyyl gur svefg xngn V rire znqr. Gunaxf sbe svavfuvat vg! :)",
    "This is actually the first kata I ever made. Thanks for finishing it! :)"
  );
  do_test("@[`{", "@[`{");
}


static void do_test(const char *input, const char *expected)
{
  size_t mem_size = strlen(input) + 1;
  char *user_string = memset(malloc(mem_size), '@', mem_size);
  char *actual = rot13(user_string, input);

  if (actual != user_string)
    cr_assert_fail("you must return the given string");

  cr_assert_str_eq(actual, expected,
    "for string:\n\"%s\"\nexpected:\n\"%s\"\nbut got:\n\"%s\"",
    input, expected, actual
  );
  free(user_string);
}