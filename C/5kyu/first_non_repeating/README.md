Write a function that takes a string input, and returns the first character that is not repeated anywhere in the string.

For example, if given the input "stress", the function should return 't', since the letter t only occurs once in the string, and occurs first in the string.

As an added challenge, upper- and lowercase characters are considered the same character, but the function should return the correct case for the initial character. For example, the input "sTreSS" should return "T".

If a string contains only repeating characters, return an empty string ("");

**Note:** despite its name in some languages, your function should handle any Unicode codepoint:

```bash
"@#@@*"    --> "#"
"かか何"    --> "何"
"🐐🦊🐐"   --> "🦊"
"sTreSS"   --> "T"
```
```bash
// The input is UTF-8-encoded
// Your output shall be as well
// Be ready for non-ASCII codepoints
// Write your answer to `output`, and nul-terminate `output`
// If there are no non-repeating codepoints in the input,
// make `output` an empty string.
// Because the C standard library's Unicode support is limited,
// you are not required to handle differing lower/upper forms
// outside of the ASCII range; in other words, treat two
// non-ASCII codepoints as different if they are not numerically identical.

void first_non_repeating_codepoint(char output[4 + 1], const char *utf8)
{
    *output = '\0';
}
```

```bash
Test Results:
test_suite
fixed_tests_ascii
Test Passed
Completed in 2.2308ms
fixed_tests_unicode
Test Passed
Completed in 0.9698ms
random_tests
Test Passed
Completed in 15.2626ms
Completed in 18.4632ms
You have passed all of the tests! :) 
``