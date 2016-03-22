/* 2012
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>

int poly,
    co;

long long int res,
              newt[32];

void countNewt(const int &row);

int main(void)
{
    scanf("%d", &poly);
    countNewt(poly);
    for(int p = 0; p <= poly; ++ p)
    {
        scanf("%d", &co);
        res += newt[p] * co;
    }

    printf("%lld\n", res);
    return 0;
}

#define $(x) (x % 2)

void countNewt(const int &row)
{
    long long int tmp[2][32] = {};
    tmp[0][0] = tmp[0][1] = 1;
    tmp[1][0] = 1;
    for(int r = 1; r <= row; ++ r)
        for(int c = 1; c <= r + 1; ++ c)
            tmp[$(r)][c] = tmp[!$(r)][c - 1] + tmp[!$(r)][c];

    for(int r = 0; r <= row + 1; ++ r)
    {
        newt[r] = tmp[$(row)][r];
        if($(r) ^ $(row))
            newt[r] *= -1;

        //printf("%lld\n", newt[r]);
    }

    return;
}
