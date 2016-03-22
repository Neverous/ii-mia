/* 2014
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>
#include <algorithm>

int cities,
    population;
long long int res[2][2];

int main(void)
{
    scanf("%d", &cities);
    for(int c = 0; c < cities; ++ c)
    {
        scanf("%d", &population);
        res[c & 1][0] = std::max(res[!(c & 1)][0], res[!(c & 1)][1]);
        res[c & 1][1] = res[!(c & 1)][0] + population;
    }

    printf("%lld\n", std::max(res[!(cities & 1)][0], res[!(cities & 1)][1]));
    return 0;
}
