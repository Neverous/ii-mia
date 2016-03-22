/* 2015
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>
#include <queue>

int number;
int numbers;
int seq[1048576];
std::deque<std::pair<int, int> > levels;

int main(void)
{
    while(scanf("%d", &numbers) != -1 && numbers)
    {
        levels.clear();
        int last = 0;
        for(int n = 0; n < numbers; ++ n)
        {
            scanf("%d", &seq[n]);
            last += seq[n];
            while(!levels.empty() && levels.back().first >= last)
                levels.pop_back();

            levels.push_back(std::make_pair(last, n));
        }

        if(last < 0)
        {
            printf("0\n");
            continue;
        }

        int ground = 0;
        int result = 0;
        for(int n = 0; n < numbers; ++ n)
        {
            if(levels.front().first - ground >= 0)
                ++ result;

            if(levels.front().second == n)
                levels.pop_front();

            last += seq[n];
            ground += seq[n];
            while(!levels.empty() && levels.back().first >= last)
                levels.pop_back();

            levels.push_back(std::make_pair(last, n + numbers));
        }

        printf("%d\n", result);
    }

    return 0;
}
