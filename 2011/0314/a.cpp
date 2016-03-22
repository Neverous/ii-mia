/* 2012
 * Maciej Szeptuch
 * II UWr
 */
#include<cstdio>

int count,
	cows,
	weight[32],
	speedup[(1<< 20)],
	lastcow,
	ct,
	best;

inline static const bool noCarry(int a, int b);
inline static const int MAX(const int &a, const int &b){return a>b?a:b;}

int main(void)
{
	scanf("%d", &cows);
	for(int c = 0; c < cows; ++ c)
	{
		scanf("%d", &weight[c]);
		speedup[(1 << c)] = weight[c];
	}

	for(int m = 1; m < (1 << cows); ++ m)
	{
		lastcow = 31 - __builtin_clz(m);
		if(speedup[m & ~(1 << lastcow)] == -1)
		{
			speedup[m] = -1;
			continue;
		}

		if(noCarry(speedup[m & ~(1 << lastcow)], weight[lastcow]))
		{
			speedup[m] = speedup[m & ~(1 << lastcow)] + weight[lastcow];
			best = MAX(best, __builtin_popcount(m));
		}

		else
			speedup[m] = -1;
	}

	printf("%d\n", best);
	return 0;
}

inline static const bool noCarry(int a, int b)
{
	while(a && b)
	{
		if(a % 10 + b % 10 >= 10)
			return false;

		a /= 10;
		b /= 10;
	}

	return true;
}
