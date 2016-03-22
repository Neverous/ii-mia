/* 2016
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>
#include <vector>

const int MAX_HITS      = 1024;
const int MAX_MONSTERS  = 128;
int diana;
int life[MAX_MONSTERS];
int monsters;
int reward[MAX_MONSTERS];
int tests;
int tower;

int solve(void);

int main(void)
{
    scanf("%d", &tests);
    for(int t = 0; t < tests; ++ t)
    {
        scanf("%d %d %d", &diana, &tower, &monsters);
        for(int m = 0; m < monsters; ++ m)
            scanf("%d %d", &life[m], &reward[m]);

        printf("Case #%d: %d\n", t + 1, solve());
    }

    return 0;
}

int solve(void)
{
    int best[2][MAX_HITS] = {};
    std::vector<int> que[2];
    que[0].push_back(1);
    for(int m = 0; m < monsters; ++ m)
    {
        std::vector<int> &curq  = que[m % 2];
        std::vector<int> &nextq = que[(m + 1) % 2];
        int *curb   = best[m % 2];
        int *nextb  = best[(m + 1) % 2];
        nextq.clear();
        for(int h = 0; h < MAX_HITS; ++ h)
            nextb[h] = -1;

        for(unsigned int q = 0; q < curq.size(); ++ q)
        {
            int act = curq[q];
            int tower_hits_pre_kill = (life[m] - 1) / tower;
            int diana_hits_to_kill = (life[m] - tower_hits_pre_kill * tower + diana - 1) / diana;

            //printf("DEBUG: hits_left: %d tower_hits_pre_kill: %d diana_hits_to_kill: %d\n", act, tower_hits_pre_kill, diana_hits_to_kill);
            // skip
            int hits_if_skip = act + tower_hits_pre_kill + 1;
            if(nextb[hits_if_skip] < curb[act])
            {
                if(nextb[hits_if_skip] == -1)
                    nextq.push_back(hits_if_skip);

                nextb[hits_if_skip] = curb[act];
            }

            // kill
            int hits_if_kill = act + tower_hits_pre_kill - diana_hits_to_kill;
            if(hits_if_kill >= 0 && nextb[hits_if_kill] < curb[act] + reward[m])
            {
                if(nextb[hits_if_kill] == -1)
                    nextq.push_back(hits_if_kill);

                nextb[hits_if_kill] = curb[act] + reward[m];
            }

            //printf("DEBUG: hits_if_skip: %d hits_if_kill: %d curb: %d reward: %d\n\n", hits_if_skip, hits_if_kill, curb[act], reward[m]);
        }
    }

    int result = 0;
    for(unsigned int q = 0; q < que[monsters % 2].size(); ++ q)
        result = std::max(result, best[monsters % 2][que[monsters % 2][q]]);

    return result;
}
