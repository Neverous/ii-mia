/* 2012
 * Maciej Szeptuch
 * II UWr
 */
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>

int verts,
	edges,
	temp,
	tA, tB,
	diff, added,
	repr[65536];
unsigned int results = 1;
long long int length;
std::pair<long long int, std::pair<int, int> > edge[131072];
std::set<std::pair<int, int> > values;

inline static const int unionFind(const int &v);
inline static const bool unionUnion(const int &a, const int &b);

int main(void)
{
	scanf("%d %d", &verts, &edges);
	for(int v = 0; v <= verts; ++ v)
		repr[v] = v;

	for(int e = 0; e < edges; ++ e)
	{
		scanf("%d %d %lld", &edge[e].second.first, &edge[e].second.second, &edge[e].first);
		if(edge[e].second.second < edge[e].second.first)
		{
			temp = edge[e].second.second;
			edge[e].second.second = edge[e].second.first;
			edge[e].second.first = temp;
		}
	}

	std::sort(edge, edge + edges);
	for(int e = 0, same = 1; e < edges; e += same, same = 1)
	{
		values.clear();
		added = 0; diff = 0;
		while(e + same < edges && edge[e].first == edge[e + same].first) ++ same;
		for(int c = 0; c < same; ++ c)
		{
			tA = unionFind(edge[e + c].second.first);
			tB = unionFind(edge[e + c].second.second);
			if(tA != tB)
			{
				if(tA < tB)
					values.insert(std::make_pair(tA, tB));

				else
					values.insert(std::make_pair(tB, tA));

				++ diff;
			}
		}

		for(int c = 0; c < same; ++ c)
			if(unionUnion(edge[e + c].second.first, edge[e + c].second.second))
			{
				++ added;
				length += edge[e + c].first;
			}

		if(diff == 2 && added == 1)
			results = (results * 2) % 1000000007;

		else if(diff == 3)
		{
			if(added == 1 || (added == 2 && values.size() == 3))
				results = (results * 3) % 1000000007;

			else if(added == 2 && values.size() == 2)
				results  = (results * 2) % 1000000007;
		}
	}

	printf("%lld %d\n", length, results);
	return 0;
}

inline static const int unionFind(const int &v)
{
	if(repr[v] == v)
		return v;

	return repr[v] = unionFind(repr[v]);
}

inline static const bool unionUnion(const int &a, const int &b)
{
	int fA = unionFind(a),
		fB = unionFind(b);

	if(fA == fB)
		return false;

	if(fA < fB)
		repr[fB] = fA;

	else
		repr[fA] = fB;

	return true;
}
