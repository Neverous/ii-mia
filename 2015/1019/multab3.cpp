/* 2015
 * Maciej Szeptuch
 * II UWr
 */
#include <algorithm>
#include <cstdio>

int m;
int n;
long long int k;

bool count(long long int value);

int main(void)
{
    scanf("%d %d %lld", &n, &m, &k);
    if(n > m)
        std::swap(n, m);

    long long int s = 1;
    long long int e = 1LL * n * m;
    while(s < e)
    {
        long long int mid = (s + e) / 2;
        if(count(mid))
            s = mid + 1;

        else
            e = mid;
    }

    printf("%lld\n", s);
    return 0;
}

inline
bool count(long long int value)
{
    long long int wanted = k;
    for(int p = 1; p <= n && wanted > 0 && p <= value; ++ p)
        wanted -= std::min(1LL * m, value / p);

    return wanted > 0;
}
