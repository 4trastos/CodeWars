Given two arrays of strings a1 and a2 return a sorted array r in lexicographical order of the strings of a1 which are substrings of strings of a2.

**Example 1:**
```bash
a1 = ["arp", "live", "strong"]
```
```bash
a2 = ["lively", "alive", "harp", "sharp", "armstrong"]
```
```bash
returns ["arp", "live", "strong"]
```
**Example 2:**
```bash
a1 = ["tarp", "mice", "bull"]
```
```bash
a2 = ["lively", "alive", "harp", "sharp", "armstrong"]
```
```bash
returns []
```
Notes:

    - Arrays are written in "general" notation. See "Your Test Cases" for examples in your language.
    - In Shell bash a1 and a2 are strings. The return is a string where words are separated by commas.
    - Beware: In some languages r must be without duplicates.

**PROTOTIPE:**
```c
const char **inArray(
    const char *const array1[/* sz1 */], int sz1,
    const char *const array2[/* sz2 */], int sz2,
    int *lg
) {
/*
    The strings in your array will NOT be freed; you can
    re-use those from `array1`.
*/
    *lg = 0; // report the length of your array
    return NULL; // return a free-able pointer
}
```

**TEST**:
```c
Test(inArray, ShouldPassAllTheTestsProvided) {
    {
        const char *arr1[] = { "arp", "live", "strong" };
        const char *arr2[] = { "lively", "alive", "harp", "sharp", "armstrong" };
        const char *expected[] = {"arp","live","strong"};
        dotest(ARR_LEN(arr1), arr1, ARR_LEN(arr2), arr2, ARR_LEN(expected), expected);
    }
    {
        const char *arr1[] = { "cod", "code", "wars", "ewar", "ar" };
        const char **arr2 = NULL;
        const char **expected = NULL;
        dotest(ARR_LEN(arr1), arr1, 0, arr2, 0, expected);
    }
    {
        const char *arr1[] = { "ohio", "code", "1346", "1028", "art" };
        const char *arr2[] = { "Carolina", "Ohio", "4600", "NY", "California" };
        const char **expected = NULL;
        dotest(ARR_LEN(arr1), arr1, ARR_LEN(arr2), arr2, 0, expected);
    }
}
```

```bash
Time: 790ms Passed: 1Failed: 0
Test Results:
inArray
ShouldPassAllTheTestsProvided
Test Passed
Completed in 2.0748ms
Completed in 2.0748ms
You have passed all of the tests! :) 
``