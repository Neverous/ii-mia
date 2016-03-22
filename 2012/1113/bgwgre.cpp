/* 2012
 * Maciej Szeptuch
 * II UWr
 */
#include<cstdio>

int n, k;

int main(void)
{
    scanf("%d %d", &n, &k);
    puts(n%(k+1) == 0?"Bartek":"Adam");
    return 0;
}
