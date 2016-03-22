/* 2014
 * Maciej Szeptuch
 * IIUWr
 */
#include <cstdio>

int numbers,
    count[16],
    prm[16],
    cprm[16][16],
    sum;

void pre(void);
void mul(int x);
void div(int x);
void print(void);

int main(void)
{
    pre();
    scanf("%d", &numbers);
    mul(numbers);
    for(int n = 0; n < numbers; ++ n)
    {
        scanf("%d", &count[n]);
        div(count[n]);
        sum += count[n] * (n + 1);
    }

    if(sum != numbers)
    {
        puts("0");
        return 0;
    }

    print();
    return 0;
}

void mul(int x)
{
    for(int c = 2; c <= x; ++ c)
        for(int p = 0; p < 16; ++ p)
            prm[p] += cprm[c][p];
}

void div(int x)
{
    for(int c = 2; c <= x; ++ c)
        for(int p = 0; p < 16; ++ p)
            prm[p] -= cprm[c][p];
}

void print(void)
{
    long long int res = 1;
    for(int p = 0; p < 16; ++ p)
        while(prm[p] -- > 0)
            res *= p;

    printf("%lld\n", res);
}

void pre(void)
{
    for(int n = 2; n < 16; ++ n)
        for(int p = 2, x = n; p <= x && x > 1; ++ p)
            while(x % p == 0)
            {
                ++ cprm[n][p];
                x /= p;
            }
}
