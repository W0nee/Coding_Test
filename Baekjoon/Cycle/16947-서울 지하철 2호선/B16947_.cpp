#include <stdio.h>
#include <iostream>
#include <queue>
#include <string.h>
#include <algorithm>
using namespace std;

int N;
vector<int> graph[3010];
int visited[3010];
int finished[3010];
int parent[3010];
vector<int> result;

void DFS(int x, int prev)
{
	for(int i = 0; i < graph[x].size(); i++)
	{
		int y = graph[x][i];
		
		if(prev == y)
		{
			continue;
		}
		
		if(visited[y] == 0)
		{
			parent[y] = x;
			visited[y] = 1;
			DFS(y, x);
		}
		else if(finished[y] == 0)
		{
			visited[y] = 2;
			
			for(int i = x; i != y; i = parent[i])
			{
				visited[i] = 2;
			}
		}
	}
	
	finished[x] = 1;
}

int BFS(int x)
{
	queue<pair<int, int>> q;
	int visit[3010] = {0};
	
	q.push({x, 0});
	visit[x] = 1;
	
	while(!q.empty())
	{
		x = q.front().first;
		int d = q.front().second;
		q.pop();
		
		for(int i = 0; i < graph[x].size(); i++)
		{
			int y = graph[x][i];
			
			if(visit[y] == 0 && visited[y] == 1)
			{
				visit[y] = 1;
				q.push({y, d+1});
			}
			else if(visit[y] == 0 && visited[y] == 2)
			{
				return d+1;
			}
		}
	}
}

int main(void)
{
//	freopen("B16947_input.txt", "r", stdin);
	
	cin >> N;
	
	for(int i = 1; i <= N; i++)
	{
		int from, to;
		cin >> from >> to;
		
		graph[from].push_back(to);	
		graph[to].push_back(from);	
	}
	
	for(int i = 1; i <= N; i++)
	{	
		if(visited[i] == 0)
		{
			visited[i] = 1;
			DFS(i, 0);
		}
	}
	
	for(int i = 1; i <= N; i++)
	{
		if(visited[i] == 2)
		{
			result.push_back(0);
		}
		else if(visited[i] == 1)
		{
			result.push_back(BFS(i));
		}
	}

	for(int i = 0; i < result.size(); i++)
	{
		cout << result[i] << " ";
	}
	
	return 0;
}
