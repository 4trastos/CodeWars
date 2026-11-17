#include <criterion/criterion.h>

extern int count_change(int money, int length, const int coins[length]);

Test(the_count_change_function, should_pass_all_fixed_tests)
{
  int coins1 [] =                    {1,2}; cr_assert_eq(count_change(  4, 2, coins1),     3);
  int coins2 [] =                  {5,2,3}; cr_assert_eq(count_change( 10, 3, coins2),     4);
  int coins3 [] =                    {5,7}; cr_assert_eq(count_change( 11, 2, coins3),     0);
  int coins4 [] =                 {3,14,8}; cr_assert_eq(count_change( 98, 3, coins4),    19);
  int coins5 [] =               {3,5,9,15}; cr_assert_eq(count_change(199, 4, coins5),   760);
  int coins6 [] = {5,10,20,50,100,200,500}; cr_assert_eq(count_change(300, 7, coins6),  1022);
  int coins7 [] = {5,10,20,50,100,200,500}; cr_assert_eq(count_change(301, 7, coins7),     0);
  int coins8 [] =           {2,5,10,20,50}; cr_assert_eq(count_change(419, 5, coins8), 18515);
}