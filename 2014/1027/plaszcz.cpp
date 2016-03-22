/* 2014
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>

int equations,
    a, b, c;

int main(void)
{
    scanf("%d", &equations);
    for(int e = 0; e < equations; ++ e)
    {
        scanf("%d %d %d", &a, &b, &c);
        if(a == 0 && b == 0 && c == 0)
        {
            puts("TAK");
            return 0;
        }
    }

    puts("NIE");
    return 0;
}
