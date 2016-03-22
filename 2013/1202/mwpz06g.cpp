/* 2013
 * Maciej Szeptuch
 * IIUWr
 */
#include <cstdio>
#include <vector>
#include <cassert>

int tests,
    verts, edges,
    from, to,
    places[1024],
    color[1024],
    start[1024],
    max;

std::vector<int> graph[1024];

void dfs(int v, int c = 1);

int main(void)
{
    scanf("%d", &tests);
    for(int t = 0; t < tests; ++ t)
    {
        scanf("%d %d", &verts, &edges);
        max = 0;
        for(int v = 0; v < verts; ++ v)
        {
            scanf("%d", &places[v]);
            graph[v].clear();
            color[v] = 0;
            start[v] = 1;
        }

        for(int e = 0; e < edges; ++ e)
        {
            scanf("%d %d %*d", &from, &to); -- from, -- to;
            graph[from].push_back(to);
            graph[to].push_back(from);
        }

        for(int v = 0; v < verts; ++ v)
            if(!color[v]) dfs(v);

        for(int v = 0; v < verts; ++ v)
        {
            if(color[v] == 2) for(unsigned int e = 0; e < graph[v].size(); ++ e)
                if(start[v] < start[graph[v][e]] + places[graph[v][e]])
                    start[v] = start[graph[v][e]] + places[graph[v][e]];

            if(max < start[v] + places[v])
                max = start[v] + places[v] - 1;
        }

        printf("%d\n", max);
        for(int v = 0; v < verts; ++ v)
        {
            for(int p = 0; p < places[v]; ++ p)
                printf("%d ", p + start[v]);

            puts("");
        }
    }

    return 0;
}

inline
void dfs(int v, int c)
{
    color[v] = c;
    for(unsigned int n = 0; n < graph[v].size(); ++ n)
        if(!color[graph[v][n]]) dfs(graph[v][n], c ^ 3);
}
