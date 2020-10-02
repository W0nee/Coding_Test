#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int Map[110][110];
long long dp[110][110];

int dx[2] = {0, 1};
int dy[2] = {1, 0};

int safe(int x, int y)
{
	if(1 <= x && x <= N && 1 <= y && y <= N)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

long long DFS(int x, int y)
{
	if(x == N && y == N)
	{
		return 1;
	}
	else if(Map[x][y] == 0)
	{
		return 0;
	}
	
	if(dp[x][y] != 0)
	{
		return dp[x][y];
	}
	
	for(int i = 0; i < 2; i++)
	{
		int nx = x + dx[i] * Map[x][y];
		int ny = y + dy[i] * Map[x][y];
		
		if(safe(nx, ny) == 0)
		{
			continue;
		}
		
		dp[x][y] += DFS(nx, ny);
	}
	
	return dp[x][y];
}

int main(void)
{
//	freopen("B1890_input.txt", "r", stdin);
	
	cin >> N;
	
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			cin >> Map[i][j];
		}
	}
	
	cout << DFS(1, 1);
	
	return 0;
}
