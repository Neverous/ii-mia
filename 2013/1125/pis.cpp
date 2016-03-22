/* 2013
 * Maciej Szeptuch
 * IIUWr
 */
#include <cstdio>
#include <cstring>

typedef long long int lld;

int tests;
lld places, people,
    speedup[128];

inline lld countSizes(const lld &root, const lld &first, const lld &second, const lld &level);
inline lld nthSize(lld start, lld pos, const lld &first, const lld &second = 0, lld level = 0);
inline lld solve(const lld &start, lld person);

int main(void)
{
    scanf("%d", &tests);
    for(int t = 0; t < tests; ++ t)
    {
        scanf("%lld %lld", &places, &people);
        lld result = solve(places, people);
        if(result == -1)
            puts("OJEJ");

        else
            printf("%lld\n", result);
    }

    return 0;
}

inline
lld solve(const lld &start, lld person)
{
    if(person == 1)
        return 1;

    if(person == 2)
        return start > 2 ? start : -1;

    person -= 2;
    lld first = start - 2,
                second = start - 2,
                firstCount = 0,
                secondCount = 1;

    while((first > 2 ? firstCount : 0) + (second > 2 ? secondCount : 0) < person && second > 2)
    {
        person -= (first > 2 ? firstCount : 0) + (second > 2 ? secondCount : 0);
        if(first == second)
        {
            if(first & 1)
            {
                first = second = first / 2;
                secondCount *= 2;
            }

            else
            {
                first = first / 2 - 1;
                second = second / 2;
                firstCount = secondCount;
            }
        }

        else
        {
            if(first & 1)
            {
                first = first / 2;
                second = second / 2;
                firstCount = 2 * firstCount + secondCount;
            }

            else
            {
                first = first / 2 - 1;
                second = second / 2;
                secondCount = 2 * secondCount + firstCount;
            }
        }
    }

    if(second < 3)
        return -1;

    memset(speedup, 0, sizeof(lld) * 128);
    // ONLY SECOND
    if(first < 3 || (second & 1 && secondCount >= person))
        return nthSize(start - 2, person, second);

    // ONLY FIRST
    if(second & 1 && secondCount < person)
        return nthSize(start - 2, person - secondCount, first);

    // BOTH
    return nthSize(start - 2, person, first, second);
}

inline
lld nthSize(lld start, lld pos, const lld &first, const lld &second, lld level)
{
    lld result = 1;
    while(start != first && start != second)
    {
        lld count = countSizes((start - 1) / 2, first, second, level ++);
        if(count >= pos)
            start = (start - 1) / 2;

        else
        {
            result += (start - 1) / 2 + 1;
            start = start / 2;
            pos -= count;
        }
    }

    return result + (start + 1) / 2;
}

inline
lld countSizes(const lld &root, const lld &first, const lld &second, const lld &level)
{
    if(!root)
        return 0;

    if(root == first || root == second)
        return (speedup[level * 2 + (root & 1)] = 2) - 1;

    if(root < first && (!second || root < second))
        return 0;

    if(speedup[level * 2 + (root & 1)] > 0)
        return speedup[level * 2 + (root & 1)] - 1;

    return (speedup[level * 2 + (root & 1)] = 1 + countSizes((root - 1) / 2, first, second, level + 1) + countSizes(root / 2, first, second, level + 1)) - 1;
}
