Create a function that takes a Roman numeral as its argument and returns its value as a numeric decimal integer. You don't need to validate the form of the Roman numeral.

Modern Roman numerals are written by expressing each decimal digit of the number to be encoded separately, starting with the leftmost digit and skipping any 0s. So 1990 is rendered "MCMXC" (1000 = M, 900 = CM, 90 = XC) and 2008 is rendered "MMVIII" (2000 = MM, 8 = VIII). The Roman numeral for 1666, "MDCLXVI", uses each letter in descending order.

**Example:**
```bash
"MM"      -> 2000
"MDCLXVI" -> 1666
"M"       -> 1000
"CD"      ->  400
"XC"      ->   90
"XL"      ->   40
"I"       ->    1
```
**Help:**
```bash
Symbol    Value
I          1
V          5
X          10
L          50
C          100
D          500
M          1,000
``
Courtesy of rosettacode.org


**Test:**
```bash
Test(tests_suite, sample_tests)
{
	do_test("I", 1);
	do_test("IV", 4);
	do_test("MCD", 1400);
	do_test("XXVII", 27);
	do_test("DCXXXIV", 634);
	do_test("MMVI", 2006);
	do_test("XXXIX", 39);

	//Historical Test Cases :)

	//The fall of the Western Roman Empire:
	do_test("CDLXXVI", 476);
	//The fall of the Byzantine Empire:
	do_test("MCDLIII", 1453);
	// Cristopher Columbus "Discovers" America
	do_test("MCDXCII", 1492);
}
```

```bash
Test Results:
tests_suite
fixed_tests
Test Passed
Completed in 1.7160ms
random_tests
Test Passed
Completed in 14.4885ms
Completed in 16.2046ms
You have passed all of the tests! :) 
``