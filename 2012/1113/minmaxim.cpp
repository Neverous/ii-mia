/* 2013
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>
#include <algorithm>

class iTree
{
    public:
        iTree(const int &val = 0);
        void insert(int pos, const int &value);
        int getMin(const int &start, const int &end, const int &iStart = 0, const int &iEnd = SIZE - 1, const int &pos = 1);

    private:
        const static int SIZE = 65536;
        int data[SIZE * 2];
};

int numbers,
    length,
    start, end,
    result[65536];

iTree tree(65536);

int main(void)
{
    scanf("%d %d", &numbers, &length);
    for(int n = 1; n < numbers; ++ n)
        result[n] = length;

    tree.insert(0, 0);
    for(int l = 0; l < length; ++ l)
    {
        scanf("%d %d", &start, &end);
        -- start; -- end;
        result[end] = std::min(result[end], tree.getMin(start, end) + 1);
        tree.insert(end, result[end]);
    }

    printf("%d\n", result[numbers - 1]);
    return 0;
}

inline iTree::iTree(const int &val)
:data()
{
    for(int s = 0; s < SIZE * 2; ++ s)
        data[s] = val;
}

inline void iTree::insert(int pos, const int &value)
{
    pos += SIZE;
    while(pos > 0)
    {
        data[pos] = std::min(data[pos], value);
        pos /= 2;
    }
}

inline int iTree::getMin(const int &start, const int &end, const int &iStart, const int &iEnd, const int &pos)
{
    if(start == iStart && end == iEnd)
        return data[pos];

    int iMid = (iStart + iEnd) / 2;
    if(end <= iMid)
        return getMin(start, end, iStart, iMid, pos * 2);

    else if(start > iMid)
        return getMin(start, end, iMid + 1, iEnd, pos * 2 + 1);


    return std::min(getMin(start, iMid, iStart, iMid, pos * 2), getMin(iMid + 1, end, iMid + 1, iEnd, pos * 2 + 1));
}
