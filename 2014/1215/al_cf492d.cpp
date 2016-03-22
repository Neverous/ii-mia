/* 2015
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>
#include <algorithm>

int monsters,
    freqA, freqB,
    sortMe[131072],
    monster[131072],
    last;

inline
bool compareMonsters(const int a, const int b)
{
    return monster[a] < monster[b];
}

int main(void)
{
    scanf("%d %d %d", &monsters, &freqA, &freqB);
    for(int m = 0; m < monsters; ++ m)
    {
        sortMe[m] = m;
        scanf("%d", &monster[m]);
        monster[m] %= freqA + freqB;
    }

    std::sort(sortMe, sortMe + monsters, compareMonsters);
    for(int hitA = 0, hitB = 0, m = 0; m < monsters; ++ m)
    {
        //printf("%d + %d = %d vs %d\n", hitA, hitB, hitA + hitB, monster[sortMe[m]]);
        while(hitA + hitB < monster[sortMe[m]])
        {
            if((long long int) freqB * (hitA + 1) < (long long int) freqA * (hitB + 1))
            {
                ++ hitA;
                last = 1;
            }

            else if((long long int) freqA * (hitB + 1) < (long long int) freqB * (hitA + 1))
            {
                ++ hitB;
                last = 2;
            }

            else
            {
                ++ hitA;
                ++ hitB;
                last = 0;
            }

            //printf("hit %d\n", last);
        }

        //printf("%d + %d = %d vs %d\n", hitA, hitB, hitA + hitB, monster[sortMe[m]]);
        monster[sortMe[m]] = last;
    }

    for(int m = 0; m < monsters; ++ m)
        puts(((const char*[]){"Obaj", "Lech", "Tadeusz"}[monster[m]]));

    return 0;
}
