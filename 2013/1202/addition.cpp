/* 2013
 * Maciej Szeptuch
 * IIUWr
 */
#include <cstdio>
#include <queue>

int numbers,
    number;
long long int result;

std::priority_queue<int, std::vector<int>, std::greater<int> > que;

int main(void)
{
    while(scanf("%d", &numbers) != -1 && numbers)
    {
        result = 0;
        for(int n = 0; n < numbers; ++ n)
        {
            scanf("%d", &number);
            que.push(number);
        }

        while(que.size() > 1)
        {
            int first = que.top(); que.pop();
            int second = que.top(); que.pop();
            que.push(first + second);
            result += first + second;
        }

        que.pop();
        printf("%lld\n", result);
    }

    return 0;
}
