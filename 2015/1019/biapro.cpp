/* 2016
 * Maciej Szeptuch
 * II UWr
 */
#include <algorithm>
#include <cstdio>

int blocks;
int height;
int width;
int x[32];
int y[32];

long long int count_rectangles(int m);

int main(void)
{
    scanf("%d %d %d", &width, &height, &blocks);
    for(int b = 0; b < blocks; ++ b)
        scanf("%d %d", &x[b], &y[b]);

    long long int result = 1LL * width * height * (width + 1) * (height + 1) / 4;
    for(int m = 1; m < (1 << blocks); ++ m)
        result += (__builtin_popcount(m) % 2 ? -1 : 1) * count_rectangles(m);

    printf("%lld\n", result);
    return 0;
}

long long int count_rectangles(int m)
{
    int s_x = width;
    int s_y = height;
    int e_x = 0;
    int e_y = 0;
    for(int b = 0; b < blocks; ++ b)
        if(m & (1 << b))
        {
            s_x = std::min(s_x, x[b]);
            s_y = std::min(s_y, y[b]);
            e_x = std::max(e_x, x[b]);
            e_y = std::max(e_y, y[b]);
        }

    return 1LL * (s_x * s_y) * (width + 1 - e_x) * (height + 1 - e_y);
}
