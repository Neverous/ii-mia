/* 2013
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>

int tests,
    size,
    hatches,
    x[64], y[64];

void solve(void);
inline int abs(const int &a){return a>0?a:-a;}
inline int max(const int &a, const int &b){return a>b?a:b;}
inline int min(const int &a, const int &b){return a<b?a:b;}

int main(void)
{
    scanf("%d", &tests);
    for(int t = 0; t < tests; ++ t)
    {
        scanf("%d %d", &size, &hatches);
        for(int h = 0; h < hatches; ++ h)
            scanf("%d %d", &x[h], &y[h]);

        solve();
    }

    return 0;
}

void solve(void)
{
    for(int w = 1; w < size; ++ w)
        for(int h = 1; h < size; ++ h)
        {
            int d = min(min(h, w), size - max(h, w));
            bool flag = true;
            for(int p = 0; flag && p < hatches; ++ p)
                flag = (x[p] != w || y[p] != h) && (w - x[p])*(w - x[p]) + (h - y[p])*(h - y[p]) <= d*d;

            if(flag)
            {
                printf("%d %d\n", w, h);
                return;
            }
        }

    puts("poodle");
    return;
}
