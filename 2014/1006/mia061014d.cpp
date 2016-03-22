/* 2014
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cassert>

char word[131072];
int start[131072],
    end[131072],
    radius[131072];
long long int result;

long long int countGray(void);
void rehash(void);
void countUpperBounds(void);
void countRadius(void);
bool compare(int startA, int endA, int startB, int endB);

int main(void)
{
    scanf("%s", word);
    for(int w = 0; word[w]; ++ w)
    {
        char original = word[w];
        for(int n = 'a'; n <= 'z'; ++ n)
        {
            word[w] = n;
            result = std::max(result, countGray());
        }

        word[w] = original;
    }

    printf("%lld\n", result);
    return 0;
}

inline
long long int countGray(void)
{
    memset(start, 0, 131072 * sizeof(int));
    memset(end, 0, 131072 * sizeof(int));
    memset(radius, 0, 131072 * sizeof(int));

    rehash();
    countUpperBounds();
    countRadius();
    long long int count = 0;
    for(int w = 0; word[w]; ++ w)
    {
        radius[w] = radius[w] * 2 + 1;
        while(radius[w] > 0)
        {
            count += (long long int) radius[w] * radius[w];
            radius[w] /= 2;
        }
    }

    return count;
}

inline
void rehash(void)
{
}

inline
void countUpperBounds(void)
{
    int prev[26] = {},
        next[26] = {},
        w = 0;

    for(int l = 0; l < 26; ++ l)
        next[l] = 131072;

    for(w = 0; word[w]; ++ w)
    {
        end[w] = w - prev[word[w] - 'a'];
        prev[word[w] - 'a'] = w + 1;
    }

    for(w = w - 1; w >= 0; -- w)
    {
        end[w] = std::min(end[w], next[word[w] - 'a'] - w);
        next[word[w] - 'a'] = w - 1;
    }
}

inline
void countRadius(void)
{
    for(int w = 0; word[w]; ++ w)
    {
        for(int r = std::max(1, radius[w]); r <= end[w] && w - r >= 0 && word[r]; r = (r * 2) + 1)
        {
            if(radius[w - (r + 1) / 2] < r / 2 || !compare(w - r, w, w + 1, w + 1 + r))
                break;

            radius[w + (r + 1) / 2] = std::max(radius[w + (r + 1) / 2], std::min(radius[w - (r + 1) / 2], r / 2));
            radius[w] = r;
        }
    }
}

inline
bool compare(int startA, int endA, int startB, int endB)
{
    for(int f = startA, s = startB; f < endA && s < endB; ++ f, ++ s)
        if(word[f] != word[s])
            return false;

    return true;
}
