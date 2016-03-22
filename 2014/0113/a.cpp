/* 2014
 * Maciej Szeptuch
 * IIUWr
 */
#include <cstdio>
#include <cassert>

int length,
    mat[1024][1024],
    last;

int main(void)
{
    scanf("%d", &length);
    if(length == 2)
    {
        puts("1 1");
        return 0;
    }

    for(int h = 0; h < length; ++ h)
        for(int w = 0; w < length; ++ w)
            scanf("%d", &mat[h][w]);

    last = (mat[length - 3][length - 1] + mat[length - 2][length - 1] - mat[length - 3][length - 2]) / 2;
    for(int l = 0; l < length - 1; ++ l)
    {
        assert(mat[l][length - 1] - last > 0);
        printf("%d ", mat[l][length - 1] - last);
    }

    assert(last > 0);
    printf("%d\n", last);
    return 0;
}
