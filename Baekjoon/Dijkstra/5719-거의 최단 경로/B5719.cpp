#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 987654321

int V, E;
int start, arrive;
vector<pair<int, int>> graph[550];
vector<pair<int, int>> trace[550];
int d[550];
int visited[550][550];

void dijkstra()
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	
	pq.push({0, start});
	d[start] = 0;
	
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
			
			if(visited[now][next] == -1)
			{
				continue;
			}
			
			if(d[now] + nextCost < d[next])
			{
				d[next] = d[now] + nextCost;
				pq.push({d[next], next});
				
				trace[next].clear();
				trace[next].push_back({now, nextCost});
			}
			else if(d[now] + nextCost == d[next])
			{
				trace[next].push_back({now, nextCost});
			}
		}
	}
}

void BFS()
{
	queue<int> q;
	
	q.push(arrive);
	
	while(!q.empty())
	{
		int now = q.front();
		q.pop();
		
		for(int i = 0; i < trace[now].size(); i++)
		{
			int next = trace[now][i].first;
			
			if(visited[next][now] == 0)
			{
				q.push(next);
				visited[next][now] = -1;	
			}
		}
	}
}

int main(void)
{
	freopen("B5719_input.txt", "r", stdin);

	while(1)
	{		
		cin >> V >> E;
		
		if(V == 0 && E == 0)
		{
			break;
		}
		else
		{
			cin >> start >> arrive;
		}
		
		for(int i = 0; i <= V-1; i++)
		{
			graph[i].clear();
			trace[i].clear();
			d[i] = INF;
			memset(visited, 0, sizeof(visited));
		}
	
		for(int i = 1; i <= E; i++)
		{
			int from, to, cost;
			cin >> from >> to >> cost;
			
			graph[from].push_back({to, cost});
		}
		
		dijkstra();	
		
		BFS();
		
		for(int i = 0; i <= V-1; i++)
		{
			d[i] = INF;
		}
		
		dijkstra();	
		
		int result = d[arrive] == INF ? -1 : d[arrive];
		cout << result << "\n";
	}
	
	return 0;
}
