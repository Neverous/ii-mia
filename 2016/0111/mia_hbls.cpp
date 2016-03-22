/* 2016
 * Maciej Szeptuch
 * II UWr
 */
#include <algorithm>
#include <cstdio>

const int MAX_HAYBALES = 1024;
const int MAX_PILES = 131072;
int current[MAX_PILES];
int haybales;
int max_move;
int move[MAX_PILES];
int wanted[MAX_PILES];

int main(void)
{
    scanf("%d", &haybales);
    for(int h = 0; h < haybales; ++ h)
    {
        scanf("%d %d", &current[h], &wanted[h]);
        move[h] = current[h] - wanted[h] + (h ? move[h - 1] : 0);
        max_move = std::max(max_move, move[h]);
    }

    std::sort(move, move + haybales);
    long long int  result = 0;
    for(int h = 0; h < haybales; ++ h)
        result += std::abs(move[h] - move[haybales / 2]);

    printf("%lld\n", result);
    return 0;
}
