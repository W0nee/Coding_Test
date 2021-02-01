#include <stdio.h>
#include <iostream>
#include <queue>
#include <math.h>
#include <algorithm>
using namespace std;

int N, E;
vector<pair<int, int>> graph[810];
int d[810];
int pass1, pass2;
int result[810][810];
int Min;

void dijkstra(int start)
{
	for(int i = 1; i <= N; i++)
	{
		d[i] = 99999999;
	}
	
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	d[start] = 0;
	pq.push({0, start});
	
	while(!pq.empty())
	{
		int now = pq.top().second;
		int nowCost = pq.top().first;
		pq.pop();
		
		if(d[now] < nowCost)
		{
			continue;
		}
		
		for(int i = 0; i < graph[now].size(); i++)
		{
			int next = graph[now][i].first;
			int nextCost = graph[now][i].second;
			
			if(nowCost + nextCost < d[next])
			{
				d[next] = nowCost + nextCost;
				pq.push({d[next], next});
			}
		}
	}
}

int main(void)
{
//	freopen("B1504_input.txt", "r", stdin);
	
	cin >> N >> E;
	
	for(int i = 1; i <= E; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		
		graph[from].push_back({to, cost});
		graph[to].push_back({from, cost});
	}
	
	cin >> pass1 >> pass2;
	
	dijkstra(1);
	result[1][pass1] = d[pass1];
	result[1][pass2] = d[pass2];
	
	dijkstra(pass1);
	result[pass1][pass2] = d[pass2];
	result[pass1][N] = d[N];
	
	dijkstra(pass2);
	result[pass2][pass1] = d[pass1];
	result[pass2][N] = d[N];
	
	Min = min(result[1][pass1] + result[pass1][pass2] + result[pass2][N], result[1][pass2] + result[pass2][pass1] + result[pass1][N]);
	
	if(Min >= 99999999)
	{
		cout << "-1";
	}
	else
	{
		cout << Min;
	}
	
	return 0;
}
