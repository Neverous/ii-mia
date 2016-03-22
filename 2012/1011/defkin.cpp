/* 2012
 * Maciej Szeptuch
 * II UWr
 */
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int tests,
    width, height,
    towers, w, h,
    maxH, maxW;
vector<int> rows, cols;

int main(void)
{
    scanf("%d", &tests);
    for(int t = 0; t < tests; ++ t)
    {
        scanf("%d %d %d", &width, &height, &towers);
        maxW = maxH = 1;
        rows.clear();
        cols.clear();
        rows.push_back(0); cols.push_back(0);
        rows.push_back(height + 1); cols.push_back(width + 1);
        for(int tow = 0; tow < towers; ++ tow)
        {
            scanf("%d %d", &w, &h);
            rows.push_back(h);
            cols.push_back(w);
        }

        sort(rows.begin(), rows.end());
        sort(cols.begin(), cols.end());
        for(int r = 1; r < rows.size(); ++ r)
            if(maxW < rows[r] - rows[r - 1])
                maxW = rows[r] - rows[r - 1];

        for(int c = 1; c < cols.size(); ++ c)
            if(maxH < cols[c] - cols[c - 1])
                maxH = cols[c] - cols[c - 1];

        printf("%d\n", (maxW - 1) * (maxH - 1));
    }

    return 0;
}
