/* 2012
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>
#include <vector>

int tests,
    safes, keys, safe,
    weight[16384], res;
std::vector<int> digraph[16384];
std::vector<int> graph[16384];

void dimark(const int &v);
void mark(const int &v);

int main(void)
{
    scanf("%d", &tests);
    for(int t = 0; t < tests; ++ t)
    {
        scanf("%d", &safes);
        res = 0;
        for(int s = 0; s < safes; ++ s)
        {
            graph[s].clear();
            digraph[s].clear();
            weight[s] = 0;
        }

        for(int s = 0; s < safes; ++ s)
        {
            scanf("%d", &keys);
            for(int k = 0; k < keys; ++ k)
            {
                scanf("%d", &safe);
                -- safe;
                ++ weight[safe];
                digraph[s].push_back(safe);
                graph[s].push_back(safe);
                graph[safe].push_back(s);
            }
        }

        for(int s = 0; s < safes; ++ s)
            if(!weight[s])
            {
                ++ res;
                dimark(s);
            }

        for(int s = 0; s < safes; ++ s)
            if(weight[s] != -1)
            {
                ++ res;
                mark(s);
            }


        printf("%d\n", res);
    }

    return 0;
}

inline
void dimark(const int &v)
{
    weight[v] = -1;
    for(unsigned int n = 0; n < digraph[v].size(); ++ n)
        if(weight[digraph[v][n]] != -1)
            dimark(digraph[v][n]);

    return;
}

inline
void mark(const int &v)
{
    weight[v] = -1;
    for(unsigned int n = 0; n < graph[v].size(); ++ n)
        if(weight[graph[v][n]] != -1)
            mark(graph[v][n]);

    return;
}
