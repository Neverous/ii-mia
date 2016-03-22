/* 2013
 * Maciej Szeptuch
 * IIUWr
 */
#include <cstdio>
#include <set>

int students,
    first[262144], second[262144], third[262144];

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

long long int solve(const int *A, const int *B);

int main(void)
{
    scanf("%d", &students);
    for(int s = 0; s < students; ++ s)
    {
        scanf("%d %d %d", &first[s], &second[s], &third[s]);
        -- first[s];
        -- second[s];
        -- third[s];
    }

    printf("%lld\n", (solve(first, second) + solve(first, third) + solve(second, third)) / 2);
    return 0;
}

long long int solve(const int *A, const int *B)
{
    int rank[262144]    = {};
    long long int res   = 0;
    iTree tree;

    for(int s = 0; s < students; ++ s)
        rank[A[s]] = B[s];

    for(int s = 0; s < students; ++ s)
    {
        res += tree.count(rank[s], students);
        tree.insert(rank[s]);
    }

    return res;
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
