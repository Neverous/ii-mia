/* 2012
 * Maciej Szeptuch
 * II UWr
 */
#include<cstdio>
#include<vector>
#include<queue>

using namespace std;

typedef vector<pair<int, int> > Snake;

int width,
    height,
    map[32][32],
    end;
bool visited[(1 << 25) - 1];
pair<int, int> target;
Snake snake(16);
char buffer[32];

inline static const int findApple(void);
inline static const Snake moveSnake(Snake snake, const int y, const int x);
inline static const int makeMask(Snake snake);

int main(void)
{
    scanf("%d %d", &height, &width);
    for(int h = 0; h < height; ++ h)
    {
        scanf("%s", buffer);
        for(int w = 0; w < width; ++ w)
            switch(buffer[w])
            {
                case '#':
                    map[h][w] = false;
                    break;
                    
                case '@':
                    target = make_pair(h, w);
                    map[h][w] = true;
                    break;
                
                case '.':
                    map[h][w] = true;
                    break;
                    
                default:
                    map[h][w] = true;
                    snake[buffer[w] - '1'] = make_pair(h, w);
                    if(end < buffer[w] - '1') end = buffer[w] - '1';
                    break;
            }
    }
    
    printf("%d\n", findApple());
    return 0;
}

inline static const int findApple(void)
{
    queue<pair<int, Snake> > que;
    Snake act, temp;
    int moves, x, y, mask;
    bool free;
    que.push(make_pair(0, snake));
    
    while(!que.empty())
    {
        act = que.front().second;
        moves = que.front().first;
        que.pop();
        x = act[0].second;
        y = act[0].first;
        for(int h = -1; h < 2; ++ h)
            for(int w = -1; w < 2; ++ w)
                if(!(w * h) && h + y >= 0 && h + y < height && w + x >= 0 && w + x < width && map[h + y][w + x])
                {
                    temp = moveSnake(act, h + y, w + x);
                    mask = makeMask(temp);
                    if(visited[mask])
                        continue;
                   
                    free = true;
                    for(int s = 0; s < end && free; ++ s)
                        if(act[s] == make_pair(h + y, w + x))
                            free = false;
                    
                    if(!free)
                        continue;
                    
                    if(target == make_pair(h + y, w + x))
                        return moves + 1;
                    
                    visited[mask] = true;
                    que.push(make_pair(moves + 1, temp));
                }
    }
    
    return -1;
}

inline static const Snake moveSnake(Snake snake, const int y, const int x)
{
    for(int s = end; s > 0; -- s)
        snake[s] = snake[s - 1];
    
    snake[0] = make_pair(y, x);
    return snake;
}

inline static const int makeMask(Snake snake)
{
    int mask = snake[0].first | (snake[0].second << 4),
        temp;
    for(int s = 1, m = 8; s < end; ++ s, m += 2)
    {
        temp = snake[s].first - snake[s - 1].first;
        if(temp)
        {
            if(temp > 0)
                continue;
            
            mask |= 1 << m;
        }
        
        else
        {
            temp = snake[s].second - snake[s - 1].second;
            if(temp > 0)
                mask |= 2 << m;
            
            else
                mask |= 3 << m;
        }
    }
        
    return mask;
}
