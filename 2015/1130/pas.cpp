/* 2016
 * Maciej Szeptuch
 * II UWr
 */
#include <algorithm>
#include <cstdio>

const int MAX_STRIPES = 1024;
const int MAX_MASKS = (1 << 24);

int bit;
int bits;
int dp[MAX_MASKS];
int stripe[1024];
int stripes;

int main(void)
{
    scanf("%d %d", &stripes, &bits);
    for(int s = 0; s < stripes; ++ s)
    {
        for(int b = 0; b < bits; ++ b)
        {
            scanf("%d", &bit);
            if(bit)
                stripe[s] |= (1 << b);
        }

        if(stripe[s] == 0)
        {
            ++ dp[0];
            -- s;
            -- stripes;
        }
    }

    ++ dp[0];
    int result = dp[0];
    if(stripes > 0)
    {
        for(int m = 0; m < (1 << bits); ++ m)
        {
            if(!dp[m]) continue;

            result = std::max(result, dp[m]);
            for(int s = 0; s < stripes; ++ s)
                if(!(m & stripe[s]))
                    dp[m | stripe[s]] = std::max(dp[m | stripe[s]], dp[m] + 1);
        }
    }

    printf("%d\n", result - 1);
    return 0;
}
