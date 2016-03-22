/* 2013
 * Maciej Szeptuch
 * II UWr
 */
#include<cstdio>

int tests,
    person;

int main(void)
{
    scanf("%d", &tests);
    for(int t = 0; t < tests; ++ t)
    {
        scanf("%d", &person);
        printf("%d\n", __builtin_popcount(person) % 2 == 0);
    }

    return 0;
}
