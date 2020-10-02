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
int K;
int Map[20][20];
int dp[20][20];
int arriveX, arriveY;
int ans = 1;

int dx[2] = {1, 0};
int dy[2] = {0, 1};

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
	if(x == arriveX && y == arriveY)
	{
		return 1;
	}	
	
	if(dp[x][y] != 0)
	{
		return dp[x][y];
	}
	
	for(int i = 0; i < 2; i++)
	{
		int nx = x+dx[i];
		int ny = y+dy[i];
		
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
//	freopen("B10164_input.txt", "r", stdin);
	
	cin >> row >> col;
	
	int cnt = 0;
	for(int i = 1; i <= row; i++)
	{
		for(int j = 1; j <= col; j++)
		{
			Map[i][j] = ++cnt;
		}
	}
	
	cin >> K;
	
	int startX = 1;
	int startY = 1;
	if(K != 0)
	{
		arriveX = K / col + 1;
		if(K % col == 0) arriveX -= 1; 
		arriveY = K % col;
		if(arriveY == 0) arriveY = col;
		
		ans *= DFS(startX, startY);
		
		startX = arriveX;
		startY = arriveY;	
	}
	arriveX = row;
	arriveY = col;
	
	cout << ans * DFS(startX, startY);
	
	return 0;
}
