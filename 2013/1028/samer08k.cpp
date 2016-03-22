/* 2013
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>

int numbers,
    number[16384],
    sum,
    jumps[16384];

bool visited[16384];

int shrink(void);
bool checkRegular(int wanted);

int main(void)
{
    while(scanf("%d", &numbers) != -1 && numbers)
    {
        sum = 0;
        for(int n = 0; n < numbers; ++ n)
        {
            scanf("%d", &number[n]);
            sum += number[n];
        }

        printf("%d\n", shrink());
    }

    return 0;
}

inline
int shrink(void)
{
    for(int k = numbers; k > 2; -- k)
        if(sum % k == 0 && checkRegular(sum / k))
            return numbers - k;

    return -1;
}

inline
bool checkRegular(int wanted)
{
    for(int j = 0; j < numbers; ++ j)
    {
        jumps[j] = -1;
        visited[j] = false;
    }

    int act = 0;
    for(int i = 0, j = 0; i < numbers; ++ i)
    {
        while(act < wanted)
        {
            act += number[j];
            j = (j + 1) % numbers;
        }

        if(act == wanted)
            jumps[i] = j;

        act -= number[i];
    }

    for(int i = 0; i < numbers; ++ i)
    {
        if(visited[i])
            continue;

        visited[i] = true;
        int j = jumps[i];
        while(j != -1 && !visited[j])
        {
            visited[j] = true;
            j = jumps[j];
        }

        if(j == i)
            return true;
    }

    return false;
}
