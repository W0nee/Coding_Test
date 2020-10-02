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
int Map[510][510];
int dp[510][510];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

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

int DFS(int x, int y)
{
	if(x == row && y == col)
	{
		return 1;
	}
	
	if(dp[x][y] != -1)
	{
		return dp[x][y];
	}
	dp[x][y] = 0;
	
	for(int i = 0; i < 4; i++)
	{
		int nx = x+dx[i];
		int ny = y+dy[i];
		
		if(safe(nx, ny) == 0)
		{
			continue;
		}
		
		if(Map[x][y] > Map[nx][ny])
		{
			dp[x][y] += DFS(nx, ny);	
		}
	}
	
	return dp[x][y];
}

int main(void)
{
//	freopen("B1520_input.txt", "r", stdin);
	
	cin >> row >> col;
	
	memset(dp, -1, sizeof(dp));
	
	for(int i = 1; i <= row; i++)
	{
		for(int j = 1; j <= col; j++)
		{
			cin >> Map[i][j];
		}
	}

	cout << DFS(1, 1);
	
	return 0;
}
