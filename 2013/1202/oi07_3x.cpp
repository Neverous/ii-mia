/* 2013
 * Maciej Szeptuch
 * IIUWr
 */
#include <cstdio>

int tests,
    numbers,
    number[1048576],
    leader, count;
bool lower, higher;

int main(void)
{
    scanf("%d", &tests);
    for(int t = 0; t < tests; ++ t)
    {
        scanf("%d", &numbers);
        count = 0;
        lower = higher = true;
        for(int n = 0; n < numbers; ++ n)
        {
            scanf("%d", &number[n]);
            if(number[n] == leader)
                ++ count;

            else
                -- count;

            if(count < 0)
            {
                leader = number[n];
                count = 1;
            }
        }

        count = 0;
        for(int n = 0; n < numbers; ++ n)
        {
            count   += number[n] == leader;
            lower   &= number[n] <= leader;
            higher  &= number[n] >= leader;
        }

        if(count <= numbers / 2 || ((numbers&1) && count == (numbers + 1) / 2 && (lower || higher)))
            puts("TAK");

        else
            puts("NIE");
    }

    return 0;
}
