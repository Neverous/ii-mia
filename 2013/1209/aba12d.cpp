/* 2013
 * Maciej Szeptuch
 * IIUWr
 */
#include <cstdio>

int tests,
    from, to,
    res[1048576];
bool prime[2097152];

void sieve(void);

int main(void)
{
    sieve();
    res[2] = 1;
    for(int i = 2; i * i < 1048576; ++ i)
        if(prime[i]) for(int p = i * i; p < 1048576 && p > 0; p *= i * i)
            if(prime[(p * i - 1) / (i - 1)])
                res[p] = 1;

    for(int i = 1; i < 1048576; ++ i)
        res[i] += res[i - 1];

    scanf("%d", &tests);
    for(int t = 0; t < tests; ++ t)
    {
        scanf("%d %d", &from, &to);
        printf("%d\n", res[to] - res[from - 1]);
    }

    return 0;
}

inline
void sieve(void)
{
    for(int i = 2; i < 2097152; ++ i)
        prime[i] = true;

    for(int i = 2; i * i < 2097152; ++ i)
        if(prime[i]) for(int j = i * i; j < 2097152; j += i)
            prime[j] = false;
}
