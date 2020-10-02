#include <stdio.h>
#include <iostream>
#include <queue>
#include <string.h>
#include <algorithm>
using namespace std;

int N;
int cycle[3010];
int visited[3010];
vector<int> graph[3010];
bool find_cycle;

void DFS(int start, int before, int arrive)
{
	if(visited[start] == 1 && visited[arrive] == 1)
	{
		find_cycle = true;
		return;
	}
	
	for(int i = 0; i < graph[start].size(); i++)
	{
		if(visited[graph[start][i]] == 0 && before != graph[start][i])
		{
			visited[graph[start][i]] = 1;
			DFS(graph[start][i], start, arrive);
			if(find_cycle)
			{
				cycle[graph[start][i]] = 1;
			}
		}
		
		if(find_cycle)
		{
			return;
		}
	}
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
	}
	
	// 순환선 체크 
	for(int i = 1; i <= N; i++)
	{
		find_cycle = false;
		memset(visited, 0, sizeof(visited));
		
		if(cycle[i] == 0)
		{
			DFS(i, i, i);
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
