/* 2013
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>

int width,
    height;

int main(void)
{
    scanf("%d %d", &width, &height);
    puts((width * height) % 2 ? "Tadek" : "Adam");
    return 0;
}
