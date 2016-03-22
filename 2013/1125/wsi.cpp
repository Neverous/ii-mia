/* 2013
 * Maciej Szeptuch
 * IIUWr
 */
#include <cstdio>
#include <cstring>

typedef unsigned int uint;

uint verts, edges, cost,
     vert[8],
     graph[32][32],
     res[1U << 8][32];
char name[32][32],
     fromName[32],
     toName[32];

inline uint MIN(uint a, uint b) {return a<b?a:b;}
uint getID(const char *repr);
uint solve(void);

int main(void)
{
    while(scanf("%u %u", &verts, &edges) != -1 && verts)
    {
        for(uint f = 0; f < verts; ++ f)
        {
            for(uint t = 0; t < verts; ++ t)
                graph[f][t] = (1U << 30);

            graph[f][f] = 0;
        }

        for(uint v = 0; v < verts; ++ v)
            scanf("%s", name[v]);

        for(uint e = 0; e < edges; ++ e)
        {
            scanf("%s %s %u", fromName, toName, &cost);
            uint from   = getID(fromName),
                 to     = getID(toName);

            graph[to][from] = graph[from][to] = MIN(graph[from][to], cost);
        }

        for(uint c = 0; c < 4; ++ c)
        {
            scanf("%s %s", fromName, toName);
            uint from   = getID(fromName),
                 to     = getID(toName);

            vert[c * 2]     = from;
            vert[c * 2 + 1] = to;
        }

        printf("%u\n", solve());
    }

    return 0;
}

inline
uint getID(const char *repr)
{
    for(uint v = 0; v < verts; ++ v)
        if(!strcmp(repr, name[v]))
            return v;

    return -1;
}

inline
uint solve(void)
{
    for(uint k = 0; k < verts; ++ k)
        for(uint f = 0; f < verts; ++ f)
            for(uint t = 0; t < verts; ++ t)
                graph[f][t] = MIN(graph[f][t], graph[f][k] + graph[k][t]);

    for(uint m = 0; m < (1U << 8); ++ m)
        for(uint v = 0; v < verts; ++ v)
            res[m][v] = (1U << 30);

    for(uint s = 0; s < 8; ++ s)
        memcpy(res[1U << s], graph[vert[s]], verts * sizeof(uint));

    for(uint m = 1; m < (1U << 8); ++ m)
        if(m & (m - 1)) for(uint f = 0; f < verts; ++ f)
            for(uint n = 1; n < m; ++ n)
                if((m & n) == n) for(uint t = 0; t < verts; ++ t)
                    res[m][f] = MIN(res[m][f], res[n][t] + res[m - n][t] + graph[f][t]);

    uint result = (1U << 30);

    result = MIN(result, res[  3][vert[1]] + res[ 12][vert[3]] + res[ 48][vert[5]] + res[192][vert[7]]);

    result = MIN(result, res[ 15][vert[1]] + res[ 48][vert[5]] + res[192][vert[7]]);
    result = MIN(result, res[ 12][vert[3]] + res[ 51][vert[1]] + res[192][vert[7]]);
    result = MIN(result, res[ 12][vert[3]] + res[ 48][vert[5]] + res[195][vert[1]]);
    result = MIN(result, res[  3][vert[1]] + res[ 60][vert[5]] + res[192][vert[7]]);
    result = MIN(result, res[  3][vert[1]] + res[ 48][vert[5]] + res[204][vert[7]]);
    result = MIN(result, res[  3][vert[1]] + res[ 12][vert[3]] + res[240][vert[7]]);

    result = MIN(result, res[  3][vert[1]] + res[252][vert[7]]);
    result = MIN(result, res[ 12][vert[3]] + res[243][vert[1]]);
    result = MIN(result, res[ 48][vert[5]] + res[207][vert[1]]);
    result = MIN(result, res[192][vert[7]] + res[ 63][vert[1]]);

    result = MIN(result, res[ 15][vert[1]] + res[240][vert[7]]);
    result = MIN(result, res[ 60][vert[5]] + res[195][vert[1]]);
    result = MIN(result, res[ 51][vert[1]] + res[204][vert[7]]);

    result = MIN(result, res[255][vert[1]]);
    return result;
}
