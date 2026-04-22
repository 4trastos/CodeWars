#include <criterion/criterion.h>

int pyramid_slide_down(int, const int*, int);

Test(pyramid_slide_down, sample_test_case_5) {
    int input[] = {3, 
                   7, 2,
                   1, 4, 6,
                   8, 1, 9, 3,
                   9, 9, 9, 9, 9};
    int expected = 32;
    int actual = pyramid_slide_down(15, input, 5);
    cr_assert_eq(actual, expected, "expected %d but got %d", expected, actual);
}

Test(pyramid_slide_down, sample_test_case_4) {
    int input[] = {3, 
                   7, 4,
                   2, 4, 6,
                   8, 5, 9, 3};
    int expected = 23;
    int actual = pyramid_slide_down(10, input, 4);
    cr_assert_eq(actual, expected, "expected %d but got %d", expected, actual);
}

Test(pyramid_slide_down, sample_test_case_4_tricky) {
    int input[] = { 10, 
                    10, 20,
                    10, 10, 20,
                    10, 90, 10, 20};
    int expected = 130;
    int actual = pyramid_slide_down(10, input, 4);
    cr_assert_eq(actual, expected, "expected %d but got %d", expected, actual);
}

Test(pyramid_slide_down, sample_test_case_3) {
    int input[] = {3,
                   7, 6,
                   2, 4, 5};
    int expected = 14;
    int actual = pyramid_slide_down(6, input, 3);
    cr_assert_eq(actual, expected, "expected %d but got %d", expected, actual);
}

Test(pyramid_slide_down, sample_test_case_2) {
    int input[] = {3,
                   1, 2};
    int expected = 5;
    int actual = pyramid_slide_down(3, input, 2);
    cr_assert_eq(actual, expected, "expected %d but got %d", expected, actual);
}

Test(pyramid_slide_down, sample_test_case_1) {
    int input[] = {1};
    int expected = 1;
    int actual = pyramid_slide_down(1, input, 1);
    cr_assert_eq(actual, expected, "expected %d but got %d", expected, actual);
}