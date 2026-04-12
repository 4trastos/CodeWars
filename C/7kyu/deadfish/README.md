Create a parser to interpret and execute the Deadfish language.

Deadfish operates on a single value in memory, which is initially set to 0.

It uses four single-character commands:

    i: Increment the value
    d: Decrement the value
    s: Square the value
    o: Output the value to a result array

All other instructions are no-ops and have no effect.

**Examples**
```bash
Program "iiisdoso" should return numbers [8, 64].
Program "iiisdosodddddiso" should return numbers [8, 64, 3600].
```
**PROTOTYPE:**
```c
int *parse (const char *program)
{
	// return a heap-allocated int array
	// its length shall be at least equal to
	// the count of 'o' commands in the program
	return NULL;
}
```

**TEST**:
```c
Test(tests_suite, sample_tests)
{
	fixed_test("ooo", ((int[]){0, 0, 0}));
	fixed_test("ioioio", ((int[]){1, 2, 3}));
	fixed_test("idoiido", ((int[]){0, 1}));
	fixed_test("isoisoiso", ((int[]){1, 4, 25}));
	fixed_test("codewars", ((int[]){0}));
	do_test("", 0, NULL);
}
```

```bash
Test Results:
tests_suite
random_tests
Test Passed
Completed in 14.9745ms
sample_tests
Test Passed
Completed in 1.1391ms
should_ignore_non_commands
Test Passed
Completed in 0.6768ms
should_not_crash_when_no_output
Test Passed
Completed in 0.5382ms
Completed in 17.3287ms
You have passed all of the tests! :) 
``