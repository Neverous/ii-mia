/* 2013
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int tests,
    locks,
    opens,
    box,
    father[131072],
    dist[131072];

vector<int> graph[131072];

int bfs(void);

int main(void)
{
    scanf("%d", &tests);
    for(int t = 0; t < tests; ++ t)
    {
        scanf("%d", &locks);
        graph[locks - 1].clear();
        for(int l = 0; l < locks - 1; ++ l)
        {
            graph[l].clear();
            scanf("%d", &opens);
            for(int o = 0; o < opens; ++ o)
            {
                scanf("%d", &box);
                graph[l].push_back(box - 1);
            }

            sort(graph[l].begin(), graph[l].end());
        }

        printf("%d\n", bfs());
        if(dist[locks - 1] != -1)
        {
            vector<int> sortMe;
            for(int v = father[locks - 1]; v >= 0; v = father[v])
                sortMe.push_back(v + 1);

            reverse(sortMe.begin(), sortMe.end());
            for(unsigned int s = 0; s < sortMe.size(); ++ s)
                printf("%d ", sortMe[s]);

            puts("");
        }
        
        puts("");
    }

    return 0;
}

int bfs(void)
{
    bool visited[131072] = {};
    queue<int> que;
    que.push(0);
    visited[0] = true;
    father[0] = -1;
    dist[locks - 1] = -1;
    while(!que.empty())
    {
        int act = que.front(); que.pop();
        if(act == locks - 1)
            return dist[act];

        for(unsigned int n = 0; n < graph[act].size(); ++ n)
            if(!visited[graph[act][n]])
            {
                visited[graph[act][n]] = true;
                dist[graph[act][n]] = dist[act] + 1;
                father[graph[act][n]] = act;
                que.push(graph[act][n]);
            }
    }

    return -1;
}
