/* 2015
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>
#include <vector>
#include <queue>

int verts;
int edges;
int start;
int end;
int cost;

std::vector<std::pair<int, int> > graph[16384];

int solve(void);

int main(void)
{
    scanf("%d %d", &verts, &edges);
    for(int e = 0; e < edges; ++ e)
    {
        scanf("%d %d %d", &start, &end, &cost);
        graph[start].push_back(std::make_pair(end, cost * 2));
        graph[end].push_back(std::make_pair(start, cost * 2));
    }

    printf("%d\n", solve());
    return 0;
}

int solve(void)
{
    int length[16384];
    for(int v = 0; v < verts; ++ v)
        length[v] = 1 << 30;

    std::priority_queue<std::pair<int, int> > que;

    length[0] = 0;
    que.push(std::make_pair(0, 0));
    while(!que.empty())
    {
        std::pair<int, int> act = que.top(); que.pop();
        if(act.first != -length[act.second]) continue;
        if(act.second == verts - 1) break;

        for(unsigned int n = 0; n < graph[act.second].size(); ++ n)
        {
            std::pair<int, int> &neighbor = graph[act.second][n];
            if(-act.first + neighbor.second >= length[neighbor.first]) continue;
            length[neighbor.first] = -act.first + neighbor.second;
            que.push(std::make_pair(-length[neighbor.first], neighbor.first));
        }
    }

    int result[16384] = {};
    que = std::priority_queue<std::pair<int, int> >();
    que.push(std::make_pair(length[verts - 1], verts - 1));
    while(!que.empty())
    {
        std::pair<int, int> act = que.top(); que.pop();
        if(act.first != length[act.second]) continue;
        length[act.second] = -1;
        bool sent = false;
        for(unsigned int n = 0; n < graph[act.second].size(); ++ n)
        {
            std::pair<int, int> &neighbor = graph[act.second][n];
            if(act.first - neighbor.second != length[neighbor.first]) continue;
            result[neighbor.first] += neighbor.second;
            if(!sent)
            {
                sent = true;
                result[neighbor.first] += result[act.second];
            }

            que.push(std::make_pair(length[neighbor.first], neighbor.first));
        }
    }

    return result[0];
}
