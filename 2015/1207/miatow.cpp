/* 2016
 * Maciej Szeptuch
 * II UWr
 */
#include <algorithm>
#include <cstdio>

int towers,
    height[131072];

int solve(void);

int main(void)
{
    scanf("%d", &towers);
    for(int t = 1; t <= towers; ++ t)
        scanf("%d", &height[t]);

    printf("%d\n", solve());
    return 0;
}

int solve(void)
{
    int result[131072] = {};
    for(int t = 1; t <= towers; ++ t)
        result[t] = std::min(result[t - 1] + 1, height[t]);

    for(int t = towers; t > 0; -- t)
        result[t] = std::min(result[t + 1] + 1, result[t]);

    for(int t = 1; t <= towers; ++ t)
        result[0] = std::max(result[0], result[t]);

    return result[0];
}
