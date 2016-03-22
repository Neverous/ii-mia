/* 2016
 * Maciej Szeptuch
 * II UWr
 */
#include <algorithm>
#include <cstdio>
#include <queue>

const int MAX_COWS = 800001;
const int MAX_DEADLINE = 10001;
int cows;
int sort_me[MAX_COWS];
int max_deadline;
int milk;
int deadline;
std::vector<int> cow_at_deadline[MAX_DEADLINE];

int main(void)
{
    scanf("%d", &cows);
    for(int c = 0; c < cows; ++ c)
    {
        scanf("%d %d", &milk, &deadline);
        cow_at_deadline[deadline].push_back(milk);
        max_deadline = std::max(deadline, max_deadline);
    }

    int result = 0;
    std::priority_queue<int> que;
    for(int t = max_deadline; t > 0; -- t)
    {
        for(unsigned int c = 0; c < cow_at_deadline[t].size(); ++ c)
            que.push(cow_at_deadline[t][c]);

        if(!que.empty())
        {
            result += que.top();
            que.pop();
        }
    }

    printf("%d\n", result);
    return 0;
}
