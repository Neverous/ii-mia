/* 2013
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

int tests,
    start, end,
    verts,
    deg[64],
    act;
queue<int> leafs[2];
vector<int> graph[64];

inline long long int solve(void);
inline bool check(const int &root);
inline int countLevels(const int &v, const int &l = 0, const int &f = -1);
inline long long int count(const int &v, const int &f = -1);
inline long long int checkLeafs(const int &v, const int &l, const int &f = -1);

int main(void)
{
    scanf("%d", &verts);
    for(int e = 1; e < verts; ++ e)
    {
        scanf("%d %d", &start, &end);
        -- start; -- end;
        graph[start].push_back(end);
        graph[end].push_back(start);
        ++ deg[start]; ++ deg[end];
    }

    printf("%lld\n", solve());
    return 0;
}

inline long long int solve(void)
{
    long long int result = 0;
    for(int v = 0; v < verts; ++ v)
    {
        if(deg[v] > 3) // TOO MANY CHILDREN
            return 0;

        if(deg[v] == 1) // LEAF
            leafs[0].push(v);
    }

    for(int l = 0, v = verts; v > 2 && !leafs[l].empty(); l ^= 1)
    {
        while(!leafs[l].empty())
        {
            act = leafs[l].front(); leafs[l].pop();
            for(int n = 0; n < graph[act].size(); ++ n)
            {
                -- deg[graph[act][n]];
                if(deg[graph[act][n]] == 1)
                    leafs[l ^ 1].push(graph[act][n]);
            }

            -- v;
        }
    }

    for(int l = 0; l < 2; ++ l) while(!leafs[l].empty())
    {
        act = leafs[l].front(); leafs[l].pop();
        if(!check(act))
            continue;

        result += count(act);
    }

    return result;
}

inline bool check(const int &root)
{
    for(int v = 0; v < verts; ++ v)
        deg[v] = 0;

    int d = countLevels(root);
    for(int v = 0; v < d; ++ v)
        if(deg[v] != (1 << v))
            return false;

    return checkLeafs(root, d) != -1;
}

inline long long int count(const int &v, const int &f)
{
    long long int res = 1;
    int tmp = 0;
    deg[v] = 1;
    for(int n = 0; n < graph[v].size(); ++ n)
        if(graph[v][n] != f)
        {
            ++ tmp;
            res *= count(graph[v][n], v);
            deg[v] += deg[graph[v][n]];
        }

    if(tmp > 2)
        return 0;

    if(tmp == 2)
    {
        tmp = 0;
        for(int n = 0; n < graph[v].size(); ++ n)
            if(graph[v][n] != f)
                tmp += (tmp > 0 ? -1 : 1) * deg[graph[v][n]];

        if(!tmp)
            res *= 2;
    }

    return res;
}

inline int countLevels(const int &v, const int &l, const int &f)
{
    int max = l;
    ++ deg[l];
    for(int n = 0; n < graph[v].size(); ++ n)
        if(graph[v][n] != f)
            max = std::max(max, countLevels(graph[v][n], l + 1, v));

    return max;
}

inline long long int checkLeafs(const int &v, const int &l, const int &f)
{
    int tmp[2] = {},
        t = 0;
    for(int n = 0; n < graph[v].size(); ++ n)
        if(graph[v][n] != f)
        {
            tmp[t] = checkLeafs(graph[v][n], l - 1, v);
            if(tmp[t ++] == -1)
                return -1;
        }

    if(tmp[0] != 0 && tmp[1] != 0 && tmp[0] != (1 << (l - 1)) && tmp[1] != (1 << (l - 1)))
        return -1;

    return tmp[0] + tmp[1] + !l;
}
