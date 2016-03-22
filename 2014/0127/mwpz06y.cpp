/* 2014
 * Maciej Szeptuch
 * IIUWr
 */
#include <cstdio>

int tests,
    length,
    number,
    fib[64];

void preprocess(void);
void printNumber(int len, int position);

int main(void)
{
    preprocess();
    scanf("%d", &tests);
    for(int t = 0; t < tests; ++ t)
    {
        scanf("%d %d", &length, &number);
        printNumber(length, number);
        puts("");
    }

    return 0;
}

inline
void preprocess(void)
{
    fib[0] = 1;
    fib[1] = 2;
    for(int f = 2; f < 64; ++ f)
        fib[f] = fib[f-2] + fib[f-1];
}

inline
void printNumber(int len, int position)
{
    if(position > fib[len])
    {
        printf("-1");
        return;
    }

    while(len)
    {
        if(position > fib[len - 1])
        {
            putchar('1');
            position -= fib[len - 1];
        }

        else
            putchar('0');

        -- len;
    }
}
