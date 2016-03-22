/* 2015
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>

int people,
    channels,
    current,
    change[131072],
    love, hate,
    count;

int main(void)
{
    scanf("%d %d %d", &people, &channels, &current);
    for(int c = 1; c <= channels; ++ c)
        change[c] = c;

    for(int p = 0; p < people; ++ p)
    {
        scanf("%d %d", &love, &hate);
        if(change[hate] == hate)
            change[hate] = love;
    }

    while(current > 0 && change[current] != current)
    {
        int next = change[current];
        change[current] = 0;
        current = next;
        ++ count;
    }

    if(current == 0)
        puts("-1");

    else
        printf("%d\n", count);

    return 0;
}
