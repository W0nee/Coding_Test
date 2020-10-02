#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

#define INF 999999999

int row, col;
int dp[10010][110];

int solve(int row, int col)
{
//	if(row < col)
//	{
//		int temp = row;
//		row = col;
//		col = row;
//	}
	
	if(row < 1 || col < 1)
	{
		return INF;
	}
	else if(row == col)
	{
		return 1;
	}
	else if(row % col == 0)
	{
		return row / col;
	}
	
	if(dp[row][col] != INF)
	{
		return dp[row][col];
	}
	
	for(int i = 1; i <= row/2; i++)
	{
		dp[row][col] = min(dp[row][col], solve(row-i, col) + solve(i, col));
	}
	
	for(int i = 1; i <= col/2; i++)
	{
		dp[row][col] = min(dp[row][col], solve(row, col-i) + solve(row, i));
	}
	
	return dp[row][col];
}

int main(void)
{
//	freopen("B10803_input.txt", "r", stdin);
	
	cin >> row >> col;
	
	for(int i = 1; i <= row; i++)
	{
		for(int j = 1; j <= col; j++)
		{
			dp[i][j] = INF;
		}
	}
	
	cout << solve(row, col);
	
	return 0;
}
