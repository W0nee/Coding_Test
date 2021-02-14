#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

int N, M;
vector<int> graph[110];
int check[110][110];

void BFS(int start)
{
	queue<int> q;
	int visited[110] = {0};
	
	q.push(start);
	visited[start] = 1;
	
	while(!q.empty())
	{
		int x = q.front();
		q.pop();
		
		for(int i = 0; i < graph[x].size(); i++)
		{
			int next = graph[x][i];
			
			if(visited[next] == 0)
			{
				q.push(next);
				visited[next] = 1;
				check[start][next] = 1;
			}
		}
	}
}

int count_object(int start)
{
	int cnt = 0;
	
	for(int i = 1; i <= N; i++)
	{
		if(i == start)
		{
			continue;
		}
		
		if(check[start][i] == 0 && check[i][start] == 0)
		{
			cnt++;
		}
	}	
	
	return cnt;
} 

int main(void)
{
//	freopen("B10159_input.txt", "r", stdin);
	
	cin >> N >> M;
	
	for(int i = 1; i <= M; i++)
	{
		int from, to;
		cin >> from >> to;
		
		graph[from].push_back(to);
	}
	
	for(int i = 1; i <= N; i++)
	{
		BFS(i);
	}
	
	for(int i = 1; i <= N; i++)
	{
		cout << count_object(i) << "\n";
	}
	
	return 0;
}
