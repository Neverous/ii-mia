/* 2013
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>
#include <vector>
#include <queue>
#include <cassert>

int switches,
    weight[524288],
    ans[524288];
std::pair<int, int> swit[524288];
std::vector<std::pair<int, int> > graph[524288];
std::queue<int> que;

void relaxLeaves(void);

int main(void)
{
    scanf("%d", &switches);
    for(int s = 1; s <= switches; ++ s)
    {
        scanf("%d %d", &swit[s].first, &swit[s].second);
        graph[swit[s].first].push_back(std::make_pair(swit[s].second, s));
        graph[swit[s].second].push_back(std::make_pair(swit[s].first, s));
        ++ weight[swit[s].second];
        ++ weight[swit[s].first];
    }

    for(int s = 1; s <= switches; ++ s)
        if(weight[s] == 1)
            que.push(s);

    relaxLeaves();
    for(int s = 1; s <= switches; ++ s)
        if(weight[s] > 2)
        {
            puts("NIE");
            return 0;
        }

    while(true)
    {
        for(int s = 1; s <= switches; ++ s)
            if(!ans[s])
            {
                ans[s] = swit[s].first < swit[s].second ? swit[s].first : swit[s].second;
                que.push(ans[s]);
                weight[ans[s]] = 0;
                for(unsigned int n = 0; n < graph[ans[s]].size(); ++ n)
                {
                    if(ans[graph[ans[s]][n].second])
                        continue;

                    ans[graph[ans[s]][n].second] = graph[ans[s]][n].first;
                }

                ans[s] = 0;
                break;
            }

        if(que.empty())
            break;

        relaxLeaves();
    }

    for(int s = 1; s <= switches; ++ s)
    {
        assert(ans[s]);
        printf("%d ", ans[s]);
    }

    puts("");
    return 0;
}

void relaxLeaves(void)
{
    while(!que.empty())
    {
        int act = que.front(); que.pop();
        weight[act] = 0;
        for(unsigned int n = 0; n < graph[act].size(); ++ n)
        {
            if(ans[graph[act][n].second])
                continue;

            if(-- weight[graph[act][n].first] == 1)
                que.push(graph[act][n].first);

            ans[graph[act][n].second] = act;
        }
    }
}
