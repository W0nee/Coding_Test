#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 987654321

int V, E;
int start;
vector<pair<int, int>> graph[20010];
int result[20010];

void dijkstra()
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	int visited[20010] = {0};
	
	pq.push({0, start});
	result[start] = 0;
	
	while(!pq.empty())
	{
		int now = pq.top().second;
		int nowCost = pq.top().first;
		pq.pop();
		
		if(result[now] != nowCost)
		{
			continue;
		}
		
		for(int i = 0; i < graph[now].size(); i++)
		{
			int next = graph[now][i].first;
			int nextCost = graph[now][i].second;
			
			if(result[now] + nextCost < result[next])
			{
				result[next] = result[now] + nextCost;
				pq.push({result[next], next});
			}
		}
	}
}

int main(void)
{
//	freopen("B1735_input.txt", "r", stdin);
	
	cin >> V >> E >> start;
	
	for(int i = 1; i <= E; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		
		graph[from].push_back({to, cost});
	}
	
	for(int i = 1; i <= V; i++)
	{
		result[i] = INF;
	}
	
	dijkstra();
	
	for(int i = 1; i <= V; i++)
	{
		if(result[i] == INF)
		{
			cout << "INF\n";
		}
		else
		{
			cout << result[i] << "\n";
		}
	}
	
	return 0;
}
