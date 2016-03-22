/* 2014
 * Maciej Szeptuch
 * IIUWr
 */
#include <cstdio>
#include <cstring>

int types,
    sum,
    count;

int main(void)
{
    scanf("%d", &types);
    for(int t = 0; t <= types; ++ t)
    {
        scanf("%d", &count);
        sum += count * (1 << t);
    }

    printf("%d\n", sum + 1);
    return 0;
}
