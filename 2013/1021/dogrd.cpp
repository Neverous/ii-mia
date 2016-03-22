/* 2013
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>

typedef std::pair<int, int> Point;

int points,
    max;
Point point[131072];
std::vector<int> result;

bool leftSide(const Point &a, const Point &b, const Point &c);
int dist(const Point &a, const Point &b);
void convexHull(void);

int main(void)
{
    scanf("%d", &points);
    for(int p = 0; p < points; ++ p)
        scanf("%d %d", &point[p].first, &point[p].second);

    std::sort(point, point + points);
    convexHull();
    for(unsigned int i = 0, j = 1; i < result.size(); ++ i)
    {
        while(j != i && dist(point[result[i]], point[result[(j + 1) % result.size()]]) >= dist(point[result[i]], point[result[j]]))
            j = (j + 1) % result.size();

        if(max < dist(point[result[i]], point[result[j]]))
            max = dist(point[result[i]], point[result[j]]);
    }

    printf("%.9Lf\n", sqrtl(max));
    return 0;
}

void convexHull(void)
{
    std::vector<int> upper,
                     lower;

    upper.push_back(0);
    upper.push_back(1);
    for(int p = 2; p < points; ++ p)
    {
        while(upper.size() > 1 && leftSide(point[upper[upper.size() - 2]], point[upper[upper.size() - 1]], point[p]))
            upper.pop_back();

        upper.push_back(p);
    }

    lower.push_back(points - 1);
    lower.push_back(points - 2);
    for(int p = points - 3; p >= 0; -- p)
    {
        while(lower.size() > 1 && leftSide(point[lower[lower.size() - 2]], point[lower[lower.size() - 1]], point[p]))
            lower.pop_back();

        lower.push_back(p);
    }

    for(unsigned int u = 0; u < upper.size() - 1; ++ u)
        result.push_back(upper[u]);

    for(unsigned int l = 0; l < lower.size() - 1; ++ l)
        result.push_back(lower[l]);
}

int dist(const Point &a, const Point &b)
{
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

bool leftSide(const Point &a, const Point &b, const Point &c)
{
    return (b.first - a.first) * (c.second - a.second) - (b.second - a.second) * (c.first - a.first) >= 0;
}
