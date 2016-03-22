/* 2013
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>

const int STEP = 1 << 15;
const long long int LIMIT = 250000000;
int primes[LIMIT];

int main(void)
{
    for(int i = 2; i < LIMIT; ++ i)
        primes[i] = 1;

    printf("int saved[] = {1,");
    for(long long int n = 2; n <= LIMIT; ++ n)
    {
        if(primes[n])
            for(long long int j = n * n; j <= LIMIT; j += n)
                primes[j] = 0;

        primes[n] += primes[n - 1];
        if((n & (STEP - 1)) == 0)
            printf("%d,", primes[n]);
    }

    puts("};");
}
