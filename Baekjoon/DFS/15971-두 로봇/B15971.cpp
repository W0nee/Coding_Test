#include <stdio.h>
#include <iostream>
#include <queue>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;

int N, r1, r2;
vector<pair<int, int>> graph[100010];
int d1[100010];
int d2[100010];
int visited[100010];
bool Flag = false;
int deep;
int Min = 999999999;

void DFS1(int x, int cnt)
{
	if(x == r2)
	{
		deep = cnt-1;
		Flag = true;
		return;
	}
	
	for(int i = 0; i < graph[x].size(); i++)
	{
		if(visited[graph[x][i].first] == 0)
		{
			visited[graph[x][i].first] = 1;
			d1[cnt] = d1[cnt-1] + graph[x][i].second;
			DFS1(graph[x][i].first, cnt+1);
			
			if(Flag)
			{
				return;
			}	
		}	
	}
}

void DFS2(int x, int cnt)
{
	if(x == r1)
	{
		Flag = true;
		return;
	}
	
	for(int i = 0; i < graph[x].size(); i++)
	{
		if(visited[graph[x][i].first] == 0)
		{
			visited[graph[x][i].first] = 1;
			d2[cnt] = d2[cnt-1] + graph[x][i].second;
			DFS2(graph[x][i].first, cnt+1);
			
			if(Flag)
			{
				return;
			}	
		}	
	}
}

int main(void)
{
//	freopen("B15971_input.txt", "r", stdin);
	
	cin >> N >> r1 >> r2;
	
	for(int i = 1; i <= N-1; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		
		graph[from].push_back({to, cost});
		graph[to].push_back({from, cost});
	}
	
	if(r1 == r2)
	{
		cout << 0;
		return 0;
	}
	
	visited[r1] = 1;
	DFS1(r1, 1);
	
	memset(visited, 0, sizeof(visited));
	Flag = false;
	
	visited[r2] = 1;
	DFS2(r2, 1);
	
	for(int i = 0; i <= deep-1; i++)
	{
		Min = min(Min, d1[i] + d2[deep-i-1]);
	}
	
	cout << Min;
	return 0;
}
