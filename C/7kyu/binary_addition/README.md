Implement a function that adds two numbers together and returns their sum in binary. The conversion can be done before, or after the addition.

The binary number returned should be a string.

**Examples:(Input1, Input2 --> Output (explanation))**
```bash
1, 1 --> "10" (1 + 1 = 2 in decimal or 10 in binary)
5, 9 --> "1110" (5 + 9 = 14 in decimal or 1110 in binary)
```

**Test:**
```bash
Test(tests_suite, sample_tests)
{
	do_test(1, 2, "11");
	do_test(51, 12, "111111");
	do_test(100, 0, "1100100");
	do_test(0, 0, "0");
	do_test(UINT_MAX, UINT_MAX, "111111111111111111111111111111110");
}
```

**attemp**:

```bash
Time: 664ms Passed: 2Failed: 0
Test Results:
tests_suite
fixed_tests
Test Passed
Completed in 0.9406ms
random_tests
Test Passed
Completed in 12.6772ms
Completed in 13.6179ms
You have passed all of the tests! :) 
``