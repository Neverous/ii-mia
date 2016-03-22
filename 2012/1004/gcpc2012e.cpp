/* 2012
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;
typedef long long unsigned int number;

int tests,
    pizzas,
    ingredients;
map<string, number> foreign,
                    native;
vector<pair<string, string> > result;

char buffer[32];

int main(void)
{
    scanf("%d", &tests);
    for(int t = 0; t < tests; ++ t)
    {
        foreign.clear();
        native.clear();
        result.clear();
        scanf("%d", &pizzas);
        for(int p = 0; p < pizzas; ++ p)
        {
            scanf("%*s");
            scanf("%d", &ingredients);
            for(int i = 0; i < ingredients; ++ i)
            {
                scanf("%s", buffer);
                foreign[string(buffer)] |= (1LLU << p);
            }
            
            scanf("%d", &ingredients);
            for(int i = 0; i < ingredients; ++ i)
            {
                scanf("%s", buffer);
                native[string(buffer)] |= (1LLU << p);
            }
        }
        
        for(map<string, number>::iterator f = foreign.begin(); f != foreign.end(); ++ f)
            for(map<string, number>::iterator n = native.begin(); n != native.end(); ++ n)
                if(f->second == n->second)
                    result.push_back(make_pair(f->first, n->first));
        
        sort(result.begin(), result.end());
        for(unsigned int r = 0; r < result.size(); ++ r)
            printf("(%s, %s)\n", result[r].first.c_str(), result[r].second.c_str());
        
        puts("");
    }
    
    return 0;
}
