/* 2015
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

int height,
    width,
    components,
    map[512][512];
bool visited[512];
char row[512];
std::vector<int> graph[512];

template<typename Type>
void filter_unique(Type container, bool already_sorted = false);

void mark_component(int x, int y, int id);
void merge_components(void);
int longest_path(int start);
int find_radius(void);

int main(void)
{
    scanf("%d %d", &height, &width);
    for(int h = 0; h < height; ++ h)
    {
        scanf("%s", row);
        for(int w = 0; w < width; ++ w)
            map[h][w] = row[w] == 'X';
    }

    merge_components();
    printf("%d\n", find_radius());
    return 0;
}

template<typename Type>
inline
void filter_unique(Type container, bool already_sorted)
{
    if(!already_sorted)
        std::sort(container.begin(), container.end());

    container.erase(std::unique(container.begin(), container.end()), container.end());
}

inline
void mark_component(int x, int y, int id)
{
    int color = map[y][x];
    map[y][x] = id + 2;
    for(int dy = -1; dy < 2; ++ dy)
        for(int dx = dy ? 0 : -1; dx < 2; dx += 2)
            if( 0 <= y + dy && y + dy < height
            &&  0 <= x + dx && x + dx < width)
            {
                if(map[y + dy][x + dx] == color)
                    mark_component(x + dx, y + dy, id);

                else if(map[y + dy][x + dx] != map[y][x] && map[y + dy][x + dx] >= 2)
                {
                    graph[id].push_back(map[y + dy][x + dx] - 2);
                    graph[map[y + dy][x + dx] - 2].push_back(id);
                }
            }
}

inline
void merge_components(void)
{
    for(int h = 0; h < height; ++ h)
        for(int w = 0; w < width; ++ w)
            if(map[h][w] < 2)
                mark_component(w, h, components ++);

    for(int c = 0; c < components; ++ c)
        filter_unique(graph[c]);

}

inline
int longest_path(int start)
{
    int length[512] = {};
    int last = length[start] = -1;
    std::queue<int> que;
    que.push(start);
    while(!que.empty())
    {
        int act = que.front();
        que.pop();

        for(unsigned int n = 0; n < graph[act].size(); ++ n)
            if(length[graph[act][n]] == 0)
            {
                last = length[graph[act][n]] = length[act] - 1;
                que.push(graph[act][n]);
            }
    }

    return -last - 1;
}

inline
int find_radius(void)
{
    int result = components;
    for(int c = 0; c < components; ++ c)
        {
            int length = longest_path(c);
            if(length < result)
                result = length;
        }

    return result;
}
