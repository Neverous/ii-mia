/* 2013
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>
#include <algorithm>

int tests,
    cities,
    weight[131072];

inline bool check(void);

int main(void)
{
    scanf("%d", &tests);
    for(int t = 0; t < tests; ++ t)
    {
        scanf("%d", &cities);
        for(int c = 0; c < cities; ++ c)
            scanf("%d", &weight[c]);

        puts(check() ? "TAK" : "NIE");
    }

    return 0;
}

inline bool check(void)
{
    int max = 0;
    int count[131072] = {};
    long long int pre[131072] = {},
                  suf[131072] = {},
                  sum = 0;
    for(int c = 0; c < cities; ++ c)
    {
        ++ count[weight[c]];
        max = std::max(weight[c], max);
        sum += weight[c];
    }

    if(sum % 2) /* nieparzysta suma stopni - nie ma jak sparować. */
        return false;

    if(max >= cities) /* za duży stopień wierzchołka */
        return false;

    /* sprawdź czy da się połączyć */
    for(int w = max, c = 0; w >= 0; -- w)
        while(count[w] --)
            weight[c ++] = w;

    /* Ile potrzebuje od początku do teraz */
    pre[0] = weight[0];
    for(int c = 1; c < cities; ++ c)
        pre[c] = pre[c - 1] + weight[c];

    /* Ile mam od następnego do końca */
    suf[cities - 1] = 0;
    for(int c = cities - 2; c >= 0; -- c)
        suf[c] = suf[c + 1] + weight[c + 1];

    /* Nie mogę brać więcej od każdego niż mam do tej pory wierzchołków */
    for(int s = 0, e = cities - 1; s < e; ++ s)
    {
        while(s < e && weight[e] < s + 1)
            -- e;

        if(s == e) break;
        suf[s] = suf[e] + (long long int)(e - s) * (s + 1);
    }

    for(int c = 0; c < cities; ++ c)
        if(suf[c] < pre[c] - (long long int)c * (c + 1)) // czy wystarczy połączeń
            return false;

    return true;
}
