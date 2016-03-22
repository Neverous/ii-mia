/* 2013
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>
#include <vector>
#include <algorithm>

int tests,
    cards,
    result,
    value[256],
    suit[256];
char card[4];
std::vector<int> adam, eve;

int main(void)
{
    for(int c = '2'; c <= '9'; ++ c)
        value[c] = (c - '2') * 4;

    value['T'] = 32; value['J'] = 36; value['Q'] = 40; value['K'] = 44; value['A'] = 48;
    suit['C'] = 0; suit['D'] = 1; suit['S'] = 2; suit['H'] = 3;

    scanf("%d", &tests);
    for(int t = 0; t < tests; ++ t)
    {
        scanf("%d", &cards);
        adam.clear();
        eve.clear();
        for(int c = 0; c < cards; ++ c)
        {
            scanf("%s", card);
            adam.push_back(value[card[0]] + suit[card[1]]);
        }

        for(int c = 0; c < cards; ++ c)
        {
            scanf("%s", card);
            eve.push_back(value[card[0]] + suit[card[1]]);
        }

        std::sort(adam.begin(), adam.end());
        std::sort(eve.begin(), eve.end());
        result = 0;
        for(int a = 0, e = 0; a < adam.size() && e < eve.size(); ++ a, ++ e)
        {
            while(e < eve.size() && adam[a] >= eve[e]) ++ e;
            if(e < eve.size())
                ++ result;
        }

        printf("%d\n", result);
    }

    return 0;
}
