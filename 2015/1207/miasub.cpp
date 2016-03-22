/* 2015
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>
#include <queue>
#include <vector>

int stations;
int from;
int to;
int distance[131072];
bool visited[131072];
std::vector<int> graph[131072];
std::queue<int> que;

int markCycle(int v, int f = 0);
void countDistances(void);

int main(void)
{
    scanf("%d", &stations);
    for(int t = 0; t < stations; ++ t)
    {
        scanf("%d %d", &from, &to);
        graph[from].push_back(to);
        graph[to].push_back(from);
        distance[t] = 131072;
    }

    markCycle(1);
    countDistances();
    for(int s = 0; s < stations; ++ s)
        printf("%d ", distance[s]);

    puts("");
    return 0;
}

inline
int markCycle(int v, int f)
{
    visited[v] = true;
    for(unsigned int i = 0; i < graph[v].size(); ++ i)
    {
        int n = graph[v][i];
        if(n == f) continue;
        if(visited[n])
        {
            distance[v - 1] = 0;
            que.push(v);
            return n;
        }

        int g = markCycle(n, v);
        if(g == -1)
            return -1;

        if(g > 0)
        {
            distance[v - 1] = 0;
            que.push(v);
            if(g == v)
                return -1;

            return g;
        }
    }

    return 0;
}

inline
void countDistances(void)
{
    while(!que.empty())
    {
        int act = que.front();
        que.pop();

        for(unsigned int i = 0; i < graph[act].size(); ++ i)
        {
            int n = graph[act][i];
            if(distance[n - 1] > distance[act - 1] + 1)
            {
                distance[n - 1] = distance[act - 1] + 1;
                que.push(n);
            }
        }
    }
}
