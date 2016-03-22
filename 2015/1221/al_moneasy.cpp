/* 2016
 * Maciej Szeptuch
 * II UWr
 */
#include <algorithm>
#include <cstdio>
#include <map>

char throws[1048576];
int balanced[4194304];

int main(void)
{
    scanf("%s", throws);
    int result = 0;
    int balance = 1048576;
    balanced[balance] = 1;
    for(int t = 0; throws[t]; ++ t)
    {
        balance += throws[t] == 'A' ? -1 : 2;
        if(balanced[balance] > 0)
            result = std::max(result, t + 2 - balanced[balance]);

        else
            balanced[balance] = t + 2;
    }

    printf("%d\n", result);
    return 0;
}
