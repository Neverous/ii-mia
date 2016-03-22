/* 2015
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>

long long int   left, right,
                size,
                first, second, third;

long long int brute(long long int from, long long int to, int maxsize);

int main(void)
{
    scanf("%lld %lld %lld", &left, &right, &size);
    if(size == 1)
        printf("%lld\n", left);

    else if(right - left + 1 <= 4)
        printf("%lld\n", brute(left, right, size));

    else if(size == 2)
        puts("1");

    else if(size >= 4)
        puts("0");

    else // size == 3
    {
        for(int l = 0; l < 60; ++ l)
        {
            first   = (1LL << l) | ((1LL << l) - 1);
            second  = (2LL << l) | ((1LL << l) - 1);
            third   = (3LL << l);

            if(third > right)
                break;

            if(first >= left)
            {
                puts("0");
                return 0;
            }
        }

        puts("1");
    }

    return 0;
}

inline
long long int brute(long long int from, long long int to, int maxsize)
{
    long long int result = to;
    for(int s = 0; s < (1 << (to - from + 1)); ++ s)
    {
        long long int res = 0;
        int count = 0;
        for(int l = 0; l < (to - from + 1) && count < maxsize; ++ l)
            if((1 << l) & s)
            {
                ++ count;
                res ^= from + l;
            }


        if(count && res < result)
            result = res;
    }

    return result;
}
