/* 2014
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>
#include <vector>

int points,
    borders,
    queries,
    A, B,
    result;

long long int x, y, r;
struct Point
{
    long long int x;
    long long int y;
} point[1024];

std::vector<int> inside[1024];

int main(void)
{
    scanf("%d %d %d", &points, &borders, &queries);
    for(int p = 0; p < points; ++ p)
        scanf("%lld %lld", &point[p].x, &point[p].y);

    for(int b = 0; b < borders; ++ b)
    {
        scanf("%lld %lld %lld", &r, &x, &y);
        for(int p = 0; p < points; ++ p)
            if((point[p].x - x) * (point[p].x - x) + (point[p].y - y) * (point[p].y - y) < r * r)
                inside[p].push_back(b);
    }

    for(int q = 0; q < queries; ++ q)
    {
        scanf("%d %d", &A, &B);
        -- A, -- B;
        unsigned int f = 0, s = 0;
        result = 0;
        while(f < inside[A].size() && s < inside[B].size())
        {
            while(s < inside[B].size() && inside[B][s] < inside[A][f])
            {
                ++ result;
                ++ s;
            }

            if(s >= inside[B].size())
                break;

            if(inside[A][f] != inside[B][s])
                ++ result;

            else
                ++ s;

            ++ f;
        }

        result += inside[A].size() - f + inside[B].size() - s;

        printf("%d\n", result);
    }

    return 0;
}
