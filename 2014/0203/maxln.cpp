/* 2014
 * Maciej Szeptuch
 * IIUWr
 */
#include <cstdio>
#include <cmath>

int tests,
    radius;

int main(void)
{
    scanf("%d", &tests);
    for(int t = 0; t < tests; ++ t)
    {
        scanf("%d", &radius);
        printf("Case %d: %.6lf\n", t + 1, (2.0 * radius) * (2.0 * radius) + 0.25);
    }

    return 0;
}
