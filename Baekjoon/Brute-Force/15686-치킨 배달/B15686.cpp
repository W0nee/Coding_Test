#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int Map[55][55];
int N, M;
int Min = 987654321;
vector<pair<int, int>> chicken;
vector<pair<int, int>> house;
vector<pair<int, int>> list;

int cal()
{
	int sum = 0;
	
	for(int i = 0; i < house.size(); i++)
	{
		int Min = 987654321;
		
		for(int j = 0; j < list.size(); j++)
		{
			Min = min(Min, abs(house[i].first-list[j].first) + abs(house[i].second-list[j].second));
		}
		
		sum += Min;
	}
	
	return sum;
}

void DFS(int idx, int cnt) 
{	
	if(cnt == M)
	{
		Min = min(Min, cal());
		return;
	}
	
	for(int i = idx; i < chicken.size(); i++)
	{
		list.push_back({chicken[i].first, chicken[i].second});
		DFS(i+1, cnt+1);
		list.pop_back();
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
	
	DFS(0, 0);
	
	cout << Min;
	
	return 0;
}
