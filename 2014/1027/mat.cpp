/* 2015
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>
#include <algorithm>
#include <cstring>

int result = 1048576,
    last[32];
char word[1048576];

int get_max(int not_letter);

int main(void)
{
    for(int l = 0; l < 32; ++ l)
        last[l] = -1048576;

    scanf("%s", word);
    result = strlen(word);
    if(word[0] != '*')
        last[word[0] - 'A'] = 0;

    for(int w = 1; word[w]; ++ w)
    {
        if(word[w] == '*')
            continue;

        result = std::min(result, w - get_max(word[w] - 'A'));
        last[word[w] - 'A'] = w;
    }

    printf("%lu\n", strlen(word) - result + 1);
    return 0;
}

inline
int get_max(int not_letter)
{
    int res = -1048576;
    for(int l = 0; l < 32; ++ l)
        if(l != not_letter)
            res = std::max(last[l], res);

    return res;
}
