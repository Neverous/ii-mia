/* 2013
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>
#include <cstring>

int blocks,
    height,
    questions,
    block[524288][2],
    from, to;

class iTree
{
    static const int SIZE = 524288;
    int level1[SIZE / 2][2][2],
        level2[SIZE / 4][2][4],
        level3[SIZE / 8][2][8],
        level4[SIZE / 8][2][10];

    int *getMax(int pos, int &size);
    int *getMin(int pos, int &size);
    void mergeMin(const int *A, int asize, const int *B, int bsize, int *C, int csize);
    void mergeMax(const int *A, int asize, const int *B, int bsize, int *C, int csize);
    void getInterval(const int start, const int end, int *MIN, int *MAX, const int height, const int iStart = 0, const int iEnd = SIZE - 1, const int pos = 1);

    public:
        iTree(void);
        void init(void);
        long long int getDiff(int start, int end);
}; // class iTree
iTree tree;

int main(void)
{
    scanf("%d %d %d", &blocks, &height, &questions);
    for(int b = 0; b < blocks; ++ b)
    {
        scanf("%d", &block[b][0]);
        block[b][1] = block[b][0];
    }

    tree.init();
    for(int q = 0; q < questions; ++ q)
    {
        scanf("%d %d", &from, &to); -- from, --to;
        printf("%lld\n", tree.getDiff(from, to));
    }

    return 0;
}

inline
iTree::iTree(void)
:level1()
,level2()
,level3()
,level4()
{
    for(int s = 0; s < 2 * SIZE; ++ s)
    {
        int *A, asize;
        A = getMin(s, asize);
        for(int a = 0; a < asize; ++ a)
            *A ++ = (1 << 30);
    }
}

inline
void iTree::init(void)
{
    for(int s = SIZE - 1; s > 0; -- s)
    {
        int *A, asize, *B, bsize, *C, csize;
        A = getMax(s * 2, asize), B = getMax(s * 2 + 1, bsize), C = getMax(s, csize);
        mergeMax(A, asize, B, bsize, C, csize);

        A = getMin(s * 2, asize), B = getMin(s * 2 + 1, bsize), C = getMin(s, csize);
        mergeMin(A, asize, B, bsize, C, csize);
    }
}

inline
int *iTree::getMax(int pos, int &size)
{
    if(pos < SIZE / 8)
    {
        size = 10;
        return level4[pos][0];
    }

    pos -= SIZE / 8;
    if(pos < SIZE / 8)
    {
        size = 8;
        return level3[pos][0];
    }

    pos -= SIZE / 8;
    if(pos < SIZE / 4)
    {
        size = 4;
        return level2[pos][0];
    }

    pos -= SIZE / 4;
    if(pos < SIZE / 2)
    {
        size = 2;
        return level1[pos][0];
    }

    pos -= SIZE / 2;
    size = 1;
    return &block[pos][0];
}

inline
int *iTree::getMin(int pos, int &size)
{
    if(pos < SIZE / 8)
    {
        size = 10;
        return level4[pos][1];
    }

    pos -= SIZE / 8;
    if(pos < SIZE / 8)
    {
        size = 8;
        return level3[pos][1];
    }

    pos -= SIZE / 8;
    if(pos < SIZE / 4)
    {
        size = 4;
        return level2[pos][1];
    }

    pos -= SIZE / 4;
    if(pos < SIZE / 2)
    {
        size = 2;
        return level1[pos][1];
    }

    pos -= SIZE / 2;
    size = 1;
    return &block[pos][1];
}

inline
void iTree::mergeMin(const int *A, int asize, const int *B, int bsize, int *C, int csize)
{
    for(int a = 0, b = 0, c = 0; a <= asize && b <= bsize && c < csize; ++ c)
    {
        if(b == bsize || (a != asize && *A < *B))
        {
            *C ++ = *A ++;
            ++ a;
            continue;
        }

        *C ++ = *B ++;
        ++ b;
    }
}

inline
void iTree::mergeMax(const int *A, int asize, const int *B, int bsize, int *C, int csize)
{
    for(int a = 0, b = 0, c = 0; a <= asize && b <= bsize && c < csize; ++ c)
    {
        if(b == bsize || (a != asize && *A > *B))
        {
            *C ++ = *A ++;
            ++ a;
            continue;
        }

        *C ++ = *B ++;
        ++ b;
    }
}

inline
long long int iTree::getDiff(int start, int end)
{
    int MIN[10] = {(1 << 30), (1 << 30), (1 << 30), (1 << 30), (1 << 30), (1 << 30), (1 << 30), (1 << 30), (1 << 30), (1 << 30)},
        MAX[10] = {};

    getInterval(start, end, MIN, MAX, height);

    long long int result = 0;
    for(int h = 0; h < height; ++ h)
        result += MAX[h] - MIN[h];

    return result;
}

inline
void iTree::getInterval(const int start, const int end, int *MIN, int *MAX, const int height, const int iStart/* = 0*/, const int iEnd/* = SIZE - 1*/, const int pos/* = 1*/)
{
    if(start == iStart && end == iEnd)
    {
        int *A, asize,
            C[10];
        A = getMin(pos, asize);
        mergeMin(A, asize, MIN, height, C, height);
        memcpy(MIN, C, height * sizeof(int));

        A = getMax(pos, asize);
        mergeMax(A, asize, MAX, height, C, height);
        memcpy(MAX, C, height * sizeof(int));
        return;
    }

    int iMid = (iStart + iEnd) / 2;
    if(end <= iMid)
        getInterval(start, end, MIN, MAX, height, iStart, iMid, pos * 2);

    else if(start > iMid)
        getInterval(start, end, MIN, MAX, height, iMid + 1, iEnd, pos * 2 + 1);

    else
    {
        getInterval(start, iMid, MIN, MAX, height, iStart, iMid, pos * 2);
        getInterval(iMid + 1, end, MIN, MAX, height, iMid + 1, iEnd, pos * 2 + 1);
    }
}
