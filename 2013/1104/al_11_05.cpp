/* 2013
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>

int size,
    piramids,
    x, y, k,
    result,
    tab[5005][5005];

inline int MAX(int a, int b) { return a>b?a:b; }

int main(void)
{
    scanf("%d %d", &size, &piramids);
    for(int p = 0; p < piramids; ++ p)
    {
        scanf("%d %d %d", &x, &y, &k);
        tab[y][x - y + 1] = MAX(tab[y][x - y + 1], k + 1);
    }

    for(int h = 1; h <= size; ++ h)
        for(int w = 1; w <= size; ++ w)
        {
           tab[h][w] = MAX(MAX(tab[h][w], tab[h - 1][w] - 1), tab[h][w - 1] - 1); 
           result += tab[h][w] > 0;
        }

    printf("%d\n", result);
    return 0;
}
