/* 2014
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>
#include <vector>
#include <algorithm>

const int MOD = 1000000007;

int lines,
    a, b,
    result[524288],
    res;
std::vector<std::pair<int, int> > line;

int main(void)
{
    scanf("%d", &lines);
    for(int l = 0; l < lines; ++ l)
    {
        scanf("%d %d %*d", &a, &b);
        if(a == 0 || b == 0)
        {
            a = std::abs(a);
            b = std::abs(b);
        }

        else if(a < 0 && b < 0) // -y = -x == y = x
        {
            a = std::abs(a);
            b = std::abs(b);
        }

        else if((a < 0 && b > 0) || (a > 0 && b < 0)) // -y = x == y = -x
        {
            a = -std::abs(a);
            b = std::abs(b);
        }

        int gcd = std::__gcd(std::abs(a), std::abs(b));
        a /= gcd;
        b /= gcd;

        line.push_back(std::make_pair(a, b));
    }

    std::sort(line.begin(), line.end());
    for(int l = line.size() - 1; l >= 0; -- l)
    {
        int count = 1;
        while(l - count >= 0 && line[l] == line[l - count])
            ++ count;

        result[l] = ((long long int) (line.size() - l - 1) * count + (long long int) result[l + 1]) % MOD;
        while(count > 1 && l > 0)
        {
            result[l - 1] = result[l];
            -- count;
            -- l;
        }
    }
/*
    for(unsigned int l = 0; l < line.size(); ++ l)
        printf("%d/%d == %d\n", line[l].first, line[l].second, result[l]);
*/
    for(unsigned int n = 0; n < line.size(); ++ n)
    {
        int count = 1;
        while(n + 1 < line.size() && line[n] == line[n + 1])
        {
            ++ n;
            ++ count;
        }

        res = ((long long int) res + (long long int) count * result[n + 1]) % MOD;
    }

    printf("%d\n", res);
    return 0;
}
