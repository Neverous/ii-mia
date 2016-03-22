/* 2011
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
//#define DEBUG(args...) fprintf(stderr, args)
#define DEBUG(args...)

int result[2][1024],
	places,
	people;
inline static const int $(const int &val){return val > 1000000003?val % 1000000003:val;}

int main(void)
{
	scanf("%d %d", &places, &people);
	for(int p = 1; p <= places; ++ p)
		result[0][p] = result[0][p - 1] + 1;

	for(int pp = 1; pp < people; ++ pp)
	{
		result[pp & 1][2 * pp - 1] = 0;
		for(int p = 2 * pp; p < places; ++ p)
			result[pp & 1][p] = $(result[pp & 1][p - 1] + result[(pp - 1) & 1][p - 2]);

		result[pp & 1][places] = $(result[pp & 1][places - 1] + result[(pp - 1) & 1][places - 3]);
	}

	printf("%d\n", result[(people - 1) & 1][places]);
	return 0;
}
