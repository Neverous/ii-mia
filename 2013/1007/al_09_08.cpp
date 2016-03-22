/* 2013
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>

int tests,
    count,
    symbol;
char word[131072],
     pattern[131072];

void countPatterns(char replacement);

int main(void)
{
    scanf("%d", &tests);
    for(int t = 0; t < tests; ++ t)
    {
        count = 0;
        symbol = -1;
        scanf("%s %s", word, pattern);
        for(int p = 0; pattern[p]; ++ p)
            if(pattern[p] == '?')
            {
                symbol = p;
                break;
            }

        if(symbol == -1)
            countPatterns('?');

        else
            for(int l = 0; l < 26; ++ l)
                countPatterns('a' + l);


        printf("%d\n", count);
    }

    return 0;
}

void countPatterns(char replacement)
{
    if(symbol != -1)
        pattern[symbol] = replacement;

    int pi[262144] = {};
    int p = 0,
        w = 0,
        j = 0;
    for(p = 1; pattern[p]; ++ p)
    {
        while(j && pattern[p] != pattern[j])
            j = pi[j - 1];

        if(pattern[p] == pattern[j])
            pi[p] = ++ j;
    }

    ++ p;
    j = 0;
    for(w = 0; word[w]; ++ w)
    {
        while(j && word[w] != pattern[j])
            j = pi[j - 1];

        if(word[w] == pattern[j])
            pi[p + w] = ++ j;

        if(pi[p + w] == p - 1)
            ++ count;
    }

    return;
}
