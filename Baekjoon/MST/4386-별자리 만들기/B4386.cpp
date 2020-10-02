#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

typedef struct node 
{
	int from;
	int to;
	long double cost;
}node;

int N;
int parent[110];
vector<pair<long double, long double>> star;
vector<node> graph;
double ans;

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
//	freopen("B4386_input.txt", "r", stdin);
	
	cin >> N;
	
	for(int i = 1; i <= N; i++)
	{
		parent[i] = i;
	}
	
	for(int i = 0; i < N; i++)
	{
		double x, y;
		cin >> x >> y;
		
		star.push_back({x, y});
	}
	
	for(int i = 0; i < N; i++)
	{
		for(int j = i+1; j < N; j++)
		{
			long double dist = sqrt((pow(star[i].first - star[j].first, 2.0) + pow(star[i].second - star[j].second, 2.0)));
			graph.push_back({i+1, j+1, dist});
		}
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
	
	cout << fixed;
	cout.precision(2);
	cout << ans;
	
	return 0;
}
