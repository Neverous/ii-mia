/* 2014
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

int length,
    MOD,
    value,
    counter[1 << 25];
long long int inv33;

int findInv33(void);
void generateHashes(int state, int size);
long long int countHashes(int state, int size);

int main(void)
{
    scanf("%d %d %d", &length, &value, &MOD);
    MOD = (1 << MOD) - 1;
    inv33 = findInv33();

    generateHashes(0, length / 2);
    printf("%lld\n", countHashes(value, (length + 1) / 2));

    return 0;
}

inline
int findInv33(void)
{
    for(int i = 1; i <= MOD; ++ i)
        if(((i * 33) & MOD) == 1)
            return i;

    return -1;
}

inline
void generateHashes(int state, int size)
{
    if(!size)
    {
        ++ counter[state];
        return;
    }

    for(int l = 1; l <= 26; ++ l)
        generateHashes(((state * 33) ^ l) & MOD, size - 1);
}

inline
long long int countHashes(int state, int size)
{
    if(!size)
        return counter[state];

    long long int count = 0;
    for(int l = 1; l <= 26; ++ l)
        count += countHashes(((state ^ l) * inv33) & MOD, size - 1);

    return count;
}
