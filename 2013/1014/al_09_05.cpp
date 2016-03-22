/* 2013
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>

int tests,
    cities,
    connected[128][128],
    counted[128][128];

int main(void)
{
    scanf("%d", &tests);
    for(int tt = 0; tt < tests; ++ tt)
    {
        scanf("%d", &cities);
        for(int f = 0; f < cities; ++ f)
            for(int t = 0; t < cities; ++ t)
                scanf("%d", &connected[f][t]);

        for(int f = 0; f < cities; ++ f)
            for(int t = 0; t < cities; ++ t)
                scanf("%d", &counted[f][t]);

        for(int f = 0; f < cities; ++ f)
            for(int t = 0; t < cities; ++ t)
                for(int p = 0; p < cities; ++ p)
                    counted[f][t] -= connected[f][p] && connected[p][t];

        bool answer = true;
        for(int f = 0; f < cities && answer; ++ f)
            for(int t = 0; t < cities && answer; ++ t)
                answer &= counted[f][t] == 0;

        puts(answer ? "TAK" : "NIE");
    }

    return 0;
}
