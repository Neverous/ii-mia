/* 2016
 * Maciej Szeptuch
 * II UWr
 */
#include <algorithm>
#include <cstdio>

const int MAX_SIZE = 2048;

int tests;
int size;
char row[MAX_SIZE][MAX_SIZE];

bool validate(void);
int solve(void);

int main(void)
{
    scanf("%d", &tests);
    for(int t = 0; t < tests; ++ t)
    {
        scanf("%d", &size);
        for(int s = 0; s < 2 * size; ++ s)
            scanf("%s", row[s]);

        printf("Case #%d: ", t + 1);
        if(!validate())
            puts("IMPOSSIBLE");

        else
            printf("%d\n", solve());
    }

    return 0;
}

bool validate(void)
{
    int count = 0;
    for(int r = 1; r < 2 * size; ++ r)
    {
        bool inverse = row[0][0] != row[r][0];
        for(int c = 0; c < 2 * size; ++ c)
            if(inverse ^ (row[0][c] != row[r][c]))
                return false;

        count += inverse;
    }

    if(count != size)
        return false;

    count = 0;
    for(int c = 1; c < 2 * size; ++ c)
    {
        bool inverse = row[0][0] != row[0][c];
        for(int r = 0; r < 2 * size; ++ r)
            if(inverse ^ (row[r][0] != row[r][c]))
                return false;

        count += inverse;
    }

    if(count != size)
        return false;

    return true;
}

int solve(void)
{
    int row0 = 0;
    int row1 = 0;
    int col0 = 0;
    int col1 = 0;
    for(int r = 0; r < 2 * size; ++ r)
    {
        row0 += (r % 2) + '0' == row[r][0];
        row1 += ((r + 1) % 2) + '0' == row[r][0];
    }

    for(int c = 0; c < 2 * size; ++ c)
    {
        col0 += (c % 2) + '0' == row[0][c];
        col1 += ((c + 1) % 2) + '0' == row[0][c];
    }

    //printf("DEBUG: row0: %d row1: %d col0: %d col1: %d\n", row0, row1, col0, col1);
    return (std::min(row0, row1) + std::min(col0, col1)) / 2;
}
