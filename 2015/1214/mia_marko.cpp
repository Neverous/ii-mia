/* 2015
 * Maciej Szeptuch
 * II UWr
 */
#include <algorithm>
#include <cstdio>
#include <cstring>

const char boundaries[8][2] = {
    {'a', 'c'},
    {'d', 'f'},
    {'g', 'i'},
    {'j', 'l'},
    {'m', 'o'},
    {'p', 's'},
    {'t', 'v'},
    {'w', 'z'},
};

char key[1024];
char word[1024][1024];
int words;

bool matches_key(const char *current)
{
    for(int c = 0; current[c] && key[c]; ++ c)
    {
        const char *bound = boundaries[key[c] - '2'];
        if(bound[0] > current[c] || current[c] > bound[1])
            return false;
    }

    return true;
}

int main(void)
{
    scanf("%d", &words);
    for(int w = 0; w < words; ++ w)
    {
        char _word[1048576];
        scanf("%s", _word);
        memcpy(word[w], _word, 1024);
    }

    scanf("%s", key);
    printf("%ld\n", std::count_if(word, word + words, matches_key));
    return 0;
}
