#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int graph[110][110];
int visited[110];
int cnt;

void DFS(int x)
{
	if(visited[x+1] == 0 && graph[x][x+1] == 1)
	{
		visited[x+1] = 1;
		DFS(x+1);
	}
}

int main(void)
{
//	freopen("B14594_input.txt", "r", stdin);
	
	cin >> N >> M;
	
	for(int i = 1; i <= M; i++)
	{
		int from, to;
		cin >> from >> to;
		
		for(int j = from; j <= to-1; j++)
		{
			graph[j][j+1] = 1;
		}
	}
	
	for(int i = 1; i <= N; i++)
	{
		if(visited[i] == 0)
		{
			visited[i] = 1;
			DFS(i);
			
			cnt++;
		}
	}
	
	cout << cnt;
	
	return 0;
}
