/* 2014
 * Maciej Szeptuch
 * IIUWr
 */
#include <cstdio>
#include <algorithm>

int blocks,
    block[1048576],
    tolerance;
long long unsigned result = 1;

int main(void)
{
    scanf("%d %d", &blocks, &tolerance);
    for(int b = 0; b < blocks; ++ b)
        scanf("%d", &block[b]);

    std::sort(block, block + blocks);
    for(int b = 0, b2 = 0; b < blocks; ++ b)
    {
        while(b2 < blocks && block[b2] <= block[b] + tolerance)
            ++ b2;

        result = 1LLU * (result * (b2 - b)) % 1000000009LLU;
    }

    printf("%llu\n", result);
    return 0;
}
