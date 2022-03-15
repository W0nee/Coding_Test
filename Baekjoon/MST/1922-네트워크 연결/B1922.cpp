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
int result;

void prim()
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	int visited[10010] = {0};
	
	for(int i = 0; i < graph[1].size(); i++)
	{
		int now = graph[1][i].first;
		int nowCost = graph[1][i].second;
		
		pq.push({nowCost, now});
		visited[1] = 1;
	}
	
	while(!pq.empty())
	{
		int now = pq.top().second;
		int nowCost = pq.top().first;
		pq.pop();
		
		if(visited[now] == 0)
		{
			visited[now] = 1;
			result += nowCost;
		}
		else
		{
			continue;
		}
		
		for(int i = 0; i < graph[now].size(); i++)
		{
			int next = graph[now][i].first;
			int nextCost = graph[now][i].second;
			
			if(visited[next] == 0)
			{
				pq.push({nextCost, next});
			}
		}
	}
}

int main(void)
{
//	freopen("B1922_input.txt", "r", stdin);
	
	cin >> V >> E;
	
	for(int i = 1; i <= E; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		
		graph[from].push_back({to, cost});
		graph[to].push_back({from, cost});
	}
	
	prim();
	
	cout << result;
	
	return 0;
}
