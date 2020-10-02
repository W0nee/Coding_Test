#include <stdio.h>
#include <iostream>
#include <queue>
#include <string.h>
#include <algorithm>
using namespace std;

int N;
vector<int> graph[3010];
int visited[3010]; // -1 : cycle, 0 : not visited, 1 : visited
int finished[3010];
int cycle[3010];
int parent[3010];

void DFS(int here, int prev)
{
	if(visited[here] == 1)
	{
		return;
	}
	
	visited[here] = 1;
	
	for(int i = 0; i < graph[here].size(); i++)
	{
		int next = graph[here][i];
		
		if(visited[next] == 0)
		{
			parent[next] = here;
			DFS(next, here);
		}
		else if(finished[next] == 0 && next != prev) 
		{
			parent[next] = here;
			
			int arrive = next;
			cycle[arrive] = 1;
			
			for(int i = parent[arrive]; i != arrive; i = parent[i])
			{
				cycle[i] = 1;
			}
		}
	}
	
	finished[here] = 1;
}

void BFS(int x)
{
	queue<pair<int, int>> q;
	int visited[3010] = {0};
	bool arrive_cycle = false;
	
	q.push({x, 0});
	visited[x] = 1;
	int Min;
	
	while(!q.empty())
	{
		x = q.front().first;
		int cost = q.front().second;
		q.pop();
		
		if(cycle[x] == 1)
		{
			arrive_cycle = true;
			Min = cost;
			break;
		}
		
		for(int i = 0; i < graph[x].size(); i++)
		{
			if(visited[graph[x][i]] == 0)
			{
				visited[graph[x][i]] = 1;
				q.push({graph[x][i], cost+1});
			}
		}
	}
	
	if(arrive_cycle)
	{
		cout << Min << " ";
	}
	else
	{
		cout << "0 ";
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
		
		parent[i] = i;
	}
	
	// 순환선 체크 
	for(int i = 1; i <= N; i++)
	{
		if(finished[i] == 0)
		{
			DFS(i, 0);
		}
	}
	
//	for(int i = 1; i <= N; i++)
//	{
//		cout << cycle[i] << " ";
//	}
//	cout << endl;
	
	// 거리 체크 
	for(int i = 1; i <= N; i++)
	{
		BFS(i);
	}
	
	return 0;
}
