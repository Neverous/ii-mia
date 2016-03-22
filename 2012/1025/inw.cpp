/* 2012
 * Maciej Szeptuch
 * II UWr
 */
#include<cstdio>

#define MOD 1000000007
#define SIZE (1 << 16)

class iTree
{
    private:
        long long int data[SIZE * 2];

    public:
        iTree(void);
        void clear(void);
        void update(const int &pos, const long long int &val);
        long long int getSum(const int &start = 1, const int &end = SIZE, const int iStart = 1, const int iEnd = SIZE, const int pos = 1);
};

int numbers,
    size,
    number[1 << 16];
long long int result[1 << 16];
iTree tree;

int main(void)
{
    scanf("%d %d", &numbers, &size);
    for(int n = 0; n < numbers; ++ n)
    {
        scanf("%d", &number[n]);
        result[n] = 1;
    }

    for(int k = 1; k < size; ++ k)
    {
        tree.clear();
        for(int n = numbers - 1; n >= 0; -- n)
        {
            int temp = result[n];
            result[n] = tree.getSum(1, number[n]);
            tree.update(number[n], temp);
            //printf("%d(%d) with %d gives %lld\n", n, number[n], k, result[n]);
        }
    }

    for(int n = numbers - 1; n > 0; -- n)
        result[n - 1] = (result[n - 1] + result[n]) % MOD;

    printf("%lld\n", result[0] % MOD);
}

iTree::iTree(void)
{
    clear();
}

void iTree::clear(void)
{
    for(int d = 0; d < SIZE * 2; ++ d)
        data[d] = 0;
}

void iTree::update(const int &pos, const long long int &val)
{
    //printf("updating %d with %lld\n", pos, val);
    for(int p = pos + SIZE - 1; p; p /= 2)
        data[p] = (data[p] + val) % MOD;
}

long long int iTree::getSum(const int &start, const int &end, const int iStart, const int iEnd, const int pos)
{
    if(start == iStart && end == iEnd)
        return data[pos];

    //printf("looking for %d %d %d %d %d %d\n", start, end, iStart, iEnd, pos, data[pos]);
    const int iMid = (iStart + iEnd) / 2;
    if(end <= iMid)
        return getSum(start, end, iStart, iMid, pos * 2) % MOD;

    if(start > iMid)
        return getSum(start, end, iMid + 1, iEnd, pos * 2 + 1) % MOD;

    return (getSum(start, iMid, iStart, iMid, pos * 2) + getSum(iMid + 1, end, iMid + 1, iEnd, pos * 2 + 1)) % MOD;
}
