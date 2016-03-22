/* 2013
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>

int height, width,
    map[128][128],
    result,
    temp;
bool adjacent[128];

int dfs(const int &y, const int &x, const int &color);

int main(void)
{
    scanf("%d %d", &height, &width);
    for(int h = 0; h < height; ++ h)
        for(int w = 0; w < width; ++ w)
            scanf("%d", &map[h][w]);

    for(int h = 0; h < height; ++ h)
        for(int w = 0; w < width; ++ w)
            if((temp = map[h][w]) != -1)
                adjacent[temp] |= dfs(h, w, temp) > 1;

    for(int i = 0; i <= 100; ++ i)
        result += adjacent[i];

    printf("%d\n", result);
    return 0;
}

int dfs(const int &y, const int &x, const int &color)
{
    int res = 1;
    map[y][x] = -1;
    for(int dx = -1; dx <= 1; ++ dx)
        for(int dy = -1; dy <= 1; ++ dy)
            if(0 <= x + dx && x + dx < width && 0 <= y + dy && y + dy < height && map[y + dy][x + dx] == color)
                res += dfs(y + dy, x + dx, color);

    return res;
}
