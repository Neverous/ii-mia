/* 2013
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>
#include <vector>

int numbers,
    seq,
    res;
std::vector<std::pair<int, int> > pos;

inline int max(const int &a, const int &b){return a>b?a:b;}

int main(void)
{
    scanf("%d", &numbers);
    for(int n = 0; n < numbers; ++ n)
    {
        scanf("%d", &seq);
        if(!pos.empty())
        {
            if(pos[0].first != seq)
                res = max(res, n - pos[0].second);

            else if(pos.size() > 1)
                res = max(res, n - pos[1].second);
        }

        if(pos.empty() || pos.back().first != seq)
            pos.push_back(std::make_pair(seq, n));
    }

    printf("%d\n", res);
    return 0;
}
