/* 2013
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>

int tests,
    width,
    height,
    pictures,
    light,
    x, y,
    neon[1024][1024],
    nextColor[1048576], color,
    usedColor[1048576], used,
    result;

int main(void)
{
    scanf("%d", &tests);
    for(int t = 0; t < tests; ++ t)
    {
        scanf("%d %d %d", &width, &height, &pictures);
        color = 0;
        result = 0;
        for(int p = 0; p < pictures; ++ p)
        {
            scanf("%d", &light);
            used = 0;
            for(int l = 0; l < light; ++ l)
            {
                scanf("%d %d", &y, &x);
                -- x; -- y;
                if(nextColor[neon[x][y]] == 0)
                {
                    usedColor[used ++] = neon[x][y];
                    nextColor[neon[x][y]] = ++ color;
                }

                neon[x][y] = nextColor[neon[x][y]];
            }

            for(int c = 0; c < used; ++ c)
                nextColor[usedColor[c]] = 0;
        }

        for(int c = 0; c <= color; ++ c)
            usedColor[c] = 0;

        for(int h = 0; h < height; ++ h)
            for(int w = 0; w < width; ++ w)
            {
                usedColor[neon[h][w]] = 1;
                neon[h][w] = 0;
            }

        for(int c = 0; c <= color; ++ c)
            result += usedColor[c] == 1;

        printf("%d\n", result);
    }
    return 0;
}
