/* 2014
 * Maciej Szeptuch
 * IIUWr
 */
#include <cstdio>

int tests;
long long int A, B;

bool check(long long int i, long long int j);
long long int NWD(long long int a, long long int b);

int main(void)
{
    scanf("%d", &tests);
    for(int t = 0; t < tests; ++ t)
    {
        scanf("%lld %lld", &A, &B);
        puts(check(A, B) ? "Y" : "N");
    }

    return 0;
}

inline
bool check(long long int i, long long int j)
{
    long long int nwd = NWD(i, j);
    return !(nwd & (nwd - 1));
}

inline
long long int NWD(long long int a, long long int b)
{
    if(a < b)
        return NWD(b, a);

    if(!b)
        return a;

    return NWD(b, a % b);
}
