#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

int N, K, S;
vector<int> graph[410];
int check[410][410];

void BFS(int start)
{
	queue<int> q;
	int visited[410] = {0};
	
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
				check[start][next] = -1;
				check[next][start] = 1;
			}
		}
	}
}

int main(void)
{
//	freopen("B1613_input.txt", "r", stdin);

	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	
	cin >> N >> K;
	
	for(int i = 1; i <= K; i++)
	{
		int from, to;
		cin >> from >> to;
		
		graph[from].push_back(to);
	}
	
	for(int i = 1; i <= N; i++)
	{
		BFS(i);
	}
	
	cin >> S;
	
	for(int i = 1; i <= S; i++)
	{
		int from, to;
		cin >> from >> to;
		
		cout << check[from][to] << "\n";
	}
	
	return 0;
}
