/* 2013
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>

int numbers,
    number[131072];

bool check(void);

int main(void)
{
    while(scanf("%d", &numbers) > 0 && numbers > 0)
    {
        for(int n = 0; n < numbers; ++ n)
            scanf("%d", &number[n]);

        printf("%sambiguous\n", check() ? "" : "not ");
    }

    return 0;
}

bool check(void)
{
    int map[131072] = {};
    for(int n = 0; n < numbers; ++ n)
        map[number[n] - 1] = n + 1;

    for(int n = 0; n < numbers; ++ n)
        if(map[n] != number[n])
            return false;

    return true;
}
