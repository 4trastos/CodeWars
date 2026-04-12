You live in the city of Cartesia where all roads are laid out in a perfect grid. You arrived ten minutes too early to an appointment, so you decided to take the opportunity to go for a short walk. The city provides its citizens with a Walk Generating App on their phones -- everytime you press the button it sends you an array of one-letter strings representing directions to walk (eg. ['n', 's', 'w', 'e']). You always walk only a single block for each letter (direction) and you know it takes you one minute to traverse one city block, so create a function that will return true if the walk the app gives you will take you exactly ten minutes (you don't want to be early or late!) and will, of course, return you to your starting point. Return false otherwise.

    Note: you will always receive a valid array containing a random assortment of direction letters ('n', 's', 'e', or 'w' only). It will never give you an empty array (that's not a walk, that's standing still!).

**Example:**

```bash
Test(Example_Tests, should_pass_these_two_tests) {
    tester("nsnsnsnsns", true);
    tester("nsnsnsnsnn", false);
}
```
```bash
Time: 750ms Passed: 6Failed: 0
Test Results:
Fixed_Tests
should_return_false_if_walk_does_not_bring_you_back_to_start
should_return_false_if_walk_is_too_long
should_return_false_if_walk_is_too_short
should_return_true_for_a_valid_walk
Completed in 3.1014ms
Full_Tests
should_pass_all_the_tests_provided
Test Passed
Completed in 38.6231ms
Completed in 38.6231ms
Random_Tests
should_pass_all_the_tests_provided
Test Passed
Completed in 15.0454ms
Completed in 15.0454ms
You have passed all of the tests! :)
``` 