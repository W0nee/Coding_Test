#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct node
{
	int from;
	int to;
	int cost;
}node;

int V, E;
int parent[10010];
vector<node> graph;
int ans;

bool cmp(node a, node b)
{
	if(a.cost < b.cost)
	{
		return true;
	}
	
	return false;
}

int Find(int a)
{
	if(a == parent[a])
	{
		return a;
	}
	else
	{
		return parent[a] = Find(parent[a]);
	}
}

void Union(int a, int b)
{
	a = Find(a);
	b = Find(b);
	
	if(a != b)
	{
		if(a < b)
		{
			parent[b] = a;
		}
		else
		{
			parent[a] = b;
		}
	}
}

int main(void)
{
//	freopen("B1197_input.txt", "r", stdin);
	
	cin >> V >> E;
	
	for(int i = 1; i <= V; i++)
	{
		parent[i] = i;
	}
	
	for(int i = 1; i <= E; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		
		graph.push_back({from, to, cost});
	}
	
	sort(graph.begin(), graph.end(), cmp);
	
	for(int i = 0; i < graph.size(); i++)
	{
		if(Find(graph[i].from) != Find(graph[i].to))
		{
			Union(graph[i].from, graph[i].to);
			ans += graph[i].cost;
		}
	}
	
	cout << ans;
	
	return 0;
}
