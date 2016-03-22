/* 2013
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>

int tests,
    state[8],
    people,
    a, b, c, d, e, f,
    nominal[8] = {1, 5, 10, 20, 50, 100};

inline int min(const int &x, const int &y){return x<y?x:y;}
bool solve(const int &money, const int &n = 5);

int main(void)
{
    scanf("%d", &tests);
    for(int t = 0; t < tests; ++ t)
    {
        state[0] = state[2] = state[3] = state[4] = state[5] = 0;
        state[1] = 10;
        scanf("%d", &people);
        for(int p = 0; p < people; ++ p)
        {
            scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);
            if(a < 5 && !b && !c && !d && !e && !f)
            {
                puts("Za malo pieniedzy");
                continue;
            }

            state[0] += a; state[1] += b; state[2] += c; state[3] += d; state[4] += e; state[5] += f;
            if(!solve(nominal[0] * a + nominal[1] * b + nominal[2] * c + nominal[3] * d + nominal[4] * e + nominal[5] * f - 5))
            {
                state[0] -= a; state[1] -= b; state[2] -= c; state[3] -= d; state[4] -= e; state[5] -= f;
                puts("Nie da sie wydac");
            }

            else
                puts("");

        }

        printf("%d %d %d %d %d %d\n", state[0], state[1], state[2], state[3], state[4], state[5]);
    }

    return 0;
}

bool solve(const int &money, const int &n)
{
   // printf(">>%d %d\n", money, n);

    if(n < 0)
        return !money;

    if(!money)
    {
        solve(money, n - 1);
        printf("0 ");
        return true;
    }

    int p = min(money / nominal[n], state[n]);
    if(solve(money - p * nominal[n], n - 1))
    {
        state[n] -= p;
        printf("%d ", p);
        return true;
    }

    -- p;
    if(p >= 0 && solve(money - p * nominal[n], n - 1))
    {
        state[n] -= p;
        printf("%d ", p);
        return true;
    }

    return false;
}
