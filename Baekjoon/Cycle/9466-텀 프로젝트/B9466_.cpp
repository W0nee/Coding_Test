#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int T;
int N;
int num[100010];
int visited[100010];
int finished[100010];
int parent[100010];
int cnt;

void DFS(int here)
{
	int next = num[here];
	
	if(visited[next] == 0)
	{
		parent[next] = here;
		visited[next] = 1;
		DFS(next);
	}
	else if(finished[next] == 0)
	{
		visited[next] = 2;
		
		for(int i = here; i != next; i = parent[i])
		{
			visited[i] = 2;
		}
	}
	
	finished[here] = 1;
}

int main(void)
{
//	freopen("B9466_input.txt", "r", stdin);
	
	cin >> T;
	
	while(T--)
	{
		cin >> N;
		
		memset(parent, 0, sizeof(parent));
		memset(visited, 0, sizeof(visited));
		memset(finished, 0, sizeof(finished));
		cnt = 0;
	
		for(int i = 1; i <= N; i++)
		{
			cin >> num[i];
		}
		
		for(int i = 1; i <= N; i++)
		{			
			if(visited[i] == 0)
			{
				visited[i] = 1;
				DFS(i);
			}
		}
		
		for(int i = 1; i <= N; i++)
		{
			if(visited[i] == 1)
			{
				cnt++;
			}
		}
		
		cout << cnt << "\n";
	}
	
	return 0;
}
