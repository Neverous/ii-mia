/* 2014
 * Maciej Szeptuch
 * IIUWr
 */
#include <cstdio>
#include <map>

int people,
    primes,
    prime[8192];
std::map<int, int> speedup;

inline int MIN(int a, int b) { return a<b?a:b; }
void pre(void);
int solve(int count);

int main(void)
{
    pre();
    scanf("%d", &people);
    printf("%d\n", solve(people));
    return 0;
}

int solve(int count)
{
    if(count < 3)
        return count;

    if(speedup.count(count))
        return speedup.at(count);

    int best = count / 2 + 1;
    for(int p = 0; p < primes && prime[p] * prime[p] <= count; ++ p) for(long long int div = prime[p]; div < count && count % div == 0; div *= prime[p])
    {
        best = MIN(best, solve(div) * (count / div / 2 + 1));
        best = MIN(best, solve(count / div) * (div / 2 + 1));
    }

    return speedup[count] = best;
}

void pre(void)
{
    bool sieve[1 << 16];
    for(int p = 2; p < (1 << 16); ++ p)
        sieve[p] = true;

    for(int p = 2; p < (1 << 16); ++ p) if(sieve[p])
    {
        prime[primes ++] = p;
        for(long long int j = 1LL * p * p; j < (1 << 16); j += p)
            sieve[j] = false;
    }
}
