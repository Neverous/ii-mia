/* 2013
 * Maciej Szeptuch
 * IIUWr
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>

int patterns,
    len[16],
    perm[16] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15},
    sum;
long long unsigned int hash[16],
                       temphash,
                       result;
char pattern[131072],
     text[1048576];
std::map<long long unsigned int, int> mapped;

long long unsigned int fastPower(long long unsigned int b, long long unsigned int p);

int main(void)
{
    scanf("%d", &patterns);
    for(int p = 0; p < patterns; ++ p)
    {
        scanf("%s", pattern);
        sum += len[p] = strlen(pattern);
        for(int i = 0; pattern[i]; ++ i)
            hash[p] = hash[p] * 31 + pattern[i] - 'a';

        //printf("%d: %llu\n", p, hash[p]);
    }

    scanf("%s", text);
    temphash = 0;
    for(int t = 0; t < sum; ++ t)
        temphash = 31 * temphash + text[t] - 'a';

    ++ mapped[temphash];
    //printf(":%d: %llu\n", 0, temphash);
    for(int t = 1; text[t + sum - 1]; ++ t)
    {
        temphash = (temphash - (text[t - 1] - 'a') * fastPower(31, sum - 1)) * 31 + text[t + sum - 1] - 'a';
        ++ mapped[temphash];
        //printf(":%d: %llu\n", t, temphash);
    }

    do
    {
        temphash = 0;
        for(int p = 0; p < patterns; ++ p)
            temphash = temphash * fastPower(31, len[perm[p]]) + hash[perm[p]];

        result += mapped[temphash];
        //printf(".%llu\n", temphash);
    }
    while(std::next_permutation(perm, perm + patterns));

    printf("%llu\n", result);
    return 0;
}

inline
long long unsigned int fastPower(long long unsigned int b, long long unsigned int p)
{
    if(!p)
        return 1LLU;

    long long unsigned int mid = fastPower(b, p / 2);
    mid *= mid;

    if(p&1)
        mid *= b;

    return mid;
}
