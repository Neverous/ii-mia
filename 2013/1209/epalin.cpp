/* 2013
 * Maciej Szeptuch
 * IIUWr
 */
#include <cstdio>
#include <cstring>

char word[262144];

int findSuffix(void);

int main(void)
{
    while(scanf("%s", word) != -1)
    {
        int l = findSuffix();
        printf("%s", word);
        for(int w = strlen(word) - l - 1; w >= 0; -- w)
            putchar(word[w]);

        puts("");
    }

    return 0;
}

inline
int findSuffix(void)
{
    int pi[262144] = {};
    int len = strlen(word);
    int i = 1, j = 0, w = 0;
    for(w = len - 2; w >= 0; ++ i, -- w)
    {
        while(j && word[w] != word[len - 1 - j])
            j = pi[j - 1];

        if(word[w] == word[len - 1 - j])
            ++ j;

        pi[i] = j;
    }

    ++ i;
    for(w = 0, j = 0; word[w]; ++ i, ++ w)
    {
        while(j && word[w] != word[len - 1 - j])
            j = pi[j - 1];

        if(word[w] == word[len - 1 - j])
            ++ j;

        pi[i] = j;
    }

    return pi[2 * strlen(word)];
}
