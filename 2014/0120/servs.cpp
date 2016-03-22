/* 2014
 * Maciej Szeptuch
 * IIUWr
 */
#include <cstdio>

inline int min(int a, int b) { return a<b?a:b; }

int servers,
    cost[1024],
    with[1024],
    without[1024];

int main(void)
{
    scanf("%d", &servers);
    for(int s = 0; s < servers; ++ s)
        scanf("%d", &cost[s]);

    with[servers - 1] = cost[servers - 1];
    without[servers - 1] = 1000000000;
    for(int s = servers - 2; s >= 0; -- s)
    {
        with[s] = cost[s] + min(with[s + 1], without[s + 1]);
        without[s] = 1000000000;
        for(int t = s + 1; t < servers; ++ t)
            without[s] = min(without[s], (t - s) * (t - s + 1) / 2 + with[t]);
    }

    printf("%d\n", min(with[0], without[0]));
    return 0;
}
