/* 2013
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>
#include <set>

int kids,
    kid,
    out[32],
    mod[32],
    primes,
    prime[8] = {2, 3, 5, 7, 11, 13, 17, 19},
    modp = 1,
    result = 0;
bool alive[32];

int main(void)
{
    scanf("%d", &kids);
    for(int k = 0; k < kids; ++ k)
    {
        scanf("%d", &kid);
        out[kid - 1] = k;
        alive[k] = true;
    }

    for(int k = 0, l = 0; k < kids; ++ k)
    {
        mod[kids - 1 - k] = 0;
        for(; l != out[k]; l = (l + 1) % kids)
            mod[kids - 1 - k] += alive[l];

        alive[out[k]] = false;
    }

    while(primes < 8 && prime[primes] <= kids)
    {
        kid = prime[primes];
        while(prime[primes] * kid <= kids)
            prime[primes] *= kid;

        modp *= prime[primes];
        ++ primes;
    }

    for(int p = 0, c = 1; p < primes; ++ p)
    {
        while(result % prime[p] != mod[prime[p] - 1])
            result += c;

        c *= prime[p];
    }

    for(int k = 0; k < kids; ++ k)
        if(result % (k + 1) != mod[k])
        {
            puts("NIE");
            return 0;
        }

    for(int k = 1; k <= kids; ++ k)
        if(k % modp == result)
        {
            result = k;
            break;
        }

    printf("%d\n", result + 1);
    return 0;
}
