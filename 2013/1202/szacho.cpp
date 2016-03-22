/* 2013
 * Maciej Szeptuch
 * IIUWr
 */
#include <cstdio>
#include <cassert>

long long int size,
              res = 1;
int MOD;

int main(void)
{
    scanf("%lld %d", &size, &MOD);
    size %= MOD;
    for(long long int s = 1, i = -1; s <= size; ++ s, i *= -1)
        res = (res * s + i) % MOD;

    printf("%lld\n", (res * res) % MOD);
    return 0;
}
