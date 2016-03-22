/* 2013
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>
#include <vector>

int tests,
    verts, edges,
    from, to,
    result,
    ids, id[131072],
    low[131072],
    color[131072],
    visited[131072];
bool answer[131072];
std::vector<std::pair<int, int> > graph[131072];
std::vector<int> edge_stack;

inline int MIN(int a, int b) { return a<b?a:b; }
void dfs(int v, int f = -1, int time = 1);
void solve(void);
bool oddCycle(int v, int i, int c = 1);

int main(void)
{
    scanf("%d", &tests);
    for(int t = 0; t < tests; ++ t)
    {
        scanf("%d %d", &verts, &edges);
        for(int e = 0; e < edges; ++ e)
        {
            scanf("%d %d", &from, &to); -- from, -- to;
            graph[from].push_back(std::make_pair(to, e));
            graph[to].push_back(std::make_pair(from, e));
        }

        solve();
        result = 0;
        ids = 0;
        for(int v = 0; v < verts; ++ v)
        {
            low[v] = visited[v] = 0;
            result += answer[v];
            color[v] = 0;
            answer[v] = false;
            graph[v].clear();
        }

        edge_stack.clear();
        for(int e = 0; e < edges; ++ e)
            id[e] = 0;

        printf("%d\n", result);
    }

    return 0;
}

void solve(void)
{
    int start[131072] = {};
    bool odd[131072] = {};
    for(int v = 0; v < verts; ++ v)
        if(!visited[v])
            dfs(v);

    for(int v = 0; v < verts; ++ v)
        for(unsigned int n = 0; n < graph[v].size(); ++ n)
            start[id[graph[v][n].second]] = v;

    for(int i = 1; i <= ids; ++ i)
        odd[i] = oddCycle(start[i], i, 2 * i);

    for(int v = 0; v < verts; ++ v)
        for(unsigned int n = 0; n < graph[v].size() && !answer[v]; ++ n)
            answer[v] = odd[id[graph[v][n].second]];
}

bool oddCycle(int v, int i, int c)
{
    color[v] = c;
    for(unsigned int n = 0; n < graph[v].size(); ++ n)
        if(id[graph[v][n].second] == i)
        {
            if(color[graph[v][n].first] != c && color[graph[v][n].first] != (c ^ 1) && oddCycle(graph[v][n].first, i, c ^ 1))
                return true;

            if(color[graph[v][n].first] == c)
                return true;
        }

    return false;
}

void dfs(int v, int f, int time)
{
    low[v] = visited[v] = time;
    for(unsigned int n = 0; n < graph[v].size(); ++ n)
    {
        if(!visited[graph[v][n].first])
        {
            edge_stack.push_back(graph[v][n].second);
            dfs(graph[v][n].first, v, time + 1);
            low[v] = MIN(low[v], low[graph[v][n].first]);
            if(low[graph[v][n].first] >= visited[v])
            {
                int act = -1;
                do
                {
                    act = edge_stack.back();
                    id[act] = ids + 1;
                    edge_stack.pop_back();
                }
                while(act != graph[v][n].second);
                ++ ids;
            }
        }

        else if(visited[v] > visited[graph[v][n].first] && graph[v][n].first != f)
        {
            edge_stack.push_back(graph[v][n].second);
            low[v] = MIN(low[v], visited[graph[v][n].first]);
        }
    }

    return;
}
