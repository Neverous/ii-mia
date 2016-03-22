/* 2013
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>

long long int factor,
              decimal,
              pow;
char input[16];
int len, point;
bool found;

int main(void)
{
    scanf("%s", input);
    for(len = 0; input[len]; ++ len)
        if('0' <= input[len] && input[len] <= '9')
            factor = factor * 10LL + input[len] - '0';

        else
            point = len;

    while(len - point - 1 < 4)
    {
        factor *= 10LL;
        ++ len;
    }

    pow = 1LL;
    if(factor != 100000LL) for(int n = 1; n <= 8; ++ n)
    {
        for(int d = 1; d <= 9; ++ d)
        {
            long long int number = d * 10000LL * (pow * 10LL - 1LL) / (100000LL - factor);
            if(number * factor != 100000LL * number - (pow * 10LL - 1LL) * 10000LL * d || number / pow != d)
                continue;

            printf("%lld\n", number);
            found = true;
        }

        pow *= 10LL;
    }

    if(!found)
        puts("No solution");

    return 0;
}
