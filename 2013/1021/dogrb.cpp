/* 2013
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>
#include <algorithm>

int vegetables,
    vegetable[1024],
    best = 500;
long double ratio;

void minCuts(int m);

int main(void)
{
    scanf("%Lf %d", &ratio, &vegetables);
    for(int v = 0; v < vegetables; ++ v)
        scanf("%d", &vegetable[v]);

    std::sort(vegetable, vegetable + vegetables);
    for(int v = vegetables - 1; v >= 0; -- v)
        minCuts(v);

    printf("%d\n", best);
    return 0;
}

void minCuts(int m)
{
    for(int c = 1; c <= best; ++ c)
    {
        int act = c - 1;
        int max = vegetable[m] / c + vegetable[c] % c;
        if(1.0L * vegetable[m] / c / max <= ratio)
            continue;

        for(int v = 0; v < vegetables && act < best; ++ v)
            if(v != m)
            {
                int factor = (vegetable[v] + max - 1) / max;
                act += factor - 1;
                if(1.0L * vegetable[v] / factor / max <= ratio)
                    act = 1000;
            }


        if(act < best)
            best = act;
    }
}
