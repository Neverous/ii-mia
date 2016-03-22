/* 2014
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>
#include <cstring>
#include <algorithm>

int tests,
    length,
    queries,
    tim[1024],
    sortme[1024],
    cycle;
char particle[16],
     result[1024][16];

bool compareTime(int a, int b);

int main(void)
{
    scanf("%d", &tests);
    for(int t = 0; t < tests; ++ t)
    {
        scanf("%d %d %s", &length, &queries, particle);
        cycle = 0;
        char temp[16]; memcpy(temp, particle, length);
        do
        {
            if(temp[cycle % length] == '+')
                temp[(length + cycle - 1) % length] ^= 6;

            temp[cycle % length] ^= 6;
            ++ cycle;
        }
        while(memcmp(particle, &temp[cycle % length], length - cycle % length) || memcmp(&particle[length - cycle % length], temp, cycle % length));

        for(int q = 0; q < queries; ++ q)
        {
            scanf("%d", &tim[q]);
            tim[q] %= cycle;
            sortme[q] = q;
        }

        std::sort(sortme, sortme + queries, compareTime);
        for(int q = 0, tt = 0; q < queries; ++ q)
        {
            while(tt < tim[sortme[q]])
            {
                if(particle[tt % length] == '+')
                    particle[(length + tt - 1) % length] ^= 6;

                particle[tt % length] ^= 6;
                ++ tt;
            }

            memcpy(result[sortme[q]], &particle[tt % length], length - tt % length);
            memcpy(&result[sortme[q]][length - tt % length], particle, tt % length);
            result[sortme[q]][length] = 0;
        }

        for(int q = 0; q < queries; ++ q)
            puts(result[q]);
    }

    return 0;
}

inline
bool compareTime(int a, int b)
{
    if(tim[a] < tim[b])
        return true;

    if(tim[a] > tim[b])
        return false;

    return a < b;
}
