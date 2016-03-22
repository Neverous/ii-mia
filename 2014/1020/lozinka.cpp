/* 2014
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>
#include <cstring>

int passwords,
    passlen;
char password[128][16];

int main(void)
{
    scanf("%d", &passwords);
    for(int p = 0; p < passwords; ++ p)
    {
        scanf("%s", password[p]);
        passlen = strlen(password[p]);
        for(int s = 0; s <= p; ++ s)
        {
            int c = 0;
            while(password[s][c] && password[s][c] == password[p][passlen - 1 - c])
                ++ c;

            if(c == passlen && !password[s][c])
            {
                printf("%d %c\n", passlen, password[p][c / 2]);
                return 0;
            }
        }
    }

    return 0;
}
