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
int cycle[100010];
int cnt;

void DFS(int here)
{
	if(visited[here] == 1)
	{
		return;
	}
	
	visited[here] = 1;

	int next = num[here];
	
	if(visited[next] == 0)
	{
		parent[next] = here;
		DFS(next);
	}
	else if(finished[next] == 0)
	{
		parent[next] = here;
		
		int arrive = next;
		cycle[arrive] = 1;
		
		for(int i = parent[arrive]; i !=  arrive; i = parent[i])
		{
			cycle[i] = 1;
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
		
		memset(visited, 0, sizeof(visited));
		memset(finished, 0, sizeof(finished));
		memset(cycle, 0, sizeof(cycle));
		cnt = 0;
	
		for(int i = 1; i <= N; i++)
		{
			cin >> num[i];
		}
		
		for(int i = 1; i <= N; i++)
		{
			if(finished[i] == 0)
			{
				DFS(i);
			}
		}
		
		for(int i = 1; i <= N; i++)
		{
			if(cycle[i] == 0)
			{
				cnt++;
			}
		}
		
		cout << cnt << endl;	
	}
	
	return 0;
}
