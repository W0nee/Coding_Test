#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 1e8

typedef struct node
{
	int from;
	int to;
	int cost;
}node;

int N, M, start, arrive;
int cityCost[110];
vector<node> graph;
long long d[110];
bool cycle = false;

int canGo(int x)
{
	queue<int> q;
	int visited[110] = {0};
	
	q.push(x);
	visited[x] = 1;
	
	while(!q.empty())
	{
		x = q.front();
		q.pop();
		
		if(x == arrive)
		{
			return 1;
		}
		
		for(int i = 0; i < graph.size(); i++)
		{
			if(graph[i].from == x && visited[graph[i].to] == 0)
			{
				q.push(graph[i].to);
				visited[graph[i].to] = 1;
			}
		}
	}
	
	return 0;
}

void bellman()
{
//	if(canGo(start) == 0)
//	{
//		cout << "gg";
//		return;
//	}
	
	d[start] = cityCost[start];
	
	for(int k = 1; k < N; k++)
	{
		for(int i = 0; i < graph.size(); i++)
		{
			int from = graph[i].from;
			int to = graph[i].to;
			int cost = graph[i].cost;
			
			if(d[from] == -INF)
			{
				continue;
			}
			
			if(d[to] < d[from] + cost)
			{
				d[to] = d[from] + cost;
			}
		}
	}
	
	for(int i = 0; i < graph.size(); i++)
	{
		int from = graph[i].from;
		int to = graph[i].to;
		int cost = graph[i].cost;
		
		if(d[from] == -INF)
		{
			continue;
		}
		
		if(d[to] < d[from] + cost)
		{
			// 양수사이클 
			if(canGo(from))
			{
				cycle = true;
				return;
//				cout << "Gee";
//				return;
			}
		}
	} 
	
//	cout << d[arrive];
//	return;
}

int main(void)
{
//	freopen("B1219_input.txt", "r", stdin);
	
	cin >> N >> start >> arrive >> M;
	
	vector<node> list;
	for(int i = 0; i < M; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		
		list.push_back({from, to, cost});
	}
	
	for(int i = 0; i < N; i++)
	{
		int cost;
		cin >> cityCost[i];
		
		d[i] = -INF;
	}
	
	for(int i = 0; i < list.size(); i++)
	{
		graph.push_back({list[i].from, list[i].to, cityCost[list[i].to] - list[i].cost});	
	}
	
	bellman();
	
	if(d[arrive] == -INF)
	{
		cout << "gg";
	}
	else if(cycle)
	{
		cout << "Gee";
	}
	else
	{
		cout << d[arrive];
	}
	
	return 0;
}
