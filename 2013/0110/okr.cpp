/* 2013
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>
#include <cstring>

int tests;
char inside[16],
     outside[16];

void solve();
long long int NWD(long long int a, long long int b);

int main(void)
{
    scanf("%d", &tests);
    for(int t = 0; t < tests; ++ t)
    {
        scanf(" 0.");
        if(!scanf("%[^(](%[^)])", outside, inside))
        {
            outside[0] = 0;
            scanf("(%[^)])", inside);
        }

        solve();
    }

    return 0;
}

void solve()
{
    long long int top = 0,
                  bottom = 0,
                  div = 0;
    char buffer[32]; sprintf(buffer, "%s%s", outside, inside);
    sscanf(buffer, "%lld", &top); // via wiki
    sscanf(outside, "%lld", &bottom); top -= bottom; bottom = 0;
    for(int i = 0; inside[i]; ++ i)
        bottom = bottom * 10 + 9;

    for(int o = 0; outside[o]; ++ o)
        bottom *= 10;

    div = NWD(top, bottom);
    printf("%lld/%lld\n", top / div, bottom / div);
    return;
}

long long int NWD(long long int a, long long int b)
{
    if(!b)
        return a;

    if(a < b)
        return NWD(b, a);

    return NWD(b, a % b);
}
