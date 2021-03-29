#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 987654321

int N, M;
int start, arrive;
vector<pair<int, int>> graph[1010];
int d[1010];
int track[1010];
vector<int> list;

void tracking(int x)
{
	if(x == start)
	{
		list.push_back(x);
		return;
	}
	
	tracking(track[x]);
	list.push_back(x);
}

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
				
				track[next] = now;
			}
		}
	}
}

int main(void)
{
//	freopen("B11779_input.txt", "r", stdin);
	
	cin >> N >> M;
	
	for(int i = 1; i <= N; i++)
	{
		d[i] = INF;
	}
	
	for(int i = 1; i <= M; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		
		graph[from].push_back({to, cost});
	}
	
	cin >> start >> arrive;
	
	dijkstra(start);
	tracking(arrive);
	
	cout << d[arrive] << "\n";
	cout << (int)list.size() << "\n";
	for(int i = 0; i < list.size(); i++)
	{
		cout << list[i] << " ";
	}
	
	return 0;
}
