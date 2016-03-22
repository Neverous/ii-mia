/* 2016
 * Maciej Szeptuch
 * II UWr
 */
#include <algorithm>
#include <cstdio>

char number[16][16];
int digits;
int numbers;
int perm[16];

long long int count_diff(void);

int main(void)
{
    scanf("%d %d", &numbers, &digits);
    for(int n = 0; n < numbers; ++ n)
        scanf("%s", number[n]);

    for(int d = 0; d < digits; ++ d)
        perm[d] = d;

    long long int result = (1LL << 60);
    do
    {
        long long int current = count_diff();
        if(current < result)
            result = current;
    }
    while(std::next_permutation(perm, perm + digits));

    printf("%lld\n", result);
    return 0;
}

long long int count_diff(void)
{
    int possible_min[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int possible_mins = numbers;
    int possible_max[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int possible_maxs = numbers;

    long long int max = 0;
    long long int min = 0;
    for(int d = 0; d < digits; ++ d)
    {
        int mind = '9';
        int maxd = '0';
        for(int n = 0; n < possible_mins; ++ n)
            if(number[possible_min[n]][perm[d]] < mind)
                mind = number[possible_min[n]][perm[d]];

        for(int n = 0; n < possible_maxs; ++ n)
            if(number[possible_max[n]][perm[d]] > maxd)
                maxd = number[possible_max[n]][perm[d]];

        for(int n = 0; n < possible_mins;)
            if(number[possible_min[n]][perm[d]] != mind)
                std::swap(possible_min[n], possible_min[-- possible_mins]);
            else
                ++ n;

        for(int n = 0; n < possible_maxs;)
            if(number[possible_max[n]][perm[d]] != maxd)
                std::swap(possible_max[n], possible_max[-- possible_maxs]);
            else
                ++ n;

        max = max * 10 + maxd - '0';
        min = min * 10 + mind - '0';
    }

    return max - min;
}
