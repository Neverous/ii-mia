/* 2013
 * Maciej Szeptuch
 * IIUWr
 */
#include <cstdio>
#include <queue>

int asteroids,
    time, prev,
    shot, shield,
    result;

std::priority_queue<int> hit;

int main(void)
{
    scanf("%d", &asteroids);
    for(int a = 0; a < asteroids; ++ a)
    {
        scanf("%d %d", &time, &shot);
        shield += time - prev;

        hit.push(shot);
        while(!hit.empty() && shield < shot)
        {
            shield += hit.top();
            hit.pop();
            ++ result;
        }

        shield -= shot;
        prev = time;
    }

    printf("%d\n", result);
    return 0;
}
