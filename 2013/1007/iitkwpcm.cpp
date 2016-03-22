/* 2013
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>
#include <cmath>

int tests;
long long unsigned int number;
const int SIEVE_SIZE = 1048576;
bool smallprime[SIEVE_SIZE];

bool isspecial(long long unsigned int num);
bool isprime(const long long unsigned int num);
long long unsigned int fastPower(const long long unsigned int base, const long long unsigned int power, const long long unsigned int MOD);
long long unsigned int multiply(long long unsigned int a, const long long unsigned int b, const long long unsigned int MOD);

int main(void)
{
    for(int i = 0; i < SIEVE_SIZE; ++ i)
        smallprime[i] = true;

    for(int i = 2; i * i < SIEVE_SIZE; ++ i)
        if(smallprime[i]) for(int j = i * i; j < SIEVE_SIZE; j += i)
            smallprime[j] = false;

    scanf("%d", &tests);
    for(int t = 0; t < tests; ++ t)
    {
        scanf("%llu", &number);
        printf("%llu\n", isspecial(number) ? number - 1 : 1);
    }

    return 0;
}

inline
bool isspecial(long long unsigned int num)
{
    if(num % 4 == 0)
        return num == 4;

    if(num % 2 == 0)
        num /= 2;

    if(isprime(num))
        return true;

    long long unsigned int root = 1337;
    for(int r = 2; r < 38 && root > 2; ++ r)
    {
        root = round(powl(num, 1.0L / r));
        if(fastPower(root, r, __LONG_LONG_MAX__) != num)
            continue;

        if(isprime(root))
            return true;
    }

    return false;
}

inline
bool isprime(const long long unsigned int num)
{
    if(num <= 3)
        return true;

    if(num < SIEVE_SIZE)
        return smallprime[num];

    const unsigned int base[4] = {13, 17, 19, 23};
    int even = 0;
    long long unsigned int odd = num - 1;
    while(odd % 2 == 0)
    {
        ++ even;
        odd /= 2;
    }

    for(int b = 0; b < 4 && base[b] < num - 1; ++ b)
    {
        long long unsigned int test = fastPower(base[b], odd, num);
        if(test == 1 || test == num - 1)
            continue;

        bool composite = true;
        for(int e = 0; e < even - 1 && composite; ++ e)
        {
            test = multiply(test, test, num);
            if(test == 1)
                return false;

            if(test == num - 1)
                composite = false;
        }

        if(composite)
            return false;
    }

    return true;
}

inline
long long unsigned int fastPower(const long long unsigned int base, const long long unsigned int power, const long long unsigned int MOD)
{
    if(power == 1)
        return base;

    long long unsigned int half = fastPower(base, power / 2, MOD);
    half = multiply(half, half, MOD);
    if(power % 2)
        half = multiply(half, base, MOD);

    return half;
}

inline
long long unsigned int multiply(long long unsigned int a, const long long unsigned int b, const long long unsigned int MOD)
{
    long long unsigned int result = 0;
    for(long long unsigned int p = 1; p <= b; p *= 2)
    {
        if(b & p)
        {
            result += a;
            if(result > MOD)
                result -= MOD;
        }

        a *= 2;
        if(a > MOD)
            a -= MOD;
    }

    return result;
}
