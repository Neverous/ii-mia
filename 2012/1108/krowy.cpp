/* 2012
 * Maciej Szeptuch
 * II UWr
 */
#include<cstdio>

long long int days, cows, milk, up, down;

int main(void)
{
    scanf("%lld %lld %lld", &days, &cows, &milk);
    up = 7 * milk;
    down = days * cows;
    for(int d = 2; d <= up && d <= down; ++ d)
        while(up % d == 0 && down % d == 0)
        {
            up /= d;
            down /= d;
        }

    printf("%lld/%lld\n", up, down);
    return 0;
}
