/* 2013
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>

char encrypted[131072],
     password[131072];
int count[256];

bool solve(void);
bool check(void);

int main(void)
{
    scanf("%s %s", encrypted, password);
    puts(solve() ? "YES" : "NO");
    return 0;
}

bool solve(void)
{
    int l = 0,
        p = 0;

    while(password[l])
        ++ count[password[l ++]];
    
    while(p < l)
        -- count[encrypted[p ++]];

    if(check())
        return true;

    while(encrypted[p])
    {
        ++ count[encrypted[p - l]];
        -- count[encrypted[p ++]];
        if(check())
            return true;
    }

    return false;
}

bool check(void)
{
    for(int c = 0; c < 256; ++ c)
        if(count[c])
            return false;

    return true;
}
