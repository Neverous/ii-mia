/* 2013
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>

int types,
    same,
    candies,
    result;

int main(void)
{
    scanf("%d %d", &types, &same);
    for(int t = 0; t < types; ++ t)
    {
        scanf("%d", &candies);
        result += candies / same;
    }

    printf("%d\n", result);
    return 0;
}
