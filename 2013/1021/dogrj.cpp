/* 2013
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>
#include <cmath>

long double eye, bull,
            inner_t, outer_t,
            inner_d, outer_d,
            sigma;

long double INT(long double r, long double q)
{
    return -expl(-r * r / 2 / q / q);
}

int main(void)
{
    scanf("%Lf %Lf %Lf %Lf %Lf %Lf %Lf", &eye, &bull, &inner_t, &outer_t, &inner_d, &outer_d, &sigma);
    printf("%.9Lf\n",
        50   * (INT(eye, sigma) - INT(0, sigma)) +
        25   * (INT(bull, sigma) - INT(eye, sigma)) +
        10.5 * (INT(outer_d, sigma) - INT(inner_d, sigma)) +
        21   * (INT(outer_t, sigma) - INT(inner_t, sigma)) +
        10.5 * (INT(outer_d, sigma) - INT(bull, sigma)));

    return 0;
}
