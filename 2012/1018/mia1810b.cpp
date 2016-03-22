/* 2012
 * Maciej Szeptuch
 * II UWr
 */
#include<cstdio>

int songs,
    top,
    rating[1024],
    min;

int main(void)
{
    scanf("%d %d", &songs, &top);
    for(int s = 0; s < songs; ++ s)
        scanf("%d", &rating[s]);

    for(int t = 0; t < top; ++ t)
    {
        min = 0;
        for(int s = 1; s < songs; ++ s)
            if(rating[min] < rating[s])
                min = s;

        printf("%d\n", min + 1);
        for(int s = 0; s < songs; ++ s)
            if(min != s) rating[s] += rating[min] / (songs - 1);

        rating[min] %= (songs - 1);
        for(int s = 0; s < songs && rating[min]; ++ s)
            if(min != s)
            {
                ++ rating[s];
                -- rating[min];
            }
    }

    return 0;
}
