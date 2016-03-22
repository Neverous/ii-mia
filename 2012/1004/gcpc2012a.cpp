/* 2012
 * Maciej Szeptuch
 * II UWr
 */
#include<cstdio>

int tests,
    width,
    height,
    shots,
    xs, ys,
    wins,
    player,
    moves[2];
char map[2][32][32];

void makeShot(const int &x, const int &y);
void checkWinners();

int main(void)
{
    scanf("%d", &tests);
    for(int t = 0; t < tests; ++ t)
    {
        wins = 0;
        player = 0;
        moves[0] = moves[1] = 0;
        scanf("%d %d %d", &width, &height, &shots);
        for(int h = 0; h < height; ++ h)
            scanf("%s", map[0][h]);

        for(int h = 0; h < height; ++ h)
            scanf("%s", map[1][h]);

        for(int s = 0; s < shots; ++ s)
        {
            scanf("%d %d", &xs, &ys);
            makeShot(xs, height - 1 - ys);
        }

        checkWinners();
        puts(wins == 3 || wins == 0 ? "draw" : wins == 1 ? "player one wins" : "player two wins");
    }

    return 0;
}

void makeShot(const int &x, const int &y)
{
    moves[player] ++;
    bool hit = map[player ^ 1][y][x] == '#';
    map[player ^ 1][y][x] = '_';
    bool opposite = false;
    for(int y0 = 0; !opposite && y0 < height; ++ y0)
        for(int x0 = 0; !opposite && x0 < width; ++ x0)
            opposite = map[player ^ 1][y0][x0] == '#';

    if(hit && !opposite && moves[player ^ 1] < shots / 2)
        player ^= 1;

    else if(!hit && opposite)
        player ^= 1;
}

void checkWinners()
{
    bool killed = true;
    for(int p = 0; p < 2; ++ p)
    {
        killed = true;
        for(int y = 0; killed && y < height; ++ y)
            for(int x = 0; killed && x < width; ++ x)
                killed = map[p][y][x] == '_';

        if(killed)
            wins |= (1 << (1 - p));
    }
}
