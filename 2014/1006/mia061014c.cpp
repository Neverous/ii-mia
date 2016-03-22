/* 2014
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>
#include <algorithm>

int size;
long long int first[300001],
              second[300001],
              start, end;

long long int best(void);
long long int count(long long int base);

int main(void)
{
    scanf("%d", &size);
    for(int s = 0; s < size; ++ s)
    {
        scanf("%lld", &first[s]);
        end = std::max(end, first[s]);
    }

    for(int s = 0; s < size; ++ s)
    {
        scanf("%lld", &second[s]);
        end = std::max(end, second[s]);
    }

    printf("%lld\n", best());
    return 0;
}

inline
long long int best(void)
{
    while(start < end)
    {
        long long middle = (start + end) / 2;
        if(count(middle) < count(middle + 1))
            end = middle;

        else
            start = middle + 1;
    }

    return count(start);
}

inline
long long int count(long long int base)
{
    long long int result = 0;
    for(int s = 0; s < size / 2; ++ s)
    {
        result += std::abs(base + size / 2 - s - first[s]);
        result += std::abs(base + size / 2 - s - second[s]);
    }

    for(int s = size / 2; s < size; ++ s)
    {
        result += std::abs(base + s - size / 2 - first[s]);
        result += std::abs(base + s - size / 2 - second[s]);
    }

    return result;
}
