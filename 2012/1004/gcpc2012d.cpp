/* 2012
 * Maciej Szeptuch
 * II UWr
 */
#include<cstdio>
#include<queue>
#include<vector>

using namespace std;

int tests,
    firstAssembly, firstTransfer, firstOperations,
    secondAssembly, secondTransfer, secondOperations,
    in, out, op,
    first[256][256],
    second[256][256];
bool same[256][256],
     visited[256];
vector<int> gfirst[256],
            rfirst[256],
            gsecond[256],
            rsecond[256];

inline static void cleanNodes(void);
inline static const bool checkSimilarity(const int &f = 0, const int &s = 0);
inline static void bfsVisit(const vector<int> graph[256], const int &start);

int main(void)
{
    scanf("%d", &tests);
    for(int t = 0; t < tests; ++ t)
    {
        scanf("%d %d %d %d %d %d", &firstAssembly, &firstTransfer, &firstOperations,
                                   &secondAssembly, &secondTransfer, &secondOperations);
        for(int s = 0; s < firstTransfer || s < secondTransfer; ++ s)
        {
            gfirst[s].clear();
            rfirst[s].clear();
            gsecond[s].clear();
            rsecond[s].clear();
            for(int o = 0; o < firstOperations || o < secondOperations; ++ o)
                first[s][o] = second[s][o] = -1;
        }

        for(int f = 0; f < firstTransfer; ++ f)
            for(int s = 0; s < secondTransfer; ++ s)
                same[f][s] = false;

        for(int a = 0; a < firstAssembly; ++ a)
        {
            scanf("%d %d %d", &in, &out, &op);
            first[in][op] = out;
            gfirst[in].push_back(out);
            rfirst[out].push_back(in);
        }

        for(int a = 0; a < secondAssembly; ++ a)
        {
            scanf("%d %d %d", &in, &out, &op);
            second[in][op] = out;
            gsecond[in].push_back(out);
            rsecond[out].push_back(in);
        }

        cleanNodes();
        same[0][0] = true;
        printf("%seligible\n", checkSimilarity() ? "" : "not ");
    }
    return 0;
}

inline static void cleanNodes(void)
{
    for(int s = 0; s < firstTransfer; ++ s)
        visited[s] = false;

    bfsVisit(gfirst, 0);
    for(int s = 0; s < firstTransfer; ++ s)
        for(int o = 0; o < firstOperations; ++ o)
            if(first[s][o] != -1 && !visited[first[s][o]])
                first[s][o] = -1;

    for(int s = 0; s < firstTransfer; ++ s)
        visited[s] = false;

    bfsVisit(rfirst, firstTransfer - 1);
    for(int s = 0; s < firstTransfer; ++ s)
        for(int o = 0; o < firstOperations; ++ o)
            if(first[s][o] != -1 && !visited[first[s][o]])
                first[s][o] = -1;

    for(int s = 0; s < secondTransfer; ++ s)
        visited[s] = false;

    bfsVisit(gsecond, 0);
    for(int s = 0; s < secondTransfer; ++ s)
        for(int o = 0; o < secondOperations; ++ o)
            if(second[s][o] != -1 && !visited[second[s][o]])
                second[s][o] = -1;

    for(int s = 0; s < secondTransfer; ++ s)
        visited[s] = false;

    bfsVisit(rsecond, secondTransfer - 1);
    for(int s = 0; s < secondTransfer; ++ s)
        for(int o = 0; o < secondOperations; ++ o)
            if(second[s][o] != -1 && !visited[second[s][o]])
                second[s][o] = -1;
}

inline static const bool checkSimilarity(const int &f, const int &s)
{
    if(f + 1 == firstTransfer && s + 1 == secondTransfer)
        return true;

    if(f + 1 == firstTransfer || s + 1 == secondTransfer)
        return false;

    for(int o = 0; o < firstOperations || o < secondOperations; ++ o)
        if((first[f][o] != -1) ^ (second[s][o] != -1))
            return false;

    for(int o = 0; o < firstOperations || o < secondOperations; ++ o)
        if(first[f][o] != -1 && !same[first[f][o]][second[s][o]])
        {
            same[first[f][o]][second[s][o]] = true;
            if(!checkSimilarity(first[f][o], second[s][o]))
                return false;
        }

    return true;
}

inline static void bfsVisit(const vector<int> graph[256], const int &start)
{
    queue<int> que;
    int act;
    que.push(start);
    visited[start] = true;
    while(!que.empty())
    {
        act = que.front();
        que.pop();

        for(unsigned int s = 0; s < graph[act].size(); ++ s)
            if(!visited[graph[act][s]])
            {
                visited[graph[act][s]] = true;
                que.push(graph[act][s]);
            }
    }

    return;
}
