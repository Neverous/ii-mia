#include<cstdio>

const int MOD = 1000000007;

int numbers;
int number;
int operations;
long long int sum;

long long int pow(const long long int base, const int power, const int mod)
{
    if(power == 0)
        return 1;

    long long int ret = pow(base, power / 2, mod);
    ret = (ret * ret) % mod;
    if(power % 2)
        ret = (ret * base) % mod;

    return ret;
}

int main(void)
{
    scanf("%d", &numbers);
    for(int n = 0; n < numbers; ++ n)
    {
        scanf("%d", &number);
        sum += number;
    }

    sum %= MOD;
    scanf("%d", &operations);
    printf("%lld\n", (pow(2, operations, MOD) * sum) % MOD);
    return 0;
}
