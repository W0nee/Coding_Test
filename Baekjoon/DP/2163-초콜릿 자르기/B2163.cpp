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
int dp[310][310];

int solve(int row, int col)
{
	if(row == 1 && col == 1)
	{
		return 0;
	}
	
	if(dp[row][col] != 0)
	{
		return dp[row][col];
	}
	
	if(row / 2 >= 1)
	{
		int nrow = (row+1) / 2;
		
		dp[row][col] += solve(nrow, col) + solve(row-nrow, col) + 1;
	}
	
	if(row == 1)
	{
		int ncol = (col+1) / 2;
		
		dp[row][col] += solve(row, ncol) + solve(row, col-ncol) + 1;
	}
	
	return dp[row][col];
}

int main(void)
{
//	freopen("B2163_input.txt", "r", stdin);
	
	cin >> row >> col;
	
	cout << solve(row, col);
	
	return 0;
}
