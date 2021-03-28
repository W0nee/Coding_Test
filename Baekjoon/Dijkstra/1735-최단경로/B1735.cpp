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
int d[20010];

void dijkstra(int x)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	
	pq.push({0, x});
	d[x] = 0;
	
	while(!pq.empty())
	{
		int now = pq.top().second;
		int nowCost = pq.top().first;
		pq.pop();
		
		if(d[now] != nowCost)
		{
			continue;
		}
		
		for(int i = 0; i < graph[now].size(); i++)
		{
			int next = graph[now][i].first;
			int nextCost = graph[now][i].second;
			
			if(d[now] + nextCost < d[next])
			{
				d[next] = d[now] + nextCost;
				pq.push({d[next], next});
			}
		}
	}
}

int main(void)
{
//	freopen("B1197_input.txt", "r", stdin);
	
	cin >> V >> E >> start;
	
	for(int i = 1; i <= V; i++)
	{
		d[i] = INF;
	}
	
	for(int i = 1; i <= E; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		
		graph[from].push_back({to, cost});
	}
	
	dijkstra(start);
	
	for(int i = 1; i <= V; i++)
	{
		if(d[i] == INF)
		{
			cout << "INF\n";
		}
		else
		{
			cout << d[i] << "\n";
		}
	}
	
	return 0;
}
