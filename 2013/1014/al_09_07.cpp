/* 2013
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>

int tests,
    throws, hits;


int main(void)
{
    scanf("%d", &tests);
    for(int t = 0; t < tests; ++ t)
    {
        scanf("%d %d", &throws, &hits);
        if(hits > throws || throws == hits * 3)
            puts("NIE");

        else if(throws < hits * 3)
            puts("TAK, ZWIEKSZY SIE");

        else
            puts("TAK, ZMNIEJSZY SIE");
    }

    return 0;
}
