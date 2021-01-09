#include <iostream>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <string>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int Map[55][55];
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;
vector<pair<int, int>> candidate;
int Min = 99999999;

void combination(int idx, int cnt)
{
	if(cnt == M)
	{
		int result = 0;
		for(int i = 0; i < house.size(); i++)
		{
			int dist = 99999999;
			for(int j = 0; j < candidate.size(); j++)
			{
				dist = min(dist, abs(house[i].first - candidate[j].first) + abs(house[i].second - candidate[j].second));
			}
			
			result += dist;
		}
		
		Min = min(Min, result);
		
		return;
	}
	
	for(int i = idx; i < chicken.size(); i++)
	{
		candidate.push_back(chicken[i]);
		combination(i+1, cnt+1);
		candidate.pop_back();
	}
}

int main(void)
{
//	freopen("B15686_input.txt", "r", stdin);
	
	cin >> N >> M;
	
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			cin >> Map[i][j];
			
			if(Map[i][j] == 1)
			{
				house.push_back({i, j});
			}
			else if(Map[i][j] == 2)
			{
				chicken.push_back({i, j});
			}
		}
	}
	
	combination(0, 0);
	
	cout << Min;
	
	return 0;
}
