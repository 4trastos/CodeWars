Usually when you buy something, you're asked whether your credit card number, phone number or answer to your most secret question is still correct. However, since someone could look over your shoulder, you don't want that shown on your screen. Instead, we mask it.

Your task is to write a function `maskify`, which changes all but the last four characters into `#`.

**Examples (input --> output):**

```bash
"4556364607935616" --> "############5616"
     "64607935616" -->      "#######5616"
               "1" -->                "1"
                "" -->                 ""

// "What was the name of your first pet?"
"Skippy" --> "##ippy"
"Nananananananananananananananana Batman!" --> "####################################man!"
```


**TEST**:
```bash
Test Results:
tests_suite
sample_tests
Test Passed
Completed in 1.7273ms
Completed in 1.7273ms
You have passed all of the tests! :)
```

**ATTEPMT:**
```bash
Time: 619ms Passed: 2Failed: 0
Test Results:
tests_suite
fixed_tests
Test Passed
Completed in 1.3578ms
random_tests
Test Passed
Completed in 12.4082ms
Completed in 13.7660ms
You have passed all of the tests! :) 
```
