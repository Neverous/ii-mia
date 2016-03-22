/* 2013
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>
#include <vector>
#include <algorithm>

#define VERTS 2000
#define EDGES 1000000
#define COSTS 100001

int edges,
    cost,
    max,
    tmp,
    result,
    best,
    longest[VERTS][VERTS];
short int repr[VERTS],
          count,
          verts,
          start, end;

std::vector<int> sort[COSTS],
                 tree[VERTS];

inline void findLongest(const short int &s, const short int &v, const short int &f = -1);
inline short int &unionFind(const short int &a);
inline bool unionUnion(const short int &a, const short int &b);

inline int makeEdge(const int &first, const int &second) { return (second << 11) + first; }
inline int makeCostEdge(const int &first, const int &second) { return (second << 17) + first; }
inline short int edgeFirst(const int &rep) { return rep & ((1 << 11) - 1); }
inline short int edgeSecond(const int &rep) { return rep >> 11; }
inline int costEdgeFirst(const int &rep) { return rep & ((1 << 17) - 1); }
inline short int costEdgeSecond(const int &rep) { return rep >> 17; }

int main(void)
{
    while(scanf("%hd %d", &verts, &edges) != -1)
    {
        for(short int v = 0; v < verts; ++ v)
        {
            tree[v].clear();
            repr[v] = v;
            for(short int v2 = 0; v2 < verts; ++ v2)
                longest[v][v2] = -1;
        }

        for(int c = 0; c <= max; ++ c)
            sort[c].clear();

        max = 0;
        for(int e = 0; e < edges; ++ e)
        {
            scanf("%hd %hd %d", &start, &end, &cost);
            sort[cost].push_back(makeEdge(start - 1, end - 1));
            max = std::max(max, cost);
        }

        result = 0;
        best = 0;
        count = 0;
        for(int c = 0; c <= max && count < verts - 1; ++ c)
            for(unsigned int e = 0; e < sort[c].size(); ++ e)
            {
                int &act = sort[c][e];
                if(unionUnion(edgeFirst(act), edgeSecond(act)))
                {
                    tree[edgeFirst(act)].push_back(makeCostEdge(c, edgeSecond(act)));
                    tree[edgeSecond(act)].push_back(makeCostEdge(c, edgeFirst(act)));
                    ++ count;
                    result += c;
                }
            }

        if(count != verts - 1)
        {
            puts("disconnected");
            continue;
        }

        for(int v = 0; v < verts; ++ v)
            findLongest(v, v);

        for(int c = 0; c <= max; ++ c)
            for(unsigned int e = 0; e < sort[c].size(); ++ e)
            {
                int &act = sort[c][e];
                tmp = c + longest[edgeFirst(act)][edgeSecond(act)];
                if(tmp > best)
                    best = tmp;
            }

        printf("%d\n", result - best);
    }

    return 0;
}

inline short int &unionFind(const short int &a)
{
    if(repr[a] != a)
        repr[a] = unionFind(repr[a]);

    return repr[a];
}

inline bool unionUnion(const short int &a, const short int &b)
{
    short int &fa = unionFind(a),
              &fb = unionFind(b);

    if(fa == fb)
        return false;

    if(fa < fb)
        repr[fb] = fa;

    else
        repr[fa] = fb;

    return true;
}

inline void findLongest(const short int &s, const short int &v, const short int &f)
{
    short int g = 0;
    for(unsigned int n = 0; n < tree[v].size(); ++ n)
    {
        g = costEdgeSecond(tree[v][n]);
        if(g == f)
            continue;

        longest[s][g] = std::max(longest[s][v], costEdgeFirst(tree[v][n]));
        findLongest(s, g, v);
    }

    return;
}
