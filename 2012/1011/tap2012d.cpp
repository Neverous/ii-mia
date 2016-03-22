/* 2012
 * Maciej Szeptuch
 * II UWr
 */
#include<cstdio>
#include<vector>

using namespace std;

int names,
    res,
    tmp;
char buffer[101],
     name[10001][101];
bool used1[10001],
     used2[10001];
vector<pair<short, short> > len[101];
vector<short> start[256];

inline static const int maxPrefix(const char *a, const char *b);

int main(void)
{
    while(scanf("%d", &names) != -1 && names != -1)
    {
        res = 0;
        for(int n = 0; n < 10001; ++ n)
            used1[n] = used2[n] = false;

        for(int l = 0; l < 101; ++ l)
            len[l].clear();
        
        for(int n = 0; n < 256; ++ n)
            start[n].clear();

        for(int n = 0; n < names; ++ n)
        {
            scanf("%s", name[n]);
            start[name[n][0]].push_back(n);
        }

        for(int n = 0; n < names; ++ n)
        {
            scanf("%s", buffer);
            for(int q = 0, p = 0; q < start[buffer[0]].size(); ++ q)
            {
                p = start[buffer[0]][q];
                tmp = maxPrefix(name[p], buffer);
                if(tmp)
                    len[tmp].push_back(make_pair(n, p));
            }
        }

        for(int l = 100; l > 0; -- l)
            for(int c = 0; c < len[l].size(); ++ c)
                if(!used1[len[l][c].first] && !used2[len[l][c].second])
                {
                    used1[len[l][c].first] = used2[len[l][c].second] = true;
                    res += l;
                }

        printf("%d\n", res);
    }

    return 0;
}

inline static const int maxPrefix(const char *a, const char *b)
{
    int r = 0;
    while(a[r] && b[r] && a[r] == b[r])
        ++ r;

    return r;
}
