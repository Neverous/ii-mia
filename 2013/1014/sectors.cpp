/* 2013
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>

int tests,
    parts,
    part[128];
long long int sum[2];

int main(void)
{
    scanf("%d", &tests);
    for(int t = 0; t < tests; ++ t)
    {
        scanf("%d", &parts);
        sum[0] = sum[1] = 0;
        for(int p = 0; p < parts; ++ p)
        {
            scanf("%d", &part[p]);
            sum[p&1] += part[p];
        }

        puts(parts&1 || sum[0] == sum[1] ? "YES" : "NO");
    }

    return 0;
}
