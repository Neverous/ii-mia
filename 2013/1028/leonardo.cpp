/* 2013
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>

int tests;
char perm[32];

int main(void)
{
    scanf("%d", &tests);
    for(int t = 0; t < tests; ++ t)
    {
        scanf("%s", perm);
        bool visited[32] = {};
        int count[32] = {};

        for(int p = 0; perm[p]; ++ p)
        {
            if(visited[p])
                continue;

            int length = 0;
            int act = perm[p] - 'A';
            while(!visited[act])
            {
                visited[act] = true;
                ++ length;
                act = perm[act] - 'A';
            }

            ++ count[length];
        }

        bool possible = true;
        for(int l = 2; l < 32 && possible; l += 2)
            possible = count[l] % 2 == 0;

        puts(possible ? "Yes" : "No");
    }

    return 0;
}
