/* 2013
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>
#include <cstring>
#include <algorithm>

int tests,
    fl, sl,
    gcd;
char first[131072],
     second[131072];

inline bool check(void);

int main(void)
{
    scanf("%d", &tests);
    for(int t = 0; t < tests; ++ t)
    {
        scanf("%s %s", first, second);
        fl = strlen(first);
        sl = strlen(second);
        gcd = std::__gcd(fl, sl);
        puts(check() ? "YES" : "NO");
    }
}

inline bool check(void)
{
    for(int p = 0; p < gcd; ++ p)
        if(first[p] != second[p])
            return false;

    for(int p = 0; p < gcd; ++ p)
    {
        for(int f = p; f < fl; f += gcd)
            if(first[p] != first[f])
                return false;

        for(int s = p; s < sl; s += gcd)
            if(second[p] != second[s])
                return false;
    }

    return true;
}
