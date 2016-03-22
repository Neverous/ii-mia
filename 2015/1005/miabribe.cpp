/* 2016
 * Maciej Szeptuch
 * II UWr
 */
#include <algorithm>
#include <cstdio>

int tests,
    cells,
    prisoners,
    prisoner[128],
    dp[128][128];

int solve(int from, int to);

int main(void)
{
    scanf("%d", &tests);
    for(int t = 0; t < tests; ++ t)
    {
        scanf("%d %d", &cells, &prisoners);
        for(int p1 = 0; p1 <= prisoners + 1; ++ p1)
            for(int p2 = 0; p2 <= prisoners + 1; ++ p2)
                dp[p1][p2] = -1;

        prisoner[0]             = 0;
        prisoner[prisoners + 1] = cells + 1;
        for(int p = 1; p <= prisoners; ++ p)
            scanf("%d", &prisoner[p]);

        printf("Case #%d: %d\n", t + 1, solve(1, prisoners));
    }

    return 0;
}

int solve(int from, int to)
{
    if(dp[from][to] != -1)
    {
        return dp[from][to];
    }

    if(from > to)
    {
        dp[from][to] = 0;
        return dp[from][to];
    }

    dp[from][to] = (1 << 30);
    for(int mid = from; mid <= to; ++ mid)
    {
        dp[from][to] = std::min(
            dp[from][to],
            prisoner[to + 1] - prisoner[from - 1] - 2 + solve(from, mid - 1) + solve(mid + 1, to));
    }

    return dp[from][to];
}
