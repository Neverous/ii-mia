/* 2015
 * Maciej Szeptuch
 * II UWr
 */
#include <algorithm>
#include <cstdio>

char knows[8192];
int people;

int main(void)
{
    scanf("%d", &people);
    for(int p = 0; p < people; ++ p)
    {
        scanf("%s", knows);
        if(std::count(knows, knows + people, '1') == 1)
        {
            printf("1\n%d\n", p + 1);
            return 0;
        }
    }

    return 0;
}
