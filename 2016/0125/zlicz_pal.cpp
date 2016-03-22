/* 2016
 * Maciej Szeptuch
 * II UWr
 */
#include<cstdio>

const int MAX_LENGTH = 1048576;
char word[MAX_LENGTH];
long long unsigned int result;

int main(void)
{
    scanf("%s", word);

    { // Even
        int radius[MAX_LENGTH] = {};
        for(int l = 0, p = 0; word[l]; ++ l, ++ result)
        {
            if(p + radius[p] - 1 >= l)
            {
                if(l + radius[2 * p - l] <= p + radius[p])
                    radius[l] = radius[2 * p - l];

                else
                    radius[l] = p + radius[p] - l;
            }

            while(l - radius[l] - 1 >= 0 && word[l + radius[l]] && word[l - radius[l] - 1] == word[l + radius[l]])
                ++ radius[l];

            result += radius[l];
            if(radius[l] + l > radius[p] + p)
                p = l;
        }
    }

    { // Odd
        int radius[MAX_LENGTH] = {};
        for(int l = 1, p = 0; word[l]; ++ l)
        {
            if(p + radius[p] >= l)
            {
                if(l + radius[2 * p - l] <= p + radius[p])
                    radius[l] = radius[2 * p - l];

                else
                    radius[l] = p + radius[p] - l;
            }

            while(l - radius[l] >= 0 && word[l + radius[l]] && word[l - radius[l]] == word[l + radius[l]])
                ++ radius[l];

            result += radius[l] - 1;
            if(radius[l] + l > radius[p] + p)
                p = l;
        }
    }

    printf("%llu\n", result);
    return 0;
}

