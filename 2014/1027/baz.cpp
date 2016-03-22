/* 2015
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>
#include <algorithm>

int products,
    price,
    odd[1048576], odd_count,
    even[1048576], even_count,
    days,
    sortMe[1048576];
long long int   day[1048576],
                oddMax[2][3],
                evenMax[2][3];

inline
bool compareDays(const int a, const int b)
{
    return day[a] < day[b];
}

int main(void)
{
    scanf("%d", &products);
    for(int p = 0; p < products; ++ p)
    {
        scanf("%d", &price);
        if(price % 2)
            odd[odd_count ++] = price;

        else
            even[even_count ++] = price;
    }

    scanf("%d", &days);
    for(int d = 0; d < days; ++ d)
    {
        scanf("%lld", &day[d]);
        sortMe[d] = d;
    }

    std::sort(odd, odd + odd_count);
    std::reverse(odd, odd + odd_count);
    std::sort(even, even + even_count);
    std::reverse(even, even + even_count);
    std::sort(sortMe, sortMe + days, compareDays);

    if(odd_count == 0)
        oddMax[1][0] = -1;

    else
    {
        oddMax[1][0] = odd[0];
        oddMax[1][1] = 1;
    }

    if(even_count == 0)
        evenMax[1][0] = -1;

    else
    {
        evenMax[1][0] = even[0];
        evenMax[1][2] = 1;
    }

    for(int c = 2, d = 0; d < days; ++ d)
    {
        while(c <= day[sortMe[d]])
        {
            long long int *oddCur     = oddMax[c&1];
            long long int *evenCur    = evenMax[c&1];
            long long int *oddPrev    = oddMax[!(c&1)];
            long long int *evenPrev   = evenMax[!(c&1)];

            oddCur[0] = -1;
            evenCur[0] = -1;

            long long int res;

            // ODD
            if(oddPrev[0] != -1 && oddPrev[2] < even_count && (res = oddPrev[0] + even[oddPrev[2]]) > oddCur[0])
            {
                oddCur[0] = res;
                oddCur[1] = oddPrev[1];
                oddCur[2] = oddPrev[2] + 1;
            }

            if(evenPrev[0] != -1 && evenPrev[1] < odd_count && (res = evenPrev[0] + odd[evenPrev[1]]) > oddCur[0])
            {
                oddCur[0] = res;
                oddCur[1] = evenPrev[1] + 1;
                oddCur[2] = evenPrev[2];
            }

            // EVEN
            if(evenPrev[0] != -1 && evenPrev[2] < even_count && (res = evenPrev[0] + even[evenPrev[2]]) > evenCur[0])
            {
                evenCur[0] = res;
                evenCur[1] = evenPrev[1];
                evenCur[2] = evenPrev[2] + 1;
            }

            if(oddPrev[0] != -1 && oddPrev[1] < odd_count && (res = oddPrev[0] + odd[oddPrev[1]]) > evenCur[0])
            {
                evenCur[0] = res;
                evenCur[1] = oddPrev[1] + 1;
                evenCur[2] = oddPrev[2];
            }

            ++ c;
        }

        day[sortMe[d]] = oddMax[!(c&1)][0];
    }

    for(int d = 0; d < days; ++ d)
        printf("%lld\n", day[d]);

    return 0;
}
