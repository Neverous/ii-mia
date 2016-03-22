/* 2013
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>
#include <cstring>

const int MOD = 1000000007;

int verts,
    edges,
    length,
    from, to;
long long int power[128][128],
              result[128][128];

void fastPower(int pow);
void multiply(long long int dest[128][128], const long long int A[128][128], const long long int B[128][128]);

int main(void)
{
    scanf("%d %d %d", &verts, &edges, &length);
    for(int e = 0; e < edges; ++ e)
    {
        scanf("%d %d", &from, &to); -- from; -- to;
        power[from][to] = 1;
    }

    power[verts - 1][verts] = 1;
    power[verts][verts] = 1;

    for(int v = 0; v <= verts; ++ v)
        result[v][v] = 1;

    fastPower(length + 1);
    printf("%lld\n", result[0][verts]);
    return 0;
}

inline
void fastPower(int pow)
{
    for(; pow > 0; pow /= 2)
    {
        if(pow & 1)
            multiply(result, result, power);

        multiply(power, power, power);
    }
}

inline
void multiply(long long int dest[128][128], const long long int A[128][128], const long long int B[128][128])
{
    long long int res[128][128] = {};
    for(int h = 0; h <= verts; ++ h)
        for(int w = 0; w <= verts; ++ w)
            for(int t = 0; t <= verts; ++ t)
            {
                res[h][w] += A[h][t] * B[t][w];
                if(res[h][w] > MOD)
                    res[h][w] %= MOD;
            }

    memcpy(dest, res, 128 * 128 * sizeof(long long int));
}
