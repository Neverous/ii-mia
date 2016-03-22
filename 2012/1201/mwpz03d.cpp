/* 2013
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>
#define abs(x) ((x) > 0 ? (x) : -(x))

int tests,
    moves,
    direction,
    steps,
    x, y;
int modifier[4] = {1, -1, 1, -1};

int main(void)
{
    scanf("%d", &tests);
    for(int t = 0; t < tests; ++ t)
    {
        x = y = 0;
        scanf("%d", &moves);
        for(int m = 0; m < moves; ++ m)
        {
            scanf("%d %d", &direction, &steps);
            if(direction < 2)
                x += modifier[direction] * steps;

            else
                y += modifier[direction] * steps;
        }

        if(x || y)
        {
            if(x) printf("%d %d\n", x > 0 ? 0 : 1, abs(x));
            if(y) printf("%d %d\n", y > 0 ? 2 : 3, abs(y));
        }

        else
            puts("studnia");
    }

    return 0;
}
