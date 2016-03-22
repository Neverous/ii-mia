/* 2013
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>
#include <algorithm>

int numbers,
    number[1048576],
    start, end,
    questions;

inline bool check(const int &s, const int &e);

int main(void)
{
    scanf("%d", &numbers);
    for(int n = 0; n < numbers; ++ n)
        scanf("%d", &number[n]);

    scanf("%d", &questions);
    for(int q = 0; q < questions; ++ q)
    {
        scanf("%d %d", &start, &end);
        puts(check(start - 1, end - 1) ? "TAK" : "NIE");
    }

    return 0;
}

inline bool check(const int &s, const int &e)
{
    if(e - s < 2)
        return false;

    if(e - s > 2)
        if(check(s, (s + e) / 2) || check((s + e) / 2, e))
            return true;

    for(int a = s; a < (s + e) / 2; ++ a)
        for(int b = a + 1; b < e; ++ b)
            for(int c = std::max(b + 1, (s + e) / 2 + 1); c <= e; ++ c)
                if(number[a] + number[b] > number[c] &&
                   number[a] + number[c] > number[b] &&
                   number[b] + number[c] > number[a])
                    return true;

    return false;
}
