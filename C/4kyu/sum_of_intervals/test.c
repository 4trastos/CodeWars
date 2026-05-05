#include <criterion/criterion.h>
#include <limits.h>
#include <stdio.h>

struct interval;
extern int sum_intervals(const struct interval *v, size_t n);

struct interval {
    int first;
    int second;
};

#define NLIM            0x10
#define FMT_INT         (CHAR_BIT * sizeof(int) / 3 + 1)
#define FMT_ALIGN       0x2
#define FMT_INTVL      ((FMT_INT << 1) + 4)
#define OUTPFALIGN      "    "
#define OUTPFLEN        ((sizeof(OUTPFALIGN) + FMT_INTVL + FMT_ALIGN) * NLIM + 1)

char *intvl_to_s(char *outpf, const struct interval *v, size_t n)
{
    size_t pos = sprintf(outpf, "\n  Intervals:\n  [");
    size_t i;
    for (i = 0ul; i < n; ++i)
        pos += sprintf(outpf+pos, "\n%s[%i, %i],", OUTPFALIGN, v[i].first, v[i].second);
    if (i)
        --pos;
    sprintf(outpf+pos, "\n  ]");
    return outpf;
}

void assert_data(const struct interval *v, size_t n, int expected)
{
    char outpf[OUTPFLEN];
    int actual = sum_intervals(v, n);
    if (actual != expected)
        cr_assert_fail("*Actual*: %i\nExpected: %i%s", actual, expected, intvl_to_s(outpf, v, n));
    else
        cr_assert(1);
}

Test(Sample_Test, should_return_the_sum_of_intervals)
{
    assert_data((const struct interval[]){{1, 5}, {10, 20}, {1, 6}, {16, 19}, {5, 11}}, 5ul, 19);
    assert_data((const struct interval[]){{1, 5}}, 1ul, 4);
    assert_data((const struct interval[]){{1, 5}, {6, 10}}, 2ul, 8);
    assert_data((const struct interval[]){{-5,-1}, {1, 5}}, 2ul, 8);
    assert_data((const struct interval[]){{-1000000000, 1000000000}}, 1ul, 2000000000);
    assert_data((const struct interval[]){{0, 20}, {-100000000, 10}, {30, 40}}, 3ul, 100000030);
}