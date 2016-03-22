/* 2014
 * Maciej Szeptuch
 * IIUWr
 */
#include <cstdio>
#include <vector>
#include <algorithm>

int tests,
    people,
    result[16384];
std::pair<int, int> person[16384];

class iTree
{
    static const int SIZE = 16384;
    int data[SIZE * 2];

    public:
        iTree(void);
        int get(int want, int pos = 1);
}; // class iTree

int main(void)
{
    scanf("%d", &tests);
    for(int t = 0; t < tests; ++ t)
    {
        iTree tree;
        scanf("%d", &people);
        for(int p = 0; p < people; ++ p)
            scanf("%d", &person[p].first);

        for(int p = 0; p < people; ++ p)
            scanf("%d", &person[p].second);

        std::sort(person, person + people);
        for(int p = 0; p < people; ++ p)
            result[tree.get(person[p].second + 1)] = person[p].first;

        for(int p = 0; p < people; ++ p)
            printf("%d ", result[p]);

        puts("");
    }

    return 0;
}

inline
iTree::iTree(void)
:data()
{
    for(int s = 0; s < SIZE; ++ s)
        data[SIZE + s] = 1;

    for(int s = SIZE - 1; s > 0; -- s)
        data[s] = data[2 * s] + data[2 * s + 1];
}

inline
int iTree::get(int want, int pos/* = 1*/)
{
    while(pos < SIZE)
    {
        -- data[pos];
        if(data[pos * 2] >= want)
            pos = pos * 2;

        else
        {
            want -= data[pos * 2];
            pos = pos * 2 + 1;
        }
    }

    -- data[pos];
    return pos - SIZE;
}
