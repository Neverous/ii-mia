/* 2015
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>
#include <cstring>

const int MOD = 1000000007;

int levels;

long long int* fixup(int length, long long int val[]);
void multiply(int length, long long int to[], long long int from[]);
long long int* max(int length, long long int A[], long long int B[]);

int main(void)
{
    while(scanf("%d", &levels) != 0 && levels > 0)
    {
        long long int tree[(1 << levels)][levels];
        memset(tree, 0, sizeof(long long int) * (1 << levels) * levels);
        for(int n = 1; n < (1 << levels); ++ n)
            scanf("%lld", &tree[n][0]);

        for(int n = (1 << (levels - 1)) - 1; n > 0; -- n)
            multiply(levels, tree[n], max(levels, tree[2 * n], tree[2 * n + 1]));

        printf("%lld\n", tree[1][0]);
    }

    return 0;
}

inline
long long int* fixup(int length, long long int val[])
{
    for(int l = 0; l < length - 1; ++ l)
        if(val[l] > MOD)
        {
            val[l + 1] += val[l] / MOD;
            val[l] %= MOD;
        }

    return val;
}

inline
void multiply(int length, long long int to[], long long int from[])
{
    long long int result[length]; memset(result, 0, sizeof(long long int) * length);
    for(int l = 0; l < length; ++ l)
    {
        for(int p = 0; p + l < length; ++ p)
            result[p + l] += to[l] * from[p];

        fixup(length, result);
    }

    for(int l = 0; l < length; ++ l)
        to[l] = result[l];
}

inline
long long int* max(int length, long long int A[], long long int B[])
{
    for(int l = length - 1; l >= 0; -- l)
    {
        if(A[l] > B[l])
            return A;

        if(B[l] > A[l])
            return B;
    }

    return B;
}
