/* 2015
 * Maciej Szeptuch
 * II UWr
 */
#include <algorithm>
#include <cstdio>

int height[524288];
int people;
int person;
int stairs;

int main(void)
{
    scanf("%d %d", &stairs, &people);
    for(int s = 0; s < stairs; ++ s)
        scanf("%d", &height[s]);

    for(int s = 1; s < stairs; ++ s)
        if(height[s - 1] > height[s])
            height[s] = height[s - 1];

    for(int p = 0; p < people; ++ p)
    {
        scanf("%d", &person);
        printf("%ld ", std::lower_bound(height, height + stairs, person) - height);
    }

    puts("");
    return 0;
}
