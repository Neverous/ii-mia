/* 2011
 * Maciej Szeptuch
 * II UWr
 */
#include<cstdio>
#include<algorithm>
#include<vector>
//#define DEBUG(args...) fprintf(stderr, args)
#define DEBUG(args...)

long long int elements,
	maxWeight,
	seq[32],
	sum,
	result;

std::vector<long long int> sums[2];

int main(void)
{
	scanf("%lld %lld", &elements, &maxWeight);
	for(int s = 0; s < elements; ++ s)
		scanf("%lld", &seq[s]);

	for(int m = 0; m < (1 << (elements / 2)); ++ m)
	{
		sum = 0;
		for(int p = 0; p < elements / 2; ++ p)
			if((1 << p) & m)
				sum += seq[p];

		if(sum <= maxWeight)
			sums[0].push_back(sum);
	}

	for(int m = 0; m < (1 << ((elements + 1) / 2)); ++ m)
	{
		sum = 0;
		for(int p = 0; p < (elements + 1) / 2; ++ p)
			if((1 << p) & m)
				sum += seq[p + elements / 2];

		if(sum <= maxWeight)
			sums[1].push_back(sum);
	}

	std::sort(sums[0].begin(), sums[0].end());
	std::sort(sums[1].begin(), sums[1].end());
	for(int n = 0, m = sums[1].size() - 1; n < sums[0].size(); ++ n)
	{
		while(sums[1][m] + sums[0][n] > maxWeight)
			-- m;

		result += m + 1;
	}
		
	printf("%lld\n", result);
	return 0;
}
