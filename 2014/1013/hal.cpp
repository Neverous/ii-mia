/* 2014
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>

int requests,
    numbers,
    from, to;

class iTree
{
    public:
        static const int SIZE = 1 << 17;
        int data[SIZE * 2];

        iTree(void);
        void propagate(void);
        int getSum(int from, int to, int iStart = 1, int iEnd = SIZE, int pos = 1);
}; // class iTree

iTree tree;

int main(void)
{
    scanf("%d %d", &requests, &numbers);
    for(int n = 0; n < numbers; ++ n)
        scanf("%d", &tree.data[iTree::SIZE + n]);

    tree.propagate();
    for(int r = 0; r < requests; ++ r)
    {
        scanf("%d %d", &from, &to);
        printf("%d\n", tree.getSum(from, to));
    }

    return 0;
}

inline
iTree::iTree(void)
:data()
{
}

inline
void iTree::propagate(void)
{
    for(int p = SIZE - 1; p > 0; -- p)
        data[p] = data[p * 2] + data[p * 2 + 1];
}

inline
int iTree::getSum(int start, int end, int iStart, int iEnd, int pos)
{
    if(start == iStart && end == iEnd)
        return data[pos];

    int iMiddle = (iStart + iEnd) / 2;
    if(start > iMiddle)
        return getSum(start, end, iMiddle + 1, iEnd, pos * 2 + 1);

    if(end <= iMiddle)
        return getSum(start, end, iStart, iMiddle, pos * 2);

    return  getSum(start, iMiddle, iStart, iMiddle, pos * 2)
        +   getSum(iMiddle + 1, end, iMiddle + 1, iEnd, pos * 2 + 1);
}
