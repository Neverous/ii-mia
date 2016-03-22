/* 2013
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>
#include <algorithm>

int candidates,
    voters,
    candidate[128],
    voter[128][128],
    sorted[128];

inline const bool compare(const int &a, const int &b){return candidate[a] > candidate[b];}

int main(void)
{
    scanf("%d %d", &candidates, &voters);
    for(int c = 0; c < candidates; ++ c)
        sorted[c] = c;

    for(int v = 0; v < voters; ++ v)
    {
        for(int c = 0; c < candidates; ++ c)
        {
            scanf("%d", &voter[v][c]);
            -- voter[v][c];
        }

        ++ candidate[voter[v][0]];
    }

    std::sort(sorted, sorted + candidates, compare);
    if(candidate[sorted[0]] > voters / 2)
    {
        printf("%d 1\n", sorted[0] + 1);
        return 0;
    }

    candidate[sorted[0]] = 0;
    candidate[sorted[1]] = 0;
    for(int v = 0; v < voters; ++ v)
    {
        int c = 0;
        while(c < candidates && voter[v][c] != sorted[0] && voter[v][c] != sorted[1])
            ++ c;

        ++ candidate[voter[v][c]];
    }

    printf("%d 2\n",1 + (candidate[sorted[0]] > candidate[sorted[1]] ? sorted[0] : sorted[1]));
    return 0;
}
