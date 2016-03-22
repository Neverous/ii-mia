/* 2012
 * Maciej Szeptuch
 * II UWr
 */
#include<cstdio>
#include<cmath>

int cities,
	travellers,
	number,
	result[1048576];

int main(void)
{
	scanf("%d %d", &cities, &travellers);
	for(int t = 0; t < travellers; ++ t)
	{
		scanf("%d", &number);
		result[number] += (int)sqrt(number) == number / sqrt(number);
	}

	for(int c = 1; c <= cities; ++ c)
		if(result[c])
			printf("%d %d\n", c, result[c]);

	return 0;
}
