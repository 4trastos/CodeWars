#include <criterion/criterion.h>

long parse_int (const char* number);

void shouldBe (const char *number, long expected) {
  long result = parse_int (number);
  cr_assert_eq (result, expected, "While parsing '%s' expected %ld, got %ld instead", number, expected, result);
}

Test (parseint, sample) {
    shouldBe ("one", 1);
    shouldBe ("twenty", 20);
    shouldBe ("twenty one", 21);
    shouldBe ("two hundred and forty-six", 246);
    shouldBe ("one thousand three hundred and thirty-seven", 1337);
    shouldBe ("four thousand two hundred thirty-seven", 4237);
}