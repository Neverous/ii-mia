/* 2015
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>

int numbers;
int number[1048576];
int result;

int main(void)
{
    scanf("%d", &numbers);
    for(int n = 0; n < numbers; ++ n)
        scanf("%d", &number[n]);

    for(int n = 0; n < numbers; ++ n)
    {
        if(!number[n])
            continue;

        ++ result;
        int j = n + 1;
        while(number[j - 1])
        {
            int b = number[j - 1];
            number[j - 1] = 0;
            j = b;
        }
    }

    printf("%d\n", result - 1);
    return 0;
}
