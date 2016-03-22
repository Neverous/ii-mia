/* 2015
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>
#include <algorithm>

int size,
    roses,
    dx, dy,
    x, y,
    transform[1048576],
    count[1048576],
    result;


int main(void)
{
    scanf("%d %d %d %d", &size, &roses, &dx, &dy);
    for(int s = 0; s < size; ++ s)
        transform[((long long int) s * dx) % size] = ((long long int) s * dy) % size;

    for(int r = 0; r < roses; ++ r)
    {
        scanf("%d %d", &x, &y);
        result = std::max(result, ++ count[(size + y - transform[x]) % size]);
    }

    printf("%d\n", result);
    return 0;
}
