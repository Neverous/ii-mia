/* 2011
 * Maciej Szeptuch
 * II UWr
 */
#include<cstdio>
#include<vector>
#include<algorithm>
//#define DEBUG(args...) fprintf(stderr, args)
#define DEBUG(args...)

int verts,
	connection,
	count[1024],
	vert[1024];

inline static const bool compare(const int &a, const int &b);

int main(void)
{
	scanf("%d", &verts);
	for(int v = 0; v < verts; ++ v)
	{
		vert[v] = v;
		for(int n = 0; n < verts; ++ n)
		{
			scanf("%d", &connection);
			count[v] += connection;
		}
	}

	std::sort(vert, vert + verts, compare);
	for(int v = 0; v < verts; ++ v)
		printf("%d ", vert[v] + 1);

	return 0;
}

inline static const bool compare(const int &a, const int &b)
{
	if(count[a] > count[b])
		return true;

	if(count[a] < count[b])
		return false;

	return a < b;
}
