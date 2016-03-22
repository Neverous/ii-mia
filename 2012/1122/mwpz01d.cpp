/* 2012
 * Maciej Szeptuch
 * II UWr
 */
#include<cstdio>

int tests,
    people,
    package,
    time,
    cookies;

int main(void)
{
    scanf("%d", &tests);
    for(int t = 0; t < tests; ++ t)
    {
        scanf("%d %d", &people, &package);
        cookies = 0;
        for(int p = 0; p < people; ++ p)
        {
            scanf("%d", &time);
            cookies += 86400 / time;
        }

        printf("%d\n", (cookies + package - 1) / package);
    }

    return 0;
}
