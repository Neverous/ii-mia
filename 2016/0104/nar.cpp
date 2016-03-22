/* 2016
 * Maciej Szeptuch
 * II UWr
 */
#include <algorithm>
#include <cstdio>
#include <vector>

int cameras;
int diff;
int result;
int runners;
std::vector<int> que;

int main(void)
{
    while(scanf("%d", &runners) != EOF && runners != 0)
    {
        cameras = 1;
        result = 1;
        que.clear();
        que.resize(runners, 0);
        que[0] = 60;

        for(int r = 1, time = 0, q = 0; r < runners; ++ r)
        {
            scanf("%d", &diff);
            time += diff;
            while(q < r && que[q] <= time)
            {
                ++ q;
                -- cameras;
            }

            ++ cameras;
            que[r] = time + 60;
            result = std::max(result, cameras);
        }

        printf("%d\n", result);
    }

    return 0;
}
