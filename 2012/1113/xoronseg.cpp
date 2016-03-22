/* 2012
 * Maciej Szeptuch
 * II UWr
 */
#include<cstdio>

class iTree
{
    private:
        static const int SIZE = 131072;
        int data[SIZE * 2];
        bool postponed[SIZE * 2];

    public:
        void propagate(const int &bit);
        void checkPostponed(const int &pos, const int &iStart, const int &iEnd);
        void swap(const int &start, const int &end, const int &pos = 1, const int &iStart = 0, const int &iEnd = SIZE - 1);
        const int getSum(const int &start, const int &end, const int &pos = 1, const int &iStart = 0, const int &iEnd = SIZE - 1);
};

int size,
    questions,
    type,
    start, end;

int number,
    tab[131072];
long long int sum;

iTree tree[20];

int main(void)
{
    scanf("%d", &size);
    for(int s = 0; s < size; ++ s)
        scanf("%d", &tab[s]);

    for(int t = 0; t < 20; ++ t)
        tree[t].propagate(t);

    scanf("%d", &questions);
    for(int q = 0; q < questions; ++ q)
    {
        scanf("%d %d %d", &type, &start, &end);
        -- start; -- end;
        if(type == 2)
        {
            scanf("%d", &number);
            for(int t = 0; t < 20; ++ t)
                if(number & (1 << t))
                    tree[t].swap(start, end);

            continue;
        }
        
        sum = 0;
        for(int t = 0; t < 20; ++ t)
            sum += (1LL << t) * tree[t].getSum(start, end);

        printf("%lld\n", sum);
    }

    return 0;
}

inline void iTree::propagate(const int &bit)
{
    for(int s = 0; s < size; ++ s)
        data[SIZE + s] = (bool) ((1 << bit) & tab[s]);

    for(int p = SIZE - 1, p2 = p << 1; p > 0; p2 = (-- p) << 1)
        data[p] = data[p2] + data[p2 | 1];
}

inline void iTree::checkPostponed(const int &pos, const int &iStart, const int &iEnd)
{
    if(!postponed[pos])
        return;

    int iMid = (iStart + iEnd) >> 1,
        pos2 = pos << 1,
        pos3 = pos2 | 1;
    postponed[pos] = 0;

    postponed[pos2] ^= 1;
    data[pos2] = iMid - iStart + 1 - data[pos2];

    postponed[pos3] ^= 1;
    data[pos3] = iEnd - iMid - data[pos3];
}

inline void iTree::swap(const int &start, const int &end, const int &pos, const int &iStart, const int &iEnd)
{
    if(start == iStart && end == iEnd)
    {
        data[pos] = end - start + 1 - data[pos];
        postponed[pos] ^= 1;
        return;
    }

    checkPostponed(pos, iStart, iEnd);
    int iMid = (iStart + iEnd) >> 1,
        pos2 = pos << 1,
        pos3 = pos2 | 1;
    if(end <= iMid)
        swap(start, end, pos2, iStart, iMid);

    else if(start > iMid)
        swap(start, end, pos3, iMid + 1, iEnd);

    else
    {
        swap(start, iMid, pos2, iStart, iMid);
        swap(iMid + 1, end, pos3, iMid + 1, iEnd);
    }

    data[pos] = data[pos2] + data[pos3];
}

inline const int iTree::getSum(const int &start, const int &end, const int &pos, const int &iStart, const int &iEnd)
{
    if(start == iStart && end == iEnd)
        return data[pos];

    checkPostponed(pos, iStart, iEnd);
    int iMid = (iStart + iEnd) >> 1;
    if(end <= iMid)
        return getSum(start, end, pos << 1, iStart, iMid);

    if(start > iMid)
        return getSum(start, end, pos << 1 | 1, iMid + 1, iEnd);

    return getSum(start, iMid, pos << 1, iStart, iMid) + getSum(iMid + 1, end, pos << 1 | 1, iMid + 1, iEnd);
}
