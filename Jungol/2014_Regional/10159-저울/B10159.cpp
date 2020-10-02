#include <stdio.h>
#include <iostream>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

int N, M;
int graph[110][110];

void floyd()
{
	for(int k = 1; k <= N; k++)
	{
		for(int i = 1; i <= N; i++)
		{
			for(int j = 1; j <= N; j++)
			{
				if(graph[i][k] != 0 && graph[k][j] != 0)
				{
					graph[i][j] = 1;
				}
			}
		}
	}
}



int main(void)
{
//	freopen("B10159_input.txt", "r", stdin);

	cin >> N >> M;
	
	for(int i = 1; i <= M; i++)
	{
		int from, to;
		cin >> from >> to;
		
		graph[from][to] = 1;
	}
	
	floyd();
	
	for(int i = 1; i <= N; i++)
	{
		int cnt = 0;
		
		for(int j = 1; j <= N; j++)
		{
			if(i == j)
			{
				continue;
			}
			
			if(graph[i][j] == 0 && graph[j][i] == 0)
			{
				cnt++;
			}
		}
		
		cout << cnt << endl;
	}
	
	return 0;
}
