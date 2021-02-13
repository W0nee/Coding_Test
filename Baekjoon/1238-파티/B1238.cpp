#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <math.h>
#include <map>
#include <queue>
#include <vector>
using namespace std;

#define INF 987654321;

int N, M, X;
vector<pair<int, int>> graph[1010];
int Max;

int dijkstra(int start, int arrive)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	int d[N+1];
	
	for(int i = 1; i <= N; i++)
	{
		d[i] = INF;
	}
	
	d[start] = 0;	
	pq.push({d[start], start});
	
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
			
			if(d[next] > nowCost + nextCost)
			{
				d[next] = nowCost + nextCost;
				pq.push({d[next], next});
			}
		}
	}
	
	return d[arrive];
}

int main(void)
{
//	freopen("B1238_input.txt", "r", stdin);
	
	cin >> N >> M >> X;
	
	for(int i = 1; i <= M; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		
		graph[from].push_back({to, cost});
	}
	
	for(int i = 1; i <= N; i++)
	{
		Max = max(Max, dijkstra(i, X) + dijkstra(X, i));
	}
	
	cout << Max;
	
	return 0;
}
