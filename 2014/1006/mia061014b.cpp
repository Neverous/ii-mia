/* 2014
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>
#include <algorithm>

int dwarves,
    requests,
    number,
    action,
    first,
    second;

class iTree
{
    public:
        static const int SIZE = 2 << 18;
        int min[SIZE * 2];
        int max[SIZE * 2];
        int map[SIZE];

        iTree();
        void populate();

        void swap(int x, int y);
        void fixup(int pos);
        int getMin(int from, int to, int iStart = 0, int iEnd = SIZE - 1, int pos = 1);
        int getMax(int from, int to, int iStart = 0, int iEnd = SIZE - 1, int pos = 1);
}; // class iTree

iTree tree;

int main(void)
{
    scanf("%d %d", &dwarves, &requests);
    for(int d = 0; d < dwarves; ++ d)
    {
        scanf("%d", &number);
        -- number;
        tree.max[iTree::SIZE + number] = tree.min[iTree::SIZE + number] = d;
        tree.map[d] = number;
    }

    tree.populate();
    for(int r = 0; r < requests; ++ r)
    {
        scanf("%d %d %d", &action, &first, &second);
        -- first, -- second;
        switch(action)
        {
            case 1: // SWAP
                tree.swap(first, second);
                break;

            case 2: // CHECK
                if(first > second)
                    std::swap(first, second);

                int start   = tree.getMin(first, second),
                    end     = tree.getMax(first, second);

                puts(end - start == second - first ? "YES" : "NO");
                break;
        }
    }

    return 0;
}

inline
iTree::iTree()
:min()
,max()
,map()
{
    for(int s = 0; s < SIZE * 2; ++ s)
        min[s] = 1048576;
}

inline
void iTree::populate()
{
    for(int p = SIZE - 1; p > 0; -- p)
    {
        max[p] = std::max(max[p * 2], max[p * 2 + 1]);
        min[p] = std::min(min[p * 2], min[p * 2 + 1]);
    }
}

inline
void iTree::swap(int x, int y)
{
    int a = map[x],
        b = map[y];

    std::swap(max[SIZE + a], max[SIZE + b]);
    std::swap(min[SIZE + a], min[SIZE + b]);
    std::swap(map[x], map[y]);

    fixup(a);
    fixup(b);
}

inline
void iTree::fixup(int pos)
{
    pos += SIZE;
    while(pos > 0)
    {
        pos /= 2;
        max[pos] = std::max(max[pos * 2], max[pos * 2 + 1]);
        min[pos] = std::min(min[pos * 2], min[pos * 2 + 1]);
    }
}

inline
int iTree::getMin(int from, int to, int iStart/* = 0*/, int iEnd/* = SIZE - 1*/, int pos/* = 1*/)
{
    if(from == iStart && to == iEnd)
        return min[pos];

    int iMiddle = (iStart + iEnd) / 2;
    if(to <= iMiddle)
        return getMin(from, to, iStart, iMiddle, pos * 2);

    if(from > iMiddle)
        return getMin(from, to, iMiddle + 1, iEnd, pos * 2 + 1);

    return std::min(
        getMin(from, iMiddle, iStart, iMiddle, pos * 2),
        getMin(iMiddle + 1, to, iMiddle + 1, iEnd, pos * 2 + 1));
}

inline
int iTree::getMax(int from, int to, int iStart/* = 0*/, int iEnd/* = SIZE - 1*/, int pos/* = 1*/)
{
    if(from == iStart && to == iEnd)
        return max[pos];

    int iMiddle = (iStart + iEnd) / 2;
    if(to <= iMiddle)
        return getMax(from, to, iStart, iMiddle, pos * 2);

    if(from > iMiddle)
        return getMax(from, to, iMiddle + 1, iEnd, pos * 2 + 1);

    return std::max(
        getMax(from, iMiddle, iStart, iMiddle, pos * 2),
        getMax(iMiddle + 1, to, iMiddle + 1, iEnd, pos * 2 + 1));
}
