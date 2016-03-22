/* 2014
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>

int items,
    drawers,
    A, B,
    repr[524288],
    free_[524288];

void findUnion(int a, int b);
int find(int a);

int main(void)
{
    scanf("%d %d", &items, &drawers);
    for(int i = 0; i < drawers; ++ i)
    {
        repr[i] = i;
        free_[i] = 1;
    }

    for(int i = 0; i < items; ++ i)
    {
        scanf("%d %d", &A, &B);
        -- A;
        -- B;

        if(free_[A])
        {
            -- free_[A];
            puts("LADICA");
        }

        else if(free_[B])
        {
            -- free_[B];
            puts("LADICA");
        }

        else if(free_[find(A)])
        {
            -- free_[find(A)];
            puts("LADICA");
        }

        else if(free_[find(B)])
        {
            -- free_[find(B)];
            puts("LADICA");
        }

        else
            puts("SMECE");

        findUnion(A, B);
    }

    return 0;
}

inline
void findUnion(int a, int b)
{
    int fa = find(a),
        fb = find(b);

    if(fa == fb)
        return;

    if(free_[fa] > free_[fb])
    {
        repr[fb] = fa;
        free_[fa] += free_[fb];
    }

    else
    {
        repr[fa] = fb;
        free_[fb] += free_[fa];
    }
}

inline
int find(int a)
{
    if(repr[a] == a)
        return a;

    return repr[a] = find(repr[a]);
}
