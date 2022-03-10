#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

int N;
int Map[510][510];
int dp[510][510];
int Max = -1;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int solve(int x, int y)
{
	if(dp[x][y] != 0)
	{
		return dp[x][y];
	}
	dp[x][y] = 1;
	
	for(int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		
		if(!(1 <= nx && nx <= N && 1 <= ny && ny <= N))
		{
			continue;
		}
		
		if(Map[x][y] < Map[nx][ny])
		{
			dp[x][y] = max(dp[x][y], solve(nx, ny) + 1);
		}
	}
	
	return dp[x][y];
}

int main(void)
{
//	freopen("B1937_input.txt", "r", stdin);
	
	cin >> N;
	
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			cin >> Map[i][j];
		}
	}
	
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			Max = max(Max, solve(i, j));
		}
	}
	
//	for(int i = 1; i <= N; i++)
//	{
//		for(int j = 1; j <= N; j++)
//		{
//			cout << dp[i][j] << " ";		
//		}
//		cout << endl;
//	}
	
	cout << Max << endl;
	
	return 0;
}
