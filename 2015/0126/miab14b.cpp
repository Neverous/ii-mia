/* 2015
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>

int contestants,
    first[524288],
    second[524288],
    map[1024][1024];

int main(void)
{
    scanf("%d", &contestants);
    for(int c = 0; c < contestants; ++ c)
    {
        scanf("%d %d", &first[c], &second[c]);
        ++ map[first[c] + 1][second[c] + 1];
    }

    for(int h = 1; h < 1024; ++ h)
        for(int w = 1; w < 1024; ++ w)
            map[h][w] += map[h-1][w] + map[h][w-1] - map[h-1][w-1];

    for(int c = 0; c < contestants; ++ c)
    {
        printf( "%d %d\n",
                1 + map[first[c] + 1][second[c] + 1] + map[1023][1023] - map[1023][second[c] + 1] - map[first[c] + 1][1023],
                contestants - map[first[c]][second[c]] - (map[first[c] + 1][1] - map[first[c]][1]) * (second[c] == 650) - (map[1][second[c] + 1] - map[1][second[c]]) * (first[c] == 650)
        );
    }

    return 0;
}
