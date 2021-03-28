#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int V, E;
vector<pair<int, int>> graph[10010];
int visited[10010];
int ans;

void prim(int x)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	
	for(int i = 0; i < graph[x].size(); i++)
	{
		int next = graph[x][i].second;
		int nextCost = graph[x][i].first;
		
		pq.push({nextCost, next});
	}
	visited[x] = 1;
	
	while(!pq.empty())
	{
		int now = pq.top().second;
		int nowCost = pq.top().first;
		pq.pop();
		
		if(visited[now] == 1)
		{
			continue;
		}
		
		visited[now] = 1;
		ans += nowCost;
		
		for(int i = 0; i < graph[now].size(); i++)
		{
			int next = graph[now][i].second;
			int nextCost = graph[now][i].first;
			
			if(visited[next] == 0)
			{
				pq.push({nextCost, next});
			}
		}
	}
}

int main(void)
{
//	freopen("B1197_input.txt", "r", stdin);
	
	cin >> V >> E;
	
	for(int i = 1; i <= E; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		
		graph[from].push_back({cost, to});
		graph[to].push_back({cost, from});
	}
	
	prim(1);
	
	cout << ans;
	
	return 0;
}
