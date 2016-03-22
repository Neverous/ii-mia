/* 2013
 * Maciej Szeptuch
 * IIUWr
 */
#include <cstdio>
#include <string>
#include <map>

typedef std::map<std::string, long long unsigned int> Pizzas;

int tests,
    pizzas,
    ingredients;
char ingredient[32];
Pizzas foreign,
       english;

int main(void)
{
    scanf("%d", &tests);
    for(int t = 0; t < tests; ++ t)
    {
        scanf("%d", &pizzas);
        for(int p = 0; p < pizzas; ++ p)
        {
            scanf("%*s%d", &ingredients);
            for(int i = 0; i < ingredients; ++ i)
            {
                scanf("%s", ingredient);
                foreign[std::string(ingredient)] |= 1LLU << p;
            }

            scanf("%d", &ingredients);
            for(int i = 0; i < ingredients; ++ i)
            {
                scanf("%s", ingredient);
                english[std::string(ingredient)] |= 1LLU << p;
            }
        }

        for(Pizzas::iterator f = foreign.begin(); f != foreign.end(); ++ f)
            for(Pizzas::iterator s = english.begin(); s != english.end(); ++ s)
                if(f->second == s->second)
                    printf("(%s, %s)\n", f->first.c_str(), s->first.c_str());

        puts("");
        foreign.clear();
        english.clear();
    }

    return 0;
}
