/* 2013
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>

int candies,
    cnt = 1,
    step;
bool b;

int main(void)
{
    scanf("%d", &candies);
    while(candies >= cnt)
    {
        if(b ^= 1)
            step ++;

        cnt += step;
        //printf("%d %d %d\n", candies, cnt, step);
    }
    printf("%d\n", cnt - step);
    return 0;
}
