/* 2012
 * Maciej Szeptuch
 * II UWr
 */
#include<cstdio>
#include<algorithm>

using namespace std;

int rWidth, rHeight,
    tWidth, tHeight;

inline static const int count(const int &roadW, const int &roadH, const int &tileW, const int &tileH);

int main(void)
{
    scanf("%d %d %d %d", &rWidth, &rHeight, &tWidth, &tHeight);
    printf("%d\n", min(count(rWidth, rHeight, tWidth, tHeight), count(rWidth, rHeight, tHeight, tWidth)));
    return 0;
}

inline static const int count(const int &roadW, const int &roadH, const int &tileW, const int &tileH)
{
    int full = max(1, (roadW / tileW) * (roadH / tileH)),
        bottom = 0, bottomSpan = 1048576,
        right = 0, rightSpan = 1048576;

    if(roadH % tileH)
    {
        bottomSpan = tileH / (roadH % tileH);
        bottom = (((roadW + tileW - 1) / tileW) + bottomSpan - 1) / bottomSpan;
    }

    if(roadW % tileW)
    {
        rightSpan = tileW / (roadW % tileW);
        right = (((roadH + tileH - 1) / tileH) + rightSpan - 1) / rightSpan;
    }

    //printf("full: %d\nbottom: %d\nbottomSpan: %d\nright: %d\nrightSpan: %d\n\n", full, bottom, bottomSpan, right, rightSpan);
    return full + bottom + right - ((roadW / tileW) % bottomSpan == 0 || (roadH / tileH) % rightSpan == 0 ? 1 : 0);
}
