/* 2013
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>
#include <algorithm>

int deg,
    times,
    questions,
    number,
    val[1048576];

inline int solve(int num);

int main(void)
{
    scanf("%d %d", &deg, &times);
    for(int d = 0; d <= deg; ++ d)
        scanf("%d", &val[d]);

    scanf("%d", &questions);
    for(int q = 0; q < questions; ++ q)
    {
        scanf("%d", &number);
        printf("%d\n", solve(number));
    }

    return 0;
}

inline int solve(int num)
{
    if(num == 0)
        return val[0];

    int t = std::min(__builtin_ctz(num & -num), times);
    if(t < times)
        return 0;
    
    if(num / (1 << t) <= deg)
        return val[num / (1 << t)];

    return 0;
}
