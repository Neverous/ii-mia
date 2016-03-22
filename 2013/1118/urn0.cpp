/* 2013
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>

const int MOD = 1000000007;

int urns,
    A, B;

long long int fastPower(long long int b, long long int p);
long long int factorial(long long int r);
long long int newton(long long int n, long long int k);

int main(void)
{
    scanf("%d %d %d", &urns, &A, &B);
    printf("%lld\n", (newton(A + urns - 1, urns - 1) * newton(B + urns - 1, urns - 1)) % MOD);
    return 0;
}

long long int newton(long long int n, long long int k)
{
    return (factorial(n) * fastPower((factorial(k) * factorial(n - k)) % MOD, MOD - 2)) % MOD;
}

long long int fastPower(long long int b, long long int p)
{
    if(!p || b == 1)
        return 1;

    if(p == 1)
        return b;

    long long int result = fastPower(b, p / 2);
    result *= result;
    if(result >= MOD)
        result %= MOD;

    if(p & 1)
        result *= b;

    if(result >= MOD)
        result %= MOD;

    return result;
}

long long int factorial(long long int r)
{
    long long int result = 1;
    while(r > 0)
    {
        result *= r;
        if(result >= MOD)
            result %= MOD;

        -- r;
    }

    return result;
}
