/* 2014
 * Maciej Szeptuch
 * IIUWr
 */
#include <cstdio>

int guests,
    guest[64],
    table,
    sum;
double result;

double calculate(int blocked);

int main(void)
{
    scanf("%d", &guests);
    for(int g = 0; g < guests; ++ g)
    {
        scanf("%d", &guest[g]);
        sum += guest[g];
    }

    scanf("%d", &table);
    if(sum <= table)
    {
        printf("%d\n", guests);
        return 0;
    }

    for(int b = 0; b < guests; ++ b)
        result += calculate(b);

    printf("%.9lf\n", result);
    return 0;
}

inline
double calculate(int blocked)
{
    double res = 0.0;
    double prob[64][4096] = {};
    prob[0][0] = 1.0;
    for(int g = 0; g < guests; ++ g) if(g != blocked)
        for(int c = guests - 2; c >= 0; -- c)
            for(int s = 0; s <= table - guest[g]; ++ s)
                prob[c + 1][s + guest[g]] += prob[c][s] * (c + 1.0) / (guests - c);

    for(int c = 0; c < guests; ++ c)
        for(int s = table - guest[blocked] + 1; s <= table; ++ s)
            res += prob[c][s] * c / (guests - c);

    return res;
}
