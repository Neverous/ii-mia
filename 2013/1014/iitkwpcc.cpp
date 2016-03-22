/* 2013
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>

typedef std::pair<int, int> Point;
typedef std::vector<int> Coord;
typedef std::map<int, Coord> Map;
Map xpoints,
    ypoints;

int points,
    result;
Point point[131072];

int findTriangles(int x, int y, const Coord &first, const Coord &second);

int main(void)
{
    scanf("%d", &points);
    for(int p = 0; p < points; ++ p)
    {
        scanf("%d %d", &point[p].first, &point[p].second);
        xpoints[point[p].first].push_back(point[p].second);
        ypoints[point[p].second].push_back(point[p].first);
    }

    for(Map::iterator it = xpoints.begin(); it != xpoints.end(); ++ it)
        std::sort(it->second.begin(), it->second.end());

    for(Map::iterator it = ypoints.begin(); it != ypoints.end(); ++ it)
        std::sort(it->second.begin(), it->second.end());

    for(int p = 0; p < points; ++ p)
    {
        Coord &xp = xpoints[point[p].first],
              &yp = ypoints[point[p].second];

        if(xp.size() < yp.size())
            result += findTriangles(point[p].second, point[p].first, xp, yp);

        else
            result += findTriangles(point[p].first, point[p].second, yp, xp);
    }

    printf("%d\n", result);
    return 0;
}

int findTriangles(int x, int y, const Coord &first, const Coord &second)
{
    int res = 0;
    for(unsigned int f = 0; f < first.size(); ++ f)
        if(x != first[f])
            res += binary_search(second.begin(), second.end(), y + x - first[f]) +
                   binary_search(second.begin(), second.end(), y - x + first[f]);

    return res;
}
