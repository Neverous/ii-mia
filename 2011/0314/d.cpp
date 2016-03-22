/* 2012
 * Maciej Szeptuch
 * II UWr
 */
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>

int points,
	result,
	mainX, mainY,
	x, y;

std::vector<std::pair<int, int> > point[4];
std::set<int> pigeons;
std::set<int>::iterator pigeon;

int main(void)
{
	scanf("%d", &points);
	scanf("%d %d", &mainX, &mainY);
	for(int p = 0; p < points; ++ p)
	{
		scanf("%d %d", &x, &y);
		if(x > mainX)
		{
			if(y > mainY) point[0].push_back(std::make_pair(x - mainX, y - mainY));
			else point[1].push_back(std::make_pair(x - mainX, mainY - y));
		}

		else
		{
			if(y > mainY) point[2].push_back(std::make_pair(mainX - x, y - mainY));
			else point[3].push_back(std::make_pair(mainX - x, mainY - y));
		}
	}

	for(int c = 0; c < 4; ++ c)
	{
		pigeons.clear();
		std::sort(point[c].begin(), point[c].end());
		for(unsigned int p = 0; p < point[c].size(); ++ p)
		{
			pigeon = pigeons.lower_bound(-point[c][p].second);
			if(pigeon != pigeons.end())
				pigeons.erase(pigeon);
			
			pigeons.insert(-point[c][p].second);
		}

		result += pigeons.size();
	}

	printf("%d\n", result);
	return 0;
}
