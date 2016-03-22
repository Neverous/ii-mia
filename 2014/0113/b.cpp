/* 2014
 * Maciej Szeptuch
 * IIUWr
 */
#include <cstdio>
#include <vector>

int tests,
    verts, edges,
    start, end,
    from, to;
std::vector<int> graph[131072];
std::vector<int> possible;
std::vector<int> result;
bool path[131072];

bool findPath(int from, int to);
void putPath(int from, int to, std::vector<int> &out);
int findCut(int s, const std::vector<int> &in);

int main(void)
{
    scanf("%d", &tests);
    for(int t = 0; t < tests; ++ t)
    {
        for(int v = 0; v < verts; ++ v)
        {
            graph[v].clear();
            path[v] = false;
        }

        scanf("%d %d %d %d", &verts, &edges, &start, &end);
        -- start; -- end;
        for(int e = 0; e < edges; ++ e)
        {
            scanf("%d %d", &from, &to);
            -- from; -- to;
            graph[from].push_back(to);
        }

        findPath(start, end);
        if(findPath(start, end))
        {
            printf("2\n%d %d\n", start + 1, end + 1);
            continue;
        }

        possible.clear();
        result.clear();
        putPath(start, end, possible);
        for(unsigned int s = 0; s < possible.size(); ++ s)
        {
            s = findCut(s, possible);
            result.push_back(s);
        }

        printf("%zu\n", result.size());
        for(unsigned int r = 0; r < result.size(); ++ r)
            printf("%d ", result[r] + 1);

        puts("");
    }

    return 0;
}
