/* 2013
 * Maciej Szeptuch
 * IIUWr
 */
#include <cstdio>
#include <set>

int students,
    first, place,
    rank[262144];
long long int result;
class iTree
{
    static const int SIZE = 262144;
    int data[SIZE * 2];

    public:
        iTree(void);
        int count(int start, int end, int iStart = 0, int iEnd = SIZE - 1, int pos = 1);
        void insert(int pos);
};
iTree already;

int main(void)
{
    scanf("%d", &students);
    for(int s = 0; s < students; ++ s)
    {
        scanf("%d %d", &first, &place);
        rank[-- first] = place - 1;
    }

    for(int s = 0; s < students; ++ s)
    {
        result += already.count(rank[s], students);
        already.insert(rank[s]);
    }

    printf("%lld\n", result);
    return 0;
}

inline
iTree::iTree(void)
:data()
{
}

inline
int iTree::count(int start, int end, int iStart/* = 0*/, int iEnd/* = SIZE - 1*/, int pos/* = 1*/)
{
    if(iStart == start && iEnd == end)
        return data[pos];

    int iMid = (iStart + iEnd) / 2;
    if(end <= iMid)
        return count(start, end, iStart, iMid, pos * 2);

    if(start > iMid)
        return count(start, end, iMid + 1, iEnd, pos * 2 + 1);

    return count(start, iMid, iStart, iMid, pos * 2) + count(iMid + 1, end, iMid + 1, iEnd, pos * 2 + 1);
}

inline
void iTree::insert(int pos)
{
    pos += SIZE;
    while(pos > 0)
    {
        ++ data[pos];
        pos /= 2;
    }
}
