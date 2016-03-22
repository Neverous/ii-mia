/* 2015
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>

int tests,
    begin, end;

int xor_(int num);
int xorseq(int from, int to);

int main(void)
{
    scanf("%d", &tests);
    for(int t = 0; t < tests; ++ t)
    {
        scanf("%d %d", &begin, &end);
        printf("%d\n", xorseq(begin, end));
    }

    return 0;
}

int xorseq(int from, int to)
{
    return xor_(from - 1) ^ xor_(to);
}

int xor_(int num)
{
    return num * ((const int[]) {1, 0, 1, 0}[num & 3]) + ((const int[]) {0, 1, 1, 0}[num & 3]);
}
