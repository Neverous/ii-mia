/* 2013
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>

int tests,
    cities,
    counted[2048][2048],
    connected[2048][2048];

template<class Type>
void readNumber(Type& out);

inline bool check(void);

int main(void)
{
    readNumber<int>(tests);
    for(int tt = 0; tt < tests; ++ tt)
    {
        readNumber<int>(cities);
        for(int f = 0; f < cities; ++ f)
            for(int t = 0; t < cities; ++ t)
                readNumber<int>(connected[f][t]);

        for(int f = 0; f < cities; ++ f)
            for(int t = 0; t < cities; ++ t)
                readNumber<int>(counted[f][t]);

        puts(check() ? "TAK" : "NIE");
    }

    return 0;
}

inline bool check(void)
{
    const int MOD = 10009;
    int first[2048] = {},
        second[2048] = {},
        temp[2048] = {};

    for(int c = 0; c < cities; ++ c)
        first[c] = second[c] = rand() % MOD;

    for(int tt = 0; tt < 2; ++ tt)
    {
        for(int f = 0; f < cities; ++ f)
            for(int t = 0; t < cities; ++ t)
                temp[f] = (temp[f] + first[t] * connected[f][t]) % MOD;

        memcpy(first, temp, 2048 * sizeof(int));
        memset(temp, 0, 2048 * sizeof(int));
    }

    for(int f = 0; f < cities; ++ f)
        for(int t = 0; t < cities; ++ t)
            temp[f] = (temp[f] + second[t] * counted[f][t]) % MOD;

    for(int c = 0; c < cities; ++ c)
        if(first[c] != temp[c])
            return false;

    return true;
}

const int BUFFER = 4096;
int p = BUFFER - 1;
char buffer[BUFFER];

template<class Type>
inline void readNumber(Type& number)
{
    number = 0;
    while((buffer[p] < '0' || buffer[p] > '9') && ++ p)
        if(p == BUFFER)
        {
            fread(buffer, sizeof(char), BUFFER, stdin);
            p = 0;
        }

    while(buffer[p] >= '0' && buffer[p] <= '9')
    {
        number = number * 10 + buffer[p] - '0';
        ++ p;

        if(p == BUFFER)
        {
            fread(buffer, BUFFER, sizeof(char), stdin);
            p = 0;
        }
    }
}

