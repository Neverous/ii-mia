/* 2013
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>
#include <vector>
#include <algorithm>

typedef std::pair<int, int> Meal;

int meals,
    prev[524288],
    next[524288];
long long int result;
Meal meal[524288];

inline
bool compareSecond(const Meal &a, const Meal &b)
{
    if(a.second < b.second)
        return true;

    if(a.second > b.second)
        return false;

    return a.first < b.first;
}

inline
int MIN(const int a, const int b)
{
    return a < b ? a : b;
}

int main(void)
{
    scanf("%d", &meals);
    for(int m = 0; m < meals; ++ m)
        scanf("%d %d", &meal[m].first, &meal[m].second);

    std::sort(meal, meal + meals, compareSecond);
    next[meals - 1] = meal[meals - 1].first;
    for(int m = meals - 2; m >= 0; -- m)
    {
        next[m] = next[m + 1];
        if(next[m] > meal[m].first)
            next[m] = meal[m].first;
    }

    prev[0] = meal[0].first - meal[0].second;
    for(int m = 1; m < meals; ++ m)
    {
        prev[m] = prev[m - 1];
        if(prev[m] > meal[m].first - meal[m].second)
            prev[m] = meal[m].first - meal[m].second;
    }

    for(int m = 0; m < meals; ++ m)
    {
        printf("%lld\n", result + MIN(m - 1 > 0 ? meal[m].second + prev[m - 1] : 1000000000, next[m]));
        result += meal[m].second;
    }

    return 0;
}
