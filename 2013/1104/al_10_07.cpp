/* 2013
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>
#include <vector>
#include <algorithm>

int length,
    actions;
std::pair<int, int> action[131072];

inline int MAX(int a, int b) { return a>b?a:b;}
inline int MIN(int a, int b) { return a<b?a:b;}
bool possible(int time);

int main(void)
{
    scanf("%d %d", &length, &actions);
    int first = 1 << 30;
    for(int a = 0; a < actions; ++ a)
    {
        scanf("%d %d", &action[a].first, &action[a].second);
        first = MIN(first, action[a].second);
    }

    std::sort(action, action + actions);
    for(int a = 0; a < actions; ++ a)
        action[a].second -= first;

    int start = 0,
        end = length;
    while(start < end)
    {
        int mid = (start + end) / 2;
        if(possible(mid))
            end = mid;

        else
            start = mid + 1;
    }

    printf("%d\n", first + end);
    return 0;
}

inline
bool possible(int time)
{
    int max = 0;
    for(int a = 0; max < length && a < actions; ++ a)
    {
        if(action[a].second >= time)
            continue;

        if(action[a].first - time + action[a].second > max)
            continue;

        max = MAX(max, action[a].first + time - action[a].second);
    }

    return max >= length;
}
