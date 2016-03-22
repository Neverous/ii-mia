/* 2016
 * Maciej Szeptuch
 * II UWr
 */
#include <algorithm>
#include <cstdio>
#include <vector>

int message;
int seq[64];
int size;
std::vector<std::pair<int, int> > bucket[2];

void fill_bucket(int id, int offset, int _size);
void print_mask(int mask, int bits);

int main(void)
{
    scanf("%d", &size);
    for(int s = 0; s < size; ++ s)
        scanf("%d", &seq[s]);

    scanf("%d", &message);

    int first_bucket_size = (1 << (size / 2));
    int second_bucket_size = (1 << (size - size / 2));
    fill_bucket(0, 0, first_bucket_size);
    fill_bucket(1, size / 2, second_bucket_size);
    for(int i = 0, j = second_bucket_size - 1; j >= 0 && i < first_bucket_size; ++ i)
    {
        while(j >= 0 && bucket[0][i].first + bucket[1][j].first > message)
            -- j;

        if(bucket[0][i].first + bucket[1][j].first == message)
        {
            print_mask(bucket[0][i].second, size / 2); print_mask(bucket[1][j].second, size - size / 2); puts("");
            return 0;
        }
    }

    return 0;
}

void fill_bucket(int id, int offset, int _size)
{
    for(int m = 0; m < _size; ++ m)
    {
        int maskvalue = 0;
        for(int b = 0; (1 << b) <= m; ++ b)
            if(m & (1 << b))
                maskvalue += seq[offset + b];

        bucket[id].push_back(std::make_pair(maskvalue, m));
    }

    std::sort(bucket[id].begin(), bucket[id].end());
}

void print_mask(int mask, int bits)
{
    for(int b = 0; b < bits; ++ b, mask /= 2)
        putchar((mask % 2) + '0');
}
