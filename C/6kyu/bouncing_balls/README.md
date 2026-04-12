A child is playing with a ball on the nth floor of a tall building. The height of this floor above ground level, h, is known.

He drops the ball out of the window. The ball bounces (for example), to two-thirds of its height (a bounce of 0.66).

His mother looks out of a window 1.5 meters from the ground.

How many times will the mother see the ball pass in front of her window (including when it's falling and bouncing)?
Three conditions must be met for a valid experiment:

    - Float parameter "h" in meters must be greater than 0
    - Float parameter "bounce" must be greater than 0 and less than 1
    - Float parameter "window" must be less than h.

If all three conditions above are fulfilled, return a positive integer, otherwise return -1.
Note:

The ball can only be seen if the height of the rebounding ball is strictly greater than the window parameter.
**Examples:**
```bash
- h = 3, bounce = 0.66, window = 1.5, result is 3

- h = 3, bounce = 1, window = 1.5, result is -1 

(Condition 2) not fulfilled).
```

**TEST:**
```c
#include <criterion/criterion.h>

extern int bouncingBall (double h, double bounce, double window);
static void testequal(double h, double bounce, double window, int expected);

Test(bouncingBall, sampleTests) {       
    testequal(2, 0.5, 1.0, 1);
    testequal(3, 0.66, 1.5, 3);
    testequal(30, 0.66, 1.5, 15);
    testequal(30, 0.75, 1.5, 21);
    testequal(30, 0.4, 10, 3);
    testequal(40, 0.4, 10, 3);
    testequal(10, 0.6, 10, -1);
    testequal(40, 1, 10, -1);
    testequal(-5, 0.66, 1.5, -1);
    testequal(5, -1, 1.5, -1);
    testequal(4, 0.25, 1.0, 1);
}

static void testequal(double h, double bounce, double window, int expected) {
    int actual = bouncingBall(h, bounce, window);
    cr_assert_eq(actual, expected,
		"for h = %.17g, bounce = %.17g, window = %.17g\n"
		"expected %d, but got %d",
		h, bounce, window,
		expected, actual
	);
}
```

```bash
Test Results:
bouncingBall
fixedTests
Test Passed
Completed in 1.8121ms
randomTests
Test Passed
Completed in 11.8224ms
Completed in 13.6344ms
You have passed all of the tests! :) 
```