Implement a function that computes the difference between two lists. The function should remove all occurrences of elements from the first list (a) that are present in the second list (b). The order of elements in the first list should be preserved in the result.

**Examples**
```bash
If a = [1, 2] and b = [1], the result should be [2].

If a = [1, 2, 2, 2, 3] and b = [2], the result should be [1, 3].
NOTE:

In C, assign return array length to pointer *z
```

**PROTOTYPE:**
```c
#include <stddef.h>

//  assign the length of your array to *z
//  your returned array will be freed

int *array_diff(const int arr1[/* n1 */], size_t n1, const int arr2[/* n2 */], size_t n2, size_t *z) {

    //  <----  hajime!
    *z = 0;
    return NULL;
}
```

**TEST:**
```c
Test(should_pass_all_the_tests_provided, Sample_Tests) {
  {
    const int arr1[2] = {1, 2};
    const int arr2[1] = {1};
    const int expected[1] = {2};
    tester(2, arr1, 1, arr2, 1, expected);
  }
  {
    const int arr1[3] = {1, 2, 2};
    const int arr2[1] = {1};
    const int expected[2] = {2, 2};
    tester(3, arr1, 1, arr2, 2, expected);
  }
  {
    const int arr1[3] = {1, 2, 2};
    const int arr2[1] = {2};
    const int expected[1] = {1};
    tester(3, arr1, 1, arr2, 1, expected);
  }
  {
    const int arr1[3] = {1, 2, 2};
    const int *arr2 = NULL;
    const int expected[3] = {1, 2, 2};
    tester(3, arr1, 0, arr2, 3, expected);
  }
  {
    const int arr1[3] = {1, 2, 3};
    const int arr2[2] = {1, 2};
    const int expected[1] = {3};
    tester(3, arr1, 2, arr2, 1, expected);
  }
  {
    const int *arr1 = NULL;
    const int arr2[2] = {1, 2};
    const int *expected = NULL;
    tester(0, arr1, 2, arr2, 0, expected);
  }
  {
    const int arr1[5] = {1, 2, 3, 4, 5};
    const int arr2[3] = {1, 3, 4};
    const int expected[2] = {2, 5};
    tester(5, arr1, 3, arr2, 2, expected);
  }
}
```

```bash
Test Results:
should_pass_all_the_tests_provided
Fixed_Tests
Test Passed
Completed in 3.0987ms
Random_Tests
Test Passed
Completed in 34.9327ms
Completed in 38.0314ms
You have passed all of the tests! :) 
```