/* 2015
 * Maciej Szeptuch
 * II UWr
 */
#include <algorithm>
#include <cstdio>
#include <cstring>

char word[128];
long long int dp[2][8];
long long int *cur  = dp[0];
long long int *prev = dp[1];

const int ONE_VOWEL         = 0;
const int TWO_VOWELS        = 2;
const int ONE_CONSONANT     = 4;
const int TWO_CONSONANTS    = 6;
const int HAS_L             = 1;

inline
bool is_vowel(char l)
{
    return  l == 'A'
        ||  l == 'E'
        ||  l == 'I'
        ||  l == 'O'
        ||  l == 'U';
}

int main(void)
{
    scanf("%s", word);
    if(word[0] == '_')
    {
        cur[ONE_VOWEL] = 5;
        cur[ONE_CONSONANT] = 20;
        cur[ONE_CONSONANT | HAS_L] = 1;
    }

    else if(is_vowel(word[0]))
        cur[ONE_VOWEL] = 1;

    else
        cur[ONE_CONSONANT | (word[0] == 'L' ? HAS_L : 0)] = 1;

    for(int w = 1; word[w]; ++ w)
    {
        std::swap(cur, prev);
        memset(cur, 0, 8 * sizeof(long long int));
        bool vowel = word[w] == '_' || is_vowel(word[w]);
        bool consonant = word[w] == '_' || !vowel;

        if(vowel)
        {
            cur[ONE_VOWEL]  = prev[ONE_CONSONANT]
                            + prev[TWO_CONSONANTS];

            cur[TWO_VOWELS] = prev[ONE_VOWEL];

            cur[ONE_VOWEL | HAS_L]  = prev[ONE_CONSONANT | HAS_L]
                                    + prev[TWO_CONSONANTS | HAS_L];

            cur[TWO_VOWELS | HAS_L] = prev[ONE_VOWEL | HAS_L];
        }

        if(consonant)
        {
            cur[ONE_CONSONANT]  = prev[ONE_VOWEL]
                                + prev[TWO_VOWELS];

            cur[TWO_CONSONANTS] = prev[ONE_CONSONANT];

            cur[ONE_CONSONANT | HAS_L]  = prev[ONE_VOWEL | HAS_L]
                                        + prev[TWO_VOWELS | HAS_L];

            cur[TWO_CONSONANTS | HAS_L] = prev[ONE_CONSONANT | HAS_L];

            if(word[w] == 'L')
            {
                cur[ONE_CONSONANT | HAS_L] += cur[ONE_CONSONANT];
                cur[TWO_CONSONANTS | HAS_L] += cur[TWO_CONSONANTS];
                cur[ONE_CONSONANT] = 0;
                cur[TWO_CONSONANTS] = 0;
            }
        }

        if(word[w] == '_')
        {
            cur[ONE_VOWEL]      *= 5;
            cur[TWO_VOWELS]     *= 5;

            cur[ONE_VOWEL | HAS_L]  *= 5;
            cur[TWO_VOWELS | HAS_L] *= 5;

            cur[ONE_CONSONANT | HAS_L]      *= 21;
            cur[TWO_CONSONANTS | HAS_L]     *= 21;

            cur[ONE_CONSONANT | HAS_L] += cur[ONE_CONSONANT];
            cur[TWO_CONSONANTS | HAS_L] += cur[TWO_CONSONANTS];

            cur[ONE_CONSONANT]      *= 20;
            cur[TWO_CONSONANTS]     *= 20;

        }

        /*printf("prev: ");
        for(int i = 0; i < 8; ++ i)
            printf("%lld ", prev[i]);

        puts("");

        printf("cur: ");
        for(int i = 0; i < 8; ++ i)
            printf("%lld ", cur[i]);

        puts("");*/
    }

    printf("%lld\n",    cur[1] + cur[3]
                    +   cur[5] + cur[7]);

    return 0;
}
