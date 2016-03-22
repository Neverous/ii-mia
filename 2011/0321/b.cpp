/* 2012
 * Maciej Szeptuch
 * II UWr
 */
#include<cstdio>
#include<queue>
#include<vector>

int sequences,
	length,
	before, now,
	act,
	in[16384];
bool was[16384];
std::priority_queue<int> que;
std::vector<int> graph[16384];

int main(void)
{
	scanf("%d", &sequences);
	for(int s = 0; s < sequences; ++ s)
	{
		scanf("%d %d", &length, &before);
		was[before] = true;
		for(int l = 1; l < length; ++ l)
		{
			scanf("%d", &now);
			++ in[now];
			was[now] = true;
			graph[before].push_back(now);
			before = now;
		}
	}

	for(int v = 1; v <= 10000; ++ v)
		if(was[v] && !in[v])
		{
			que.push(-v);
			was[v] = false;
		}

	while(!que.empty())
	{
		act = -que.top();
		que.pop();
		printf("%d ", act);
		for(int n = 0; n < graph[act].size(); ++ n)
			if(was[graph[act][n]] && !(-- in[graph[act][n]]))
			{
				was[graph[act][n]] = false;
				que.push(-graph[act][n]);
			}
	}

	puts("");
	return 0;
}
