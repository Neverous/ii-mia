/* 2014
 * Maciej Szeptuch
 * IIUWr
 */
#include <cstdio>
#include <algorithm>

int takeover,
    buyout,
    take[131072],
    buy[131072];

bool simulate(void);

int main(void)
{
    for(int t = 0; scanf("%d %d", &takeover, &buyout) != -1; ++ t)
    {
        for(int c = 0; c < takeover; ++ c)
            scanf("%d", &take[c]);

        for(int c = 0; c < buyout; ++ c)
            scanf("%d", &buy[c]);

        printf("Case %d: %s", t + 1, simulate() ? "Takeover Incorporated" : "Buyout Limited");
    }

    return 0;
}

inline
bool simulate(void)
{
    std::sort(take, take + takeover);
    std::reverse(take, take + takeover);

    std::sort(buy, buy + buyout);
    std::reverse(buy, buy + buyout);

    int remainder[2] = {
        take[0],
        buy[0],
    };

    for(int a = 0, t = 1, b = 1; true; a ^= 1)
    {
        if(a == 0) // TAKEOVER TURN
        {
            if(remainder[0] > remainder[1] + (b < buyout ? buy[b] : 0))
                return true;

            if(remander[0] > remainder[1])
                remainder[1] = b < buyout ? buy[b ++] : 0;


            continue;
        }

        // BUYOUT TURN

    }

    return remainder[0] > remainder[1];
}
