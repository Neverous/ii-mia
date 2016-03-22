/* 2013
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>

int tests,
    atoms,
    connections, atom;
bool connection[256][256];

inline int solve(void);

int main(void)
{
    scanf("%d", &tests);
    for(int t = 0; t < tests; ++ t)
    {
        scanf("%d", &atoms);
        for(int h = 0; h < 256; ++ h)
            for(int w = 0; w < 256; ++ w)
                connection[h][w] = 0;

        for(int a = 0; a < atoms; ++ a)
        {
            scanf("%d", &connections);
            for(int c = 0; c < connections; ++ c)
            {
                scanf("%d", &atom);
                -- atom;
                connection[a][atom] = connection[atom][a] = 1;
            }
        }

        printf("%d\n", solve());
    }

    return 0;
}

inline int solve(void)
{
    int result = 0,
        count = 0;
    for(int a = 0; a < atoms; ++ a)
        for(int b = a + 1; b < atoms; ++ b)
            if(!connection[a][b])
            {
                count = 0;
                for(int c = 0; c < atoms; ++ c)
                    count += connection[a][c] && connection[b][c];

                result += count * (count - 1) / 2;
            }

    return result;
}
