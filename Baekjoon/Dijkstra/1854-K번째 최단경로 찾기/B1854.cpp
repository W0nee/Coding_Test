#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

int V, E, K;
vector<pair<int, int>> graph[1010];
priority_queue<int, vector<int>, less<int>> list[1010];

void dijkstra()
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	
	pq.push({0, 1});
	list[1].push(0);
	
	while(!pq.empty())
	{
		int now = pq.top().second;
		int nowCost = pq.top().first;
		pq.pop();
		
		for(int i = 0; i < graph[now].size(); i++)
		{
			int next = graph[now][i].first;
			int nextCost = graph[now][i].second;
			
			if(list[next].size() < K)
			{
				list[next].push(nowCost + nextCost);
				pq.push({nowCost + nextCost, next});
			}
			else
			{
				if(list[next].top() > nowCost + nextCost)
				{
					list[next].pop();
					list[next].push(nowCost + nextCost);
					pq.push({nowCost + nextCost, next});
				}
			}	
		}
	}
}

int main(void)
{
//	freopen("B1854_input.txt", "r", stdin);
	
	cin >> V >> E >> K;

	for(int i = 1; i <= E; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		
		graph[from].push_back({to, cost});
	}
	
	dijkstra();
	
	for(int i = 1; i <= V; i++)
	{
		if(list[i].size() < K)
		{
			cout << "-1\n";
		}
		else
		{
			cout << list[i].top() << "\n";
		}
	}
	
	return 0;
}
