/* 2014
 * Maciej Szeptuch
 * II UWr
 */

#include <cstdio>

int cost[256],
    result[2][16384],
    s, a;

char apple[16384],
     swine[8192];

int main(void)
{
    scanf("%s %s", apple, swine);
    scanf("%d %d %d %d", &cost[(int) 'A'], &cost[(int) 'C'], &cost[(int) 'G'], &cost[(int) 'T']);

    for(s = 0; swine[s]; ++ s)
    {
        result[s & 1][0] = result[!(s & 1)][0] + cost[(int) swine[s]];
        for(a = 1; apple[a - 1]; ++ a)
        {
            if(swine[s] == apple[a - 1])
                result[s & 1][a] = result[!(s & 1)][a - 1];

            else
                result[s & 1][a] = result[!(s & 1)][a] + cost[(int) swine[s]];
        }
    }

    int best = result[!(s & 1)][0];
    for(a = 1; apple[a - 1]; ++ a)
        if(best > result[!(s & 1)][a])
            best = result[!(s & 1)][a];

    printf("%d\n", best);
    return 0;
}
