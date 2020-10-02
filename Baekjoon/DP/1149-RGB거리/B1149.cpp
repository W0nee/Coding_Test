#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 999999999

int N;
int house[1010][4];
int dp[1010][4];

int solve(int row, int col)
{
	if(row == N+1)
	{
		return 0;
	}
	
	if(dp[row][col] != 0)
	{
		return dp[row][col];
	}
	dp[row][col] = INF;
	
	if(col == 1)
	{
		dp[row][col] = min({dp[row][col], house[row][col] + solve(row+1, 2), house[row][col] + solve(row+1, 3)});
	}
	else if(col == 2)
	{
		dp[row][col] = min({dp[row][col], house[row][col] + solve(row+1, 1), house[row][col] + solve(row+1, 3)});
	}
	else if(col == 3)
	{
		dp[row][col] = min({dp[row][col], house[row][col] + solve(row+1, 1), house[row][col] + solve(row+1, 2)});
	}
	
	return dp[row][col];
}

int main(void)
{
//	freopen("B1149_input.txt", "r", stdin);
	
	cin >> N;
	
	for(int i = 1; i <= N; i++)
	{
		cin >> house[i][1] >> house[i][2] >> house[i][3];
	}
	
	cout << min({solve(1, 1), solve(1, 2), solve(1, 3)});
	
	return 0;
}
