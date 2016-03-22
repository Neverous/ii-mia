/* 2015
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>
#include <algorithm>
#include <cstring>

int size,
    seq[256],
    eaten[256][256];

int eat(int from, int to);

int main(void)
{
    while(scanf("%d", &size) != -1 && size > 0)
    {
        for(int s = 0; s < size; ++ s)
            scanf("%d", &seq[s]);

        memset(eaten, 0, 256 * 256 * sizeof(int));
        printf("%d\n", eat(0, size - 1));
    }

    return 0;
}

inline
int eat(int from, int to)
{
    if(eaten[from][to] > 0)
        return eaten[from][to] - 1;

    if(to - from <= 1)
        return (eaten[from][to] = 1) - 1;

    int result = 0;
    for(int div = from + 1; div < to; ++ div)
        result = std::max(result, eat(from, div) + eat(div, to) + seq[div]);

    return (eaten[from][to] = 1 + result + seq[from] + seq[to]) - 1;
}
