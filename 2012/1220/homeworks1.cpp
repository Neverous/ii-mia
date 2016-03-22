/* 2013
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>
#include <cstring>

#define SIZE (1 << 22)

int tests,
    bits;
char sequence[SIZE + 1],
     word[(1 << 20) + 1],
     was;

void preprocess(void);
void solve(void);

int main(void)
{
    preprocess();
    scanf("%d", &tests);
    for(int t = 0; t < tests; ++ t)
    {
        scanf("%d", &bits);
        word[bits] = 0;
        for(int b = 0; b < bits; ++ b)
            scanf(" %c", &word[b]);

        solve();
    }

    return 0;
}

void preprocess(void)
{
    sequence[0] = '0';
    for(int t = 1, s = 1; s < SIZE; t <<= 1)
        for(int j = 0; j < t && s < SIZE; ++ j, ++ s)
            sequence[s] = sequence[j] ^ 1;

    sequence[SIZE] = 0;
}

void solve(void)
{
    char *result = sequence;
    for(int b = 0; b < bits; ++ b)
    {
        if(!result)
        {
            printf("-1 ");
            continue;
        }

        was = word[b + 1];
        word[b + 1] = 0;
        if(word[b] != result[b])
            result = strstr(result + 1, word);

        if(result)
            printf("%ld ", result - sequence);

        else
            printf("-1 ");

        word[b + 1] = was;
    }

    puts("");
}
