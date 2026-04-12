The main idea is to count all the occurring characters in a string. If you have a string like aba, then the result should be {'a': 2, 'b': 1}.

What if the string is empty? Then the result should be empty object literal, {}.

```c
#define COUNTS_SIZE 128

//  assign char counts to the provided pre-allocated array
//  pre-existing values in array aren't guaranteed to be 0
//  from test string: "aaa", counts['a'] should be == to 3

void count(const char *string, unsigned counts[COUNTS_SIZE]) {

    //  <----  hajime!

}
```

***TEST**
```c
Test(count, Sample_Tests) {
    {
        const unsigned expected[COUNTS_SIZE] = { ['a'] = 2, ['b'] = 1 };
        tester("aba", expected);
    }
    {
        const unsigned expected[COUNTS_SIZE] = { 0 };
        tester("", expected);
    }
    {
        const unsigned expected[COUNTS_SIZE] = { ['a'] = 2 };
        tester("aa", expected);
    }
    {
        const unsigned expected[COUNTS_SIZE] = { ['a'] = 2, ['b'] = 2 };
        tester("aabb", expected);
    }
}
```

```bash
Test Results:
count
Fixed_Tests
Test Passed
Completed in 1.2531ms
Random_Tests
Test Passed
Completed in 14.8624ms
Completed in 16.1156ms
You have passed all of the tests! :) 
```