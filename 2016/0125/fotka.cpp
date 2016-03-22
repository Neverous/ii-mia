/* 2015
 * Maciej Szeptuch
 * II UWr
 */
#include <algorithm>
#include <cstdio>

const int MAX_HEIGHT = 1073741824;
const int MAX_STUDENTS = 262144;
int columns;
int height[MAX_STUDENTS];
int rows;
int students;

bool check(int diff);

int main(void)
{
    scanf("%d %d %d", &students, &rows, &columns);
    for(int s = 0; s < students; ++ s)
        scanf("%d", &height[s]);

    std::sort(height, height + students);
    int s = 0,
        e = MAX_HEIGHT;

    while(s < e)
    {
        int mid = (s + e) / 2;
        if(check(mid))
            e = mid;

        else
            s = mid + 1;
    }

    printf("%d\n", s);
}

bool check(int diff)
{
    int count = 0;
    for(int s = 0; s + columns - 1 < students && count < rows; ++ s)
    {
        if(height[s + columns - 1] - height[s] <= diff)
        {
            ++ count;
            s += columns - 1;
        }
    }

    return count >= rows;
}
