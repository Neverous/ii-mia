/* 2012
 * Maciej Szeptuch
 * II UWr
 */
#include<cstdio>
#include<cstring>

const int MOD = 1000000007;

long long int power;
int bricks,
	size;
long long int matrix[15][15];
inline static void empower(long long int M[15][15], long long int pow);
inline static void multiply(long long int R[15][15], long long int M[15][15]);
inline static void DBG(long long int M[15][15])
{
	for(int i = 0; i < 15; ++ i)
	{
		for(int j = 0; j < 15; ++ j)
			printf("%lld ", M[i][j]);

		puts("");
	}

	puts("--");
}

int main(void)
{
	scanf("%lld %d", &power, &bricks);
	for(int i = 1; i < 15; ++ i)
		matrix[i][i-1] = 1;

	for(int b = 0; b < bricks; ++ b)
	{
		scanf("%d", &size);
		matrix[0][size - 1] = 1;
	}

	empower(matrix, power);
	printf("%lld\n", (matrix[0][0] * 2) % MOD);
}

inline static void empower(long long int M[15][15], long long int pow)
{
	if(pow == 1)
		return;

	long long int T[15][15] = {};
	if(!pow)
		for(int i = 0; i < 15; ++ i)
			T[i][i] = 1;

	else
	{
		memcpy(T, M, sizeof(T));
		empower(T, pow / 2);
		multiply(T, T);
		if(pow % 2)
			multiply(T, M);
	}

	memcpy(M, T, sizeof(T));
	return;
}

inline static void multiply(long long int R[15][15], long long int M[15][15])
{
	long long int T[15][15] = {};
	for(int i = 0; i < 15; ++ i)
		for(int j = 0; j < 15; ++ j)
		{
			for(int c = 0; c < 15; ++ c)
				T[i][j] += R[i][c] * M[c][j];

			if(T[i][j] >= MOD)
				T[i][j] %= MOD;
		}

	memcpy(R, T, sizeof(T));
	return;
}
