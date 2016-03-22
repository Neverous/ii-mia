/* 2013
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>
#include <set>

int sectors,
    reserve,
    result[524288];
std::set<int> secik;

int main(void)
{
    scanf("%d", &sectors);
    for(int s = 0; s < sectors; ++ s)
        scanf("%d", &result[s]);

    for(int s = sectors - 1; s >= 0; -- s)
    {
        secik.insert(result[s]);
        std::set<int>::iterator next = secik.upper_bound(result[s]);
        if(next == secik.end())
            result[s] = -1;

        else
            result[s] = *next;
    }

    for(int s = 0; s < sectors; ++ s)
    {
        if(result[s] == -1)
            puts("NIE");

        else
            printf("%d\n", result[s]);
    }

    return 0;
}
