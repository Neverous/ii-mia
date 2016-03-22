/* 2015
 * Maciej Septuch
 * II UWr
 */
#include <cstdio>

int size;
int tab[16][16];
int tests;

bool test(void);

int main(void)
{
    scanf("%d", &tests);
    for(int t = 0; t < tests; ++ t)
    {
        scanf("%d", &size);
        for(int h = 0; h < size; ++ h)
            for(int w = 0; w < size; ++ w)
                scanf("%d", &tab[w][h]);

        puts(test() ? "TAK" : "NIE");
    }

    return 0;
}

bool test(void)
{
    for(int h = 1; h < size; ++ h)
        for(int w = 1; w < size; ++ w)
        {
            if(tab[h][w] - tab[h - 1][w] != tab[h][w - 1] - tab[h - 1][w - 1])
                return false;

            if(tab[h][w] - tab[h][w - 1] != tab[h - 1][w] - tab[h - 1][w - 1])
                return false;
        }

    return true;
}
