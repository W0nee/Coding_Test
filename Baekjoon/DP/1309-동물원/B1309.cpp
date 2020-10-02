#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 9901

int N;
long long dp[100010][3];

long long solve(int row, int col)
{
	if(row == N)
	{
		return 1;
	}
	
	if(dp[row][col] != 0)
	{
		return dp[row][col];
	}
	
	if(col == 0)
	{
		dp[row][col] += solve(row+1, 0) % INF + solve(row+1, 1) % INF + solve(row+1, 2) % INF;
	}
	else if(col == 1)
	{
		dp[row][col] += solve(row+1, 0) % INF + solve(row+1, 2) % INF;
	}
	else if(col == 2)
	{
		dp[row][col] += solve(row+1, 0) % INF + solve(row+1, 1) % INF;
	}
	
	return dp[row][col] % INF;
}

int main(void)
{
//	freopen("B1937_input.txt", "r", stdin);
	
	cin >> N;
	
	cout << solve(0, 0);
	
	return 0;
}
