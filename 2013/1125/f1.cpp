/* 2013
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>

int tests,
    laps;

double pitstop,
       first[1024],
       second[1024],
       firstO[1024],
       secondO[1024],
       result;

int main(void)
{
    scanf("%d", &tests);
    for(int t = 0; t < tests; ++ t)
    {
        scanf("%d %lf", &laps, &pitstop);
        for(int l = 0; l < laps; ++ l)
        {
            scanf("%lf %lf", &first[l], &second[l]);
            if(l)
            {
                first[l]    += first[l - 1];
                second[l]   += second[l - 1];
            }
        }

        for(int l = 0; l < laps; ++ l)
        {
            firstO[l] = first[l];
            secondO[l] = second[l];
            for(int p = 0; p < l; ++ p)
            {
                if(firstO[l] > firstO[p] + pitstop + firstO[l - p - 1])
                    firstO[l] = firstO[p] + pitstop + firstO[l - p - 1];

                if(secondO[l] > secondO[p] + pitstop + secondO[l - p - 1])
                    secondO[l] = secondO[p] + pitstop + secondO[l - p - 1];
            }
        }

        result = firstO[0] + pitstop + secondO[laps - 1];
        for(int l = 0; l < laps - 1; ++ l)
        {
            if(result > firstO[l] + pitstop + secondO[laps - l - 2])
                result = firstO[l] + pitstop + secondO[laps - l - 2];
        }

        printf("%.3lf\n", result);
    }

    return 0;
}
