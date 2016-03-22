/* 2012
 * Maciej Szeptuch
 * II UWr
 */
#include<cstdio>

int players,
	games,
	game,
	result[4],
	sum,
	best,
	min;

inline static const int MAX(const int &a, const int &b){return a>b?a:b;}

int main(void)
{
	scanf("%d %d", &players, &games);
	for(int p = 0; p < players; ++ p)
	{
		sum = 0;
		min = 0;
		result[p] = 0;
		for(int g = 0; g < games; ++ g)
		{
			scanf("%d", &game);
			sum += game;
			result[p] = MAX(result[p], sum - min);
			if(sum < min)
				min = sum;
		}
	}

	for(int p = 0; p < players; ++ p)
		if(result[p] > result[best])
			best = p;

	printf("%d %d\n", best + 1, result[best]);
}
