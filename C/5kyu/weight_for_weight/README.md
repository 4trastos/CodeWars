My friend John and I are members of the "Fat to Fit Club (FFC)". John is worried because each month a list with the weights of members is published and each month he is the last on the list which means he is the heaviest.

I am the one who establishes the list so I told him: "Don't worry any more, I will modify the order of the list". It was decided to attribute a "weight" to numbers. The weight of a number will be from now on the sum of its digits.

For example 99 will have "weight" 18, 100 will have "weight" 1 so in the list 100 will come before 99.

Given a string with the weights of FFC members in normal order can you give this string ordered by "weights" of these numbers?
**Example:**
```bash
"56 65 74 100 99 68 86 180 90" ordered by numbers weights becomes: 

"100 180 90 56 65 74 68 86 99"
```
When two numbers have the same "weight", let us class them as if they were strings (alphabetical ordering) and not numbers:

180 is before 90 since, having the same "weight" (9), it comes before as a string.

All numbers in the list are positive numbers and the list can be empty.
Notes

   - it may happen that the input string have leading, trailing whitespaces and more than a unique whitespace between two consecutive numbers
   - For C: The result is freed.

**PROTOTYPE:**
```c
#include <stdlib.h>

char *orderWeight(const char *string)
{
    // return a heap-allocated string
    return calloc(1, 1);
}
```
--- 

**TEST:**
```c
Test(tests_suite, fixed_tests)
{
	doTest(
		"103 123 4444 99 2000",
		"2000 103 123 4444 99"
	);
	doTest(
		"      103     123     4444     99    2000     ",
		"2000 103 123 4444 99"
	);
	doTest(
		"2000 10003 1234000 44444444 9999 11 11 22 123",
		"11 11 2000 10003 22 123 1234000 44444444 9999"
	);
	doTest(
		"10003 1234000 44444444 9999 2000 123456789",
		"2000 10003 1234000 44444444 9999 123456789"
	);
	doTest(
		"3 16 9 38 95 1131268 49455 347464 59544965313 496636983114762 85246814996697",
		"3 16 9 38 95 1131268 49455 347464 59544965313 496636983114762 85246814996697"
	);
	doTest(
		"71899703 200 6 91 425 4 67407 7 96488 6 4 2 7 31064 9 7920 1 34608557 27 72 18 81",
		"1 2 200 4 4 6 6 7 7 18 27 72 81 9 91 425 31064 7920 67407 96488 34608557 71899703"
	);
	doTest(
		"387087 176 351832 100 430372 8 58052 54 175432 120 269974 147 309754 91 404858 67 271476 164 295747 111 40",
		"100 111 120 40 8 54 91 164 147 67 176 430372 58052 175432 351832 271476 309754 404858 387087 295747 269974"
	);
}
```
```bash
Test Results:
tests_suite
fixed_tests
Test Passed
Completed in 1.2487ms
random_tests
Test Passed
Completed in 27.1381ms
Completed in 28.3868ms
You have passed all of the tests! :) 
```