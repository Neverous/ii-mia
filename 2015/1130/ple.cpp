/* 2015
 * Maciej Szeptuch
 * II UWr
 */
#include <algorithm>
#include <cstdio>

int backpacks;
int needed;
int size[524288];

int main(void)
{
    scanf("%d", &backpacks);
    for(int b = 0; b < backpacks; ++ b)
        scanf("%d", &size[b]);

    std::sort(size, size + backpacks);
    needed = 1;
    for(int b = 1, current = 1; b < backpacks; ++ b)
    {
        if(size[b] == size[b-1])
        {
            ++ current;
            if(needed < current)
                needed = current;
        }

        else
            current = 1;
    }

    printf("%d\n", needed);
    return 0;
}
