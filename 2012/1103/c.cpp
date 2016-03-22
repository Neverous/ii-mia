/* 2012
 * Maciej Szeptuch
 * II UWr
 */
#include<cstdio>

int bottles,
    bottle[1024],
    avg,
    moves;

int main(void)
{
    scanf("%d", &bottles);
    for(int b = 0; b < bottles; ++ b)
    {
        scanf("%d", &bottle[b]);
        avg += bottle[b];
    }

    for(int b = 0; b < bottles; ++ b)
        if(bottle[b] * bottles > avg)
            ++ moves;

    printf("%d\n", moves);
}
