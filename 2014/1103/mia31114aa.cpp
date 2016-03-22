/* 2014
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>

int buttons,
    operations,
    button,
    counter[1048576],
    leveled[1048576],
    max, currentMax, currentLevel;

int main(void)
{
    scanf("%d %d", &buttons, &operations);
    for(int o = 0; o < operations; ++ o)
    {
        scanf("%d", &button); -- button;
        if(button == buttons)
        {
            currentMax = max;
            ++ currentLevel;
            continue;
        }

        if(leveled[button] < currentLevel)
        {
            leveled[button] = currentLevel;
            counter[button] = currentMax;
        }

        ++ counter[button];
        if(counter[button] > max)
            max = counter[button];
    }

    for(int b = 0; b < buttons; ++ b)
        printf("%d ", leveled[b] == currentLevel ? counter[b] : currentMax);

    puts("");
    return 0;
}
