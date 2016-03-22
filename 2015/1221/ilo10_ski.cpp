/* 2016
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>
#include <algorithm>

const int MAX_ROUNDS = 262144;
int end[MAX_ROUNDS];
int rounds;
int sort_me[MAX_ROUNDS];
int start[MAX_ROUNDS];
int tests;
int time_[MAX_ROUNDS];

bool compare_by_required_free(int a, int b);

int main(void)
{
    scanf("%d", &tests);
    for(int t = 0; t < tests; ++ t)
    {
        scanf("%d", &rounds);
        for(int r = 0; r < rounds; ++ r)
        {
            scanf("%d %d %d", &start[r], &end[r], &time_[r]);
            sort_me[r] = r;
        }

        bool result = true;
        std::sort(sort_me, sort_me + rounds, compare_by_required_free);
        for(int s = 0, T = 0; s < rounds; ++ s)
        {
            int r = sort_me[s];
            T = std::max(T, start[r]);
            if (T + time_[r] > end[r])
            {
                result = false;
                break;
            }

            T += time_[r];
        }

        puts(result ? "TAK" : "NIE");
    }

    return 0;
}

inline
bool compare_by_required_free(int a, int b)
{
    if(end[a] - time_[a] < end[b] - time_[b])
        return true;

    if(end[a] - time_[a] > end[b] - time_[b])
        return false;

    return start[a] + time_[a] < start[b] + time_[b];
}
