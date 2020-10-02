#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

int N, M;
vector<int> graph[110];
int visited[110];
int cnt;

void DFS(int x)
{
	for(int i = 0; i < graph[x].size(); i++)
	{
		if(visited[graph[x][i]] == 0)
		{
			visited[graph[x][i]] = 1;
			DFS(graph[x][i]);
		}	
	}
}

int main(void)
{
//	freopen("B2606_input.txt", "r", stdin);
	
	cin >> N >> M;
	
	for(int i = 1; i <= M; i++)
	{
		int from, to;
		cin >> from >> to;
		
		graph[from].push_back(to);
		graph[to].push_back(from);
	}
	
	visited[1] = 1;
	DFS(1);
	
	for(int i = 2; i <= N; i++)
	{
		if(visited[i] == 1)
		{
			cnt++;
		}
	}
	
	cout << cnt;
		
	return 0;
}
