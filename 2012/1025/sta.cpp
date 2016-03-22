/* 2012
 * Maciej Szeptuch
 * II UWr
 */
#include<cstdio>
#include<algorithm>

using namespace std;

int numbers,
    number[262144],
    result;

int main(void)
{
    scanf("%d", &numbers);
    for(int n = 0; n < numbers; ++ n)
        scanf("%d", &number[n]);

    sort(number, number + numbers);
    for(int n = 0; n < numbers - 2; ++ n)
        result = max(
            max(abs(number[n] + number[numbers - 1] - 2 * number[n + 1]),
                abs(number[n] + number[numbers - 1] - 2 * number[numbers - 2])),
            result
        );

    for(int n = 2; n < numbers; ++ n)
        result = max(
            max(abs(number[n] + number[0] - 2 * number[n - 1]),
                abs(number[n] + number[0] - 2 * number[1])),
            result
        );

    printf("%.2f\n", 1.0 * result / 3);

}
