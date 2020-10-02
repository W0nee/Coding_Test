#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int row, col;
int Map[1010][1010];
long long dp[1010][1010];

int dx[3] = {0, 1, 1};
int dy[3] = {1, 0, 1};

int safe(int x, int y)
{
	if(1 <= x && x <= row && 1 <= y && y <= col)
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
	if(x == row && y == col)
	{
		return Map[x][y];
	}
	
	if(dp[x][y] != -1)
	{
		return dp[x][y];
	}
	dp[x][y] = Map[x][y];
	
	for(int i = 0; i < 3; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		
		if(safe(nx, ny) == 0)
		{
			continue;
		}
		
		dp[x][y] = max(dp[x][y], Map[x][y] + DFS(nx, ny));
	}
	
	return dp[x][y];
}

int main(void)
{
//	freopen("B11048_input.txt", "r", stdin);
	
	cin >> row >> col;
	
	for(int i = 1; i <= row; i++)
	{
		for(int j = 1; j <= col; j++)
		{
			cin >> Map[i][j];
			
			dp[i][j] = -1;
		}
	}
	
	cout << DFS(1, 1);
	
	return 0;
}
