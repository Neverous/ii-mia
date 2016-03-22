/* 2014
 * Maciej Szeptuch
 * II UWr
 */

#include <cstdio>

int levels,
    input[1 << 16],
    output[1 << 16];

int main(void)
{
    scanf("%d", &levels);
    for(int l = 0, n = (1 << levels) - 1; l < n; ++ l)
        scanf("%d", &input[l]);

    for(int l = 0, n = (1 << levels) - 1; l < levels; ++ l)
        for(int i = (1 << l) - 1, o = (1 << (levels - l - 1)) - 1; i < n; i += (1 << (l + 1)), ++ o)
            output[o] = input[i];

    for(int l = 0; l < levels; ++ l)
    {
        for(int o = 0; o < (1 << l); ++ o)
            printf("%d ", output[(1 << l) - 1 + o]);

        puts("");
    }

    return 0;
}
