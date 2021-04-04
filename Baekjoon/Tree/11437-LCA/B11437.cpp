#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int parent[50010];
int order[50010];
int visited[50010];
vector<int> graph[50010];

int LCA(int a, int b)
{
	int r1 = order[a];
	int r2 = order[b];
	
	while(r1 > r2)
	{
		a = parent[a];
		r1 = order[a];
	}
	
	while(r2 > r1)
	{
		b = parent[b];
		r2 = order[b];
	}
	
	while(a != b)
	{
		a = parent[a];
		b = parent[b];
	}
	
	return a;
}

void DFS(int x, int cnt)
{
	order[x] = cnt;
	
	for(int i = 0; i < graph[x].size(); i++)
	{
		if(visited[graph[x][i]]  == 0)
		{
			visited[graph[x][i]] = 1;
			
			parent[graph[x][i]] = x;
			DFS(graph[x][i], cnt+1);	
		}
	}
}

int main(void)
{
//	freopen("B11437_input.txt", "r", stdin);
	
	cin >> N;
	
	for(int i = 1; i <= N-1; i++)
	{
		int from, to;
		cin >> from >> to;
		
		graph[from].push_back(to);
		graph[to].push_back(from);
	}
	
	visited[1] = 1;
	DFS(1, 1);
	
	cin >> M;
	
	for(int i = 1; i <= M; i++)
	{
		int a, b;
		cin >> a >> b;
		
		cout << LCA(a, b) << "\n";
	}
	
	return 0;
}
