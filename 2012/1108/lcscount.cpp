/* 2013
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>

int MOD,
    lcs[1024][1024],
    cnt[1024][1024],
    f, s;
char first[1024],
     second[1024];

inline int max(const int &a, const int &b){return a>b?a:b;}

int main(void)
{
    scanf("%d %s %s", &MOD, first, second);
    for(f = 0; first[f]; ++ f)
        cnt[f][0] = 1;

    cnt[f][0] = 1;
    for(s = 0; second[s]; ++ s)
        cnt[0][s] = 1;

    cnt[0][s] = 1;
    /* LCS */
    for(f = 1; first[f - 1]; ++ f)
        for(s = 1; second[s - 1]; ++ s)
        {
            lcs[f][s] = max(lcs[f - 1][s], lcs[f][s - 1]);
            if(first[f - 1] == second[s - 1])
                lcs[f][s] = max(lcs[f][s], lcs[f - 1][s - 1] + 1);

            if(lcs[f][s] == lcs[f - 1][s])
                cnt[f][s] += cnt[f - 1][s];

            if(lcs[f][s] == lcs[f][s - 1])
                cnt[f][s] += cnt[f][s - 1];

            if(lcs[f][s] == lcs[f - 1][s - 1] + 1)
            {
                if(first[f - 1] == second[s - 1])
                    cnt[f][s] += cnt[f - 1][s - 1];
            }

            else
            {
                    cnt[f][s] -= cnt[f - 1][s - 1];
            }

            if(cnt[f][s] > MOD)
                cnt[f][s] %= MOD;
        }

    /*
    for(f = 1; first[f - 1]; ++ f)
    {
        for(s = 1; second[s - 1]; ++ s)
            printf("%3d", lcs[f][s]);

        puts("");
    }

    puts("");
    for(f = 1; first[f - 1]; ++ f)
    {
        for(s = 1; second[s - 1]; ++ s)
            printf("%3d", cnt[f][s]);

        puts("");
    }
    */
    printf("%d %d\n", lcs[f - 1][s - 1], cnt[f - 1][s - 1]);

    return 0;
}
