/* 2015
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>
#include <algorithm>

int size,
    bucket,
    sortme[8192],
    strength[8192],
    tree[8192];

inline
bool compareStrength(const int a, const int b)
{
    return strength[a] < strength[b];
}

void tree_push(const int pos, const int value);
int tree_get(const int pos);

int main(void)
{
    scanf("%d %d", &size, &bucket);
    for(int s = 0; s < size; ++ s)
    {
        sortme[s] = s;
        scanf("%d", &strength[s]);
    }

    std::sort(sortme, sortme + size, compareStrength);
    for(int s = 0; s < size; ++ s)
        strength[sortme[s]] = s / bucket;

    int result = 0;
    for(int s = 0; s < size; ++ s)
    {
        int temp = tree_get(strength[s]) + 1;
        if(temp > result)
            result = temp;

        tree_push(strength[s], temp);
    }

    printf("%d\n", size - result);
    return 0;
}

inline
void tree_push(const int pos, const int value)
{
    for(int p = pos + 1; p <= size; p += (p&-p))
        tree[p] = std::max(tree[p], value);
}

inline
int tree_get(const int pos)
{
    int result = 0;
    for(int p = pos + 1; p > 0; p -= (p&-p))
        result = std::max(result, tree[p]);

    return result;
}
