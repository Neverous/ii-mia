/* 2014
 * Maciej Szeptuch
 * IIUWr
 */
#include <cstdio>

int size,
    map[64][64],
    result,
    countT[8388608],
    *count = countT + 4194304,
    modifT[8388608],
    *modif = modifT + 4194304,
    t;

int main(void)
{
    scanf("%d", &size);
    for(int h = 0; h < size; ++ h)
        for(int w = 0; w < size; ++ w)
            scanf("%d", &map[h][w]);

    for(int h = 0; h < size - 1; ++ h)
        for(int w = 1; w < size; ++ w)
        {
            {
                int pref[64][64] = {};
                for(int a = h; a >= 0; -- a)
                    for(int b = w; b < size; ++ b)
                        if(modif[pref[a][b] = pref[a][b - 1] + pref[a + 1][b] - pref[a + 1][b - 1] + map[a][b]] != t)
                        {
                            count[pref[a][b]] = 1;
                            modif[pref[a][b]] = t;
                        }
                        else
                            ++ count[pref[a][b]];
            }

            {
                int pref[64][64] = {};
                for(int a = h + 1; a < size; ++ a)
                    for(int b = w - 1; b >= 0; -- b)
                        if(modif[pref[a][b] = pref[a][b + 1] + pref[a - 1][b] - pref[a - 1][b + 1] + map[a][b]] == t)
                            result += count[pref[a][b]];
            }

            ++ t;
        }

    for(int h = 0; h < size - 1; ++ h)
        for(int w = 0; w < size - 1; ++ w)
        {
            {
                int pref[64][64] = {};
                for(int a = h; a >= 0; -- a)
                    for(int b = w; b >= 0; -- b)
                        if(modif[pref[a][b] = pref[a][b + 1] + pref[a + 1][b] - pref[a + 1][b + 1] + map[a][b]] != t)
                        {
                            count[pref[a][b]] = 1;
                            modif[pref[a][b]] = t;
                        }
                        else
                            ++ count[pref[a][b]];
            }

            {
                int pref[64][64] = {};
                for(int a = h + 1; a < size; ++ a)
                    for(int b = w + 1; b < size; ++ b)
                        if(modif[pref[a][b] = pref[a][b - 1] + pref[a - 1][b] - pref[a - 1][b - 1] + map[a][b]] == t)
                            result += count[pref[a][b]];
            }

            ++ t;
        }

    printf("%d\n", result);
    return 0;
}
