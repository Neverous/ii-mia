/* 2014
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>
#include <cstring>
#include <algorithm>

char cards[131072];
int total_ones, ones, eaten_ones,
    total_zeros, zeros, eaten_zeros,
    total_marks, marks,
    n;

bool p00,
     p01,
     p10,
     p11;

int main(void)
{
    scanf("%s", cards);
    n = strlen(cards);
    for(int c = 0; cards[c]; ++ c)
        switch(cards[c])
        {
            case '1':
                ++ total_ones;
                break;

            case '0':
                ++ total_zeros;
                break;

            case '?':
                ++ total_marks;
                break;
        }

    eaten_zeros = (n - 2) / 2;
    eaten_ones  = (n - 1) / 2;
    p00 = total_zeros + total_marks >= 2 + eaten_zeros;
    p11 = total_ones + total_marks >= 2 + eaten_ones;

    for(int c = 0; cards[c]; ++ c)
    {
        if( (cards[c] == '1' || cards[c] == '?')
        &&  zeros + marks >= 1 + eaten_zeros
        &&  total_ones + total_marks - std::max(0, eaten_zeros + 1 - zeros) >= 1 + eaten_ones)
            p01 = true;

        if( (cards[c] == '0' || cards[c] == '?')
        &&  ones + marks >= 1 + eaten_ones
        &&  total_zeros + total_marks - std::max(0, eaten_ones + 1 - ones) >= 1 + eaten_zeros)
            p10 = true;

        switch(cards[c])
        {
            case '1':
                ++ ones;
                break;

            case '0':
                ++ zeros;
                break;

            case '?':
                ++ marks;
                break;
        }
    }

    if(p00)
        puts("00");

    if(p01)
        puts("01");

    if(p10)
        puts("10");

    if(p11)
        puts("11");

    return 0;
}
