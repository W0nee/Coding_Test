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
int Map[510][510];
int dp[510][510];

int solve(int row, int col)
{
	if(row > N)
	{
		return 0;
	}
	
	if(dp[row][col] != 0)
	{
		return dp[row][col];
	}
	
	dp[row][col] = Map[row][col] + max(solve(row+1, col), solve(row+1, col+1));
	
	return dp[row][col];
}

int main(void)
{
//	freopen("B1932_input.txt", "r", stdin);
	
	cin >> N;
	
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= i; j++)
		{
			cin >> Map[i][j];
		}
	}
	
	cout << solve(1, 1);
	
	return 0;
}
