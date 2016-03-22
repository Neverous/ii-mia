/* 2012
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>
#include <vector>

using namespace std;

int tests;
long long int kids,
              capacity;
pair<long long int, pair<long long int, long long int> > res;

inline static pair<long long int, pair<long long int, long long int> > nwd(const long long int &a, const long long int &b);

int main(void)
{
    scanf("%d", &tests);
    for(int t = 0; t < tests; ++ t)
    {
        scanf("%lld %lld", &kids, &capacity);
        if(capacity == 1)
        {
            printf("%d\n", kids + 1);
            continue;
        }

        res = nwd(kids, capacity);
        if(res.first != 1)
            puts("IMPOSSIBLE");

        else
        {
            res.second.first = (res.second.first * (capacity  - 1)) % capacity;
            res.second.first = (res.second.first * kids + 1) / capacity;
            printf("%lld\n", res.second.first);
        }
    }

    return 0;
}

inline static pair<long long int, pair<long long int, long long int> > nwd(const long long int &a, const long long int &b)
{
    pair<long long int, pair<long long int, long long int> > temp = make_pair(b, make_pair(0, 1));
    if(a % b == 0)
        return temp;

    temp = nwd(b, a % b);
    temp = make_pair(temp.first, make_pair(temp.second.second, temp.second.first - temp.second.second * (a / b)));
    temp.second.first = (capacity + temp.second.first) % capacity;
    temp.second.second = (capacity + temp.second.second) % capacity;
    return temp;
}
