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
		int to = graph[1][i].first;
		int cost = graph[1][i].second;
		
		pq.push({cost, to});
		visited[1] = 1;
	}
	
	while(!pq.empty())
	{
		int from = pq.top().second;
		int cost = pq.top().first;
		pq.pop();
		
		if(visited[from] == 0)
		{
			visited[from] = 1;
			result += cost;
		}
		else
		{
			continue;
		}
		
		for(int i = 0; i < graph[from].size(); i++)
		{
			int to = graph[from][i].first;
			int cost = graph[from][i].second;
			
			if(visited[to] == 0)
			{
				pq.push({cost, to});	
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
		
		graph[from].push_back({to, cost});
		graph[to].push_back({from, cost});
	}
	
	prim();
	
	cout << result;
	
	return 0;
}
