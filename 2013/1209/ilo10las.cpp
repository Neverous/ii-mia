/* 2013
 * Maciej Szeptuch
 * IIUWr
 */
#include <cstdio>

int size, area,
    map[512][512],
    visited[512][512], vflag,
    maxAge;

inline int MAX(int a, int b) { return a>b?a:b; }
int bestAge(int start, int end);
int biggestArea(int max);
int flood(int h, int w, int max);

int main(void)
{
    scanf("%d %d", &size, &area);
    for(int h = 0; h < size; ++ h)
        for(int w = 0; w < size; ++ w)
        {
            scanf("%d", &map[h][w]);
            maxAge = MAX(maxAge, map[h][w]);
        }

    printf("%d\n", bestAge(1, maxAge));
    return 0;
}

inline
int bestAge(int start, int end)
{
    while(start < end)
    {
        int mid = (start + end) / 2;
        if(biggestArea(mid) >= area)
            end = mid;

        else
            start = mid + 1;
    }

    return start;
}

inline
int biggestArea(int max)
{
    ++ vflag;
    int res = 0;
    for(int h = 0; h < size; ++ h)
        for(int w = 0; w < size; ++ w)
            if(map[h][w] <= max && visited[h][w] != vflag) res = MAX(res, flood(h, w, max));

    return res;
}

int flood(int h, int w, int max)
{
    visited[h][w] = vflag;
    int res = 1;
    for(int dh = -1; dh < 2; dh += 2)
        if( 0 <= h + dh && h + dh < size
        &&  map[h + dh][w] <= max
        &&  visited[h + dh][w] != vflag)
            res += flood(h + dh, w, max);

    for(int dw = -1; dw < 2; dw += 2)
        if( 0 <= w + dw && w + dw < size
        &&  map[h][w + dw] <= max
        &&  visited[h][w + dw] != vflag)
            res += flood(h, w + dw, max);

    return res;
}
