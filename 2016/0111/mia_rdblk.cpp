/* 2016
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>
#include <queue>
#include <vector>

const int MAX_EDGES = 32768;
const int MAX_VERTS = 256;
int cost[MAX_EDGES];
int edges;
int verts;
std::vector<std::pair<int, int> > graph[MAX_VERTS];

int find_shortest_path(int from, int to, std::vector<int> *path=0);

int main(void)
{
    scanf("%d %d", &verts, &edges);
    for(int e = 0; e < edges; ++ e)
    {
        int from;
        int to;
        scanf("%d %d %d", &from, &to, &cost[e]);
        -- from; -- to;
        graph[from].push_back(std::make_pair(to, e));
        graph[to].push_back(std::make_pair(from, e));
    }

    std::vector<int> shortest;
    int shortest_length = find_shortest_path(0, verts - 1, &shortest);

    int result = 0;
    for(unsigned int s = 0; s < shortest.size(); ++ s)
    {
        //printf("DEBUG: doubling %d\n", shortest[s]);
        cost[shortest[s]] *= 2;
        int current_length = find_shortest_path(0, verts - 1);
        result = std::max(result, current_length - shortest_length);
        cost[shortest[s]] /= 2;
    }

    printf("%d\n", result);
    return 0;
}

int find_shortest_path(int from, int to, std::vector<int> *path)
{
    int visited[verts];
    int through[verts];
    int prev[verts];
    for(int v = 0; v < verts; ++ v)
        visited[v] = (1 << 30);

    visited[from] = 0;
    std::priority_queue<std::pair<int, int> > que;
    que.push(std::make_pair(0, from));

    while(!que.empty())
    {
        std::pair<int, int> act = que.top();
        que.pop();

        if(-act.first > visited[act.second])
            continue;

        if(act.second == to)
            break;

        for(unsigned int n = 0; n < graph[act.second].size(); ++ n)
        {
            std::pair<int, int> &neighbour = graph[act.second][n];
            if(visited[neighbour.first] <= -act.first + cost[neighbour.second])
                continue;

            through[neighbour.first] = neighbour.second;
            prev[neighbour.first] = act.second;
            visited[neighbour.first] = -act.first + cost[neighbour.second];
            que.push(std::make_pair(-visited[neighbour.first], neighbour.first));
        }
    }

    if(path)
    {
        int cur = to;
        while(cur != from)
        {
            path->push_back(through[cur]);
            cur = prev[cur];
        }
    }

    return visited[to];
}
