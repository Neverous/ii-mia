/* 2016
 * Maciej Szeptuch
 * II UWr
 */
#include <algorithm>
#include <cstdio>
#include <vector>

const int MAX_STONES = 65536;
int area[MAX_STONES];
int component[MAX_STONES];
int h[MAX_STONES];
int sort_me2[MAX_STONES];
int sort_me[MAX_STONES];
int stones;
int w[MAX_STONES];
int x[MAX_STONES];
int y[MAX_STONES];

bool compare_hopen(int a, int b);
bool compare_hclose(int a, int b);
bool compare_vopen(int a, int b);
bool compare_vclose(int a, int b);

bool intersects(int s1, int e1, int s2, int e2);

int find(int a);
void join(int a, int b);

void join_intersecting(int* level, int* level_close, int* offset, int* offset_close);

int main(void)
{
    scanf("%d", &stones);
    for(int s = 0; s < stones; ++ s)
    {
        scanf("%d %d %d %d", &x[s], &y[s], &w[s], &h[s]);
        sort_me[s]      = s;
        sort_me2[s]     = s;
        component[s]    = s;
    }

    std::sort(sort_me, sort_me + stones, compare_hopen);
    std::sort(sort_me2, sort_me2 + stones, compare_hclose);
    join_intersecting(y, h, x, w);

    std::sort(sort_me, sort_me + stones, compare_vopen);
    std::sort(sort_me2, sort_me2 + stones, compare_vclose);
    join_intersecting(x, w, y, h);

    int result = 0;
    for(int c = 0; c < stones; ++ c)
    {
        int comp = find(c);
        area[comp] += w[c] * h[c];
        if(area[comp] > area[result])
            result = comp;
    }

    printf("%d\n", area[result]);
    return 0;
}

bool compare_hopen(int a, int b)
{
    if(y[a] < y[b])
        return true;

    if(y[a] > y[b])
        return false;

    return x[a] < x[b];
}

bool compare_hclose(int a, int b)
{
    if(y[a] + h[a] < y[b] + h[b])
        return true;

    if(y[a] + h[a] > y[b] + h[b])
        return false;

    return x[a] < x[b];
}

bool compare_vopen(int a, int b)
{
    if(x[a] < x[b])
        return true;

    if(x[a] > x[b])
        return false;

    return y[a] < y[b];
}

bool compare_vclose(int a, int b)
{
    if(x[a] + w[a] < x[b] + w[b])
        return true;

    if(x[a] + w[a] > x[b] + w[b])
        return false;

    return y[a] < y[b];
}

bool intersects(int s1, int e1, int s2, int e2)
{
    return s1 <= e2 && e1 >= s2;
}

int find(int a)
{
    if(component[a] != a)
        return component[a] = find(component[a]);

    return a;
}

void join(int a, int b)
{
    int fa = find(a);
    int fb = find(b);

    if(fa == fb)
        return;

    if(fa < fb)
        component[fb] = fa;

    else
        component[fa] = fb;
}

void join_intersecting(int* level, int* level_close, int* offset, int* offset_close)
{
    for(int so = 0, sc = 0; so < stones && sc < stones;)
    {
        int o = sort_me[so];
        int c = sort_me2[sc];

        if(level[c] + level_close[c] > level[o])
        {
            ++ so;
            continue;
        }

        if(level[c] + level_close[c] < level[o])
        {
            ++ sc;
            continue;
        }

        if(intersects(offset[c], offset[c] + offset_close[c], offset[o], offset[o] + offset_close[o]))
            join(c, o);

        if(offset[c] + offset_close[c] < offset[o] + offset_close[o])
            ++ sc;

        else
            ++ so;
    }
}
