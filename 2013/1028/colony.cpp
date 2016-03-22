/* 2013
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>

int year;
long long int position;

bool color(int y, long long int p);

int main(void)
{
    scanf("%d %lld", &year, &position);
    puts(color(year, position) ? "red" : "blue");
    return 0;
}

bool color(int y, long long int p)
{
    if(y == 0)
        return true;

    if(y == 1)
        return p == 1;

    if(p >= (1LL << (y - 1)))
        return color(y - 1, p - (1LL << (y - 1)));

    return !color(y - 1, p);
}
