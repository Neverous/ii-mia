/* 2015
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>

int ingredients;
int one;
int pairs;
int result;
int two;
int without[32];

int main(void)
{
    scanf("%d %d", &ingredients, &pairs);
    for(int p = 0; p < pairs; ++ p)
    {
        scanf("%d %d", &one, &two);
        -- one;
        -- two;
        without[one] |= (1 << two);
        without[two] |= (1 << one);
    }

    for(int m = 0; m < (1 << ingredients); ++ m)
    {
        bool is_ok = true;
        for(int i = 0; is_ok && i < ingredients && (1 << i) <= m; ++ i) if(m & (1 << i))
            is_ok = !(m & without[i]);

        result += is_ok;
    }

    printf("%d\n", result);
    return 0;
}
