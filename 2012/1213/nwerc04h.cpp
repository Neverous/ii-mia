/* 2013
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>
#include <algorithm>

int tests,
    MOD,
    len,
    res,
    matrix[128][256],
    repr[256];
char buffer[128];

inline void inverseMatrix(const int &size);
inline int inverse(const int &a, const int &b);
inline std::pair<int, int> extEuclides(const int &a, const int &b);

int main(void)
{
    for(int s = 0; s < 26; ++ s)
        repr['a' + s] = s + 1;

    scanf("%d", &tests);
    for(int t = 0; t < tests; ++ t)
    {
        scanf("%d %s", &MOD, buffer);
        len = 0; while(buffer[len]) ++ len;
        inverseMatrix(len);
        for(int h = 0; h < len; ++ h)
        {
            res = 0;
            for(int w = 0; w < len; ++ w)
                res = (res + matrix[h][len + w] * repr[(int)buffer[w]]) % MOD;

            printf("%d ", res);
        }

        puts("");
    }

    return 0;
}

inline void inverseMatrix(const int &size)
{
    /* fill with zeros */
    for(int h = 0; h < size; ++ h)
        for(int w = 0; w < 2 * size; ++ w)
            matrix[h][w] = 0;

    /* add identity matrix after */
    for(int h = 0; h < size; ++ h)
        matrix[h][size + h] = 1;

    /* fill with equations */
    for(int h = 0; h < size; ++ h)
    {
        matrix[h][0] = 1;
        for(int w = 1; w < size; ++ w)
            matrix[h][w] = matrix[h][w - 1] * (h + 1) % MOD;
    }

    /* eliminate bottom triangle */
    int co = 0;
    for(int h = 0; h < size; ++ h)
        for(int e = h + 1; e < size; ++ e)
        {
            co = (matrix[e][h] * inverse(matrix[h][h], MOD)) % MOD;
            for(int w = 0; w < 2 * size; ++ w)
                matrix[e][w] = (32768* MOD + matrix[e][w] - co * matrix[h][w]) % MOD;
        }

    /* eliminate top triangle */
    for(int h = size - 1; h >= 0; -- h)
    {

        for(int e = h - 1; e >= 0; -- e)
        {
            co = matrix[e][h] * inverse(matrix[h][h], MOD) % MOD;
            for(int w = h; w < 2 * size; ++ w)
                matrix[e][w] = (32768 * MOD + matrix[e][w] - co * matrix[h][w]) % MOD;
        }
    }

    /* make rest identity matrix */
    for(int h = 0; h < size; ++ h)
        if(matrix[h][h] != 1)
        {
            int temp = inverse(matrix[h][h], MOD);
            for(int w = 0; w < 2 * size; ++ w)
                matrix[h][w] = (matrix[h][w] * temp) % MOD;
        }

    return;
}

inline int inverse(const int &a, const int &b)
{
    return (32768 * MOD + extEuclides(b, a).second) % MOD;
}

inline std::pair<int, int> extEuclides(const int &a, const int &b)
{
    std::pair<int, int> result(1, 0);
    if(!b)
        return result;

    result = extEuclides(b, a % b);
    int temp = result.first;
    result.first = result.second;
    result.second = temp - result.second * (a / b);
    return result;
}
