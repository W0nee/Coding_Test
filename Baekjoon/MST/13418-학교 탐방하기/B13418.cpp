#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

typedef struct node
{
	int from;
	int to;
	int cost;	
}node;

int N, M;
vector<node> graph;
int parent[1010];
int Max, Min;

bool cmp1(node a, node b)
{
	if(a.cost < b.cost)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool cmp2(node a, node b)
{
	if(a.cost > b.cost)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int Find(int a)
{
	if(parent[a] == a)
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
	a = Find(parent[a]);
	b = Find(parent[b]);
	
	if(a < b)
	{
		parent[b] = a;
	}
	else if(a > b)
	{
		parent[a] = b;
	}
}

int main(void)
{
//	freopen("B13418_input.txt", "r", stdin);
	
	cin >> N >> M;
	
	for(int i = 0; i <= N; i++)
	{
		parent[i] = i;
	}
	
	for(int i = 0; i <= M; i++)
	{	
		int from, to, cost;
		cin >> from >> to >> cost;
		
		if(cost == 0) cost = 1;
		else if(cost == 1) cost = 0;
		
		graph.push_back({from, to, cost});
	}
	
	sort(graph.begin(), graph.end(), cmp1);
	for(int i = 0; i <= M; i++)
	{
		if(Find(graph[i].from) != Find(graph[i].to))
		{
			Union(graph[i].from, graph[i].to);
			Min += graph[i].cost;
		}
	}
	
//	cout << Min << endl;
	
	for(int i = 0; i <= N; i++)
	{
		parent[i] = i;
	}
	
	sort(graph.begin(), graph.end(), cmp2);
	for(int i = 0; i <= M; i++)
	{
		if(Find(graph[i].from) != Find(graph[i].to))
		{
			Union(graph[i].from, graph[i].to);
			Max += graph[i].cost;
		}
	}

//	cout << Max << endl;
	
	cout << Max*Max - Min*Min;
	
	return 0;
}
