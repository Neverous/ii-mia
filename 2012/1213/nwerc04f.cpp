/* 2013
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>
#include <cstring>

int tests,
    capital,
    years,
    bonds,
    cost[16],
    gain[16];

inline int max(const int &a, const int &b){return a>b?a:b;}
inline int invest(const int &money);

int main(void)
{
    scanf("%d", &tests);
    for(int t = 0; t < tests; ++ t)
    {
        scanf("%d %d %d", &capital, &years, &bonds);
        for(int b = 0; b < bonds; ++ b)
        {
            scanf("%d %d", &cost[b], &gain[b]);
            cost[b] /= 1000;
        }

        for(int y = 0; y < years; ++ y)
            capital += invest(capital / 1000);

        printf("%d\n", capital);
    }

    return 0;
}

inline int invest(const int &money)
{
    int profit[money + 1];
    memset(profit, 0, sizeof(int) * (money + 1));
    for(int b = 0; b < bonds; ++ b)
        for(int p = 0; p <= money - cost[b]; ++ p)
            profit[p + cost[b]] = max(profit[p + cost[b]], profit[p] + gain[b]);

    return profit[money];
}
