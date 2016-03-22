/* 2015
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>
#include <cstring>
#include <algorithm>

int tests;
char word[1024];

int solve(char *name);

int main(void)
{
    scanf("%d", &tests);
    for(int t = 0; t < tests; ++ t)
    {
        scanf("%s", word);
        printf("%d\n", solve(word));
    }

    return 0;
}

inline
int solve(char *name)
{
    int len                 = strlen(name),
        sum                 = 0,
        result              = 8192,
        stepsLeft[1024]     = {},
        stepsRight[1024]    = {};

    for(int i = len - 1, j = len - 1; i >= 0; -- i, ++ j)
    {
        while(j > 0 && (j > len - 1 || name[(i + j) % len] == 'A'))
            -- j;

        stepsRight[i] = j;
    }

    for(int i = 0, j = len - 1; i < len; ++ i, ++ j)
    {
        while(j > 0 && (j > len - 1 || name[(len + i - j) % len] == 'A'))
            -- j;

        stepsLeft[i] = j;
    }

    for(int n = 0; name[n]; ++ n)
        sum += std::min(name[n] - 'A', 'Z' - name[n] + 1);

    for(int l = 0; name[l]; ++ l)
        if(result > std::min(l, len - l) + std::min(stepsLeft[l], stepsRight[l]))
            result = std::min(l, len - l) + std::min(stepsLeft[l], stepsRight[l]);

    return result + sum;
}
