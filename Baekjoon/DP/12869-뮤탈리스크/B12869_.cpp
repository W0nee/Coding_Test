#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 999999999;

int N;
int scv[5];
int dp[70][70][70];

int solve(int a, int b, int c)
{
	if(a < 0) a = 0;
	if(b < 0) b = 0;
	if(c < 0) c = 0;
	
	if(a == 0 && b == 0 && c == 0)
	{
		return 0;
	}
	
	if(dp[a][b][c] != 0)
	{
		return dp[a][b][c];
	}
	dp[a][b][c] = INF;
	
	dp[a][b][c] = min(dp[a][b][c], 1 + solve(a-9, b-3, c-1));
	dp[a][b][c] = min(dp[a][b][c], 1 + solve(a-9, b-1, c-3));
	dp[a][b][c] = min(dp[a][b][c], 1 + solve(a-3, b-9, c-1));
	dp[a][b][c] = min(dp[a][b][c], 1 + solve(a-3, b-1, c-9));
	dp[a][b][c] = min(dp[a][b][c], 1 + solve(a-1, b-3, c-9));
	dp[a][b][c] = min(dp[a][b][c], 1 + solve(a-1, b-9, c-3));
	
	return dp[a][b][c];
}

int main(void)
{
//	freopen("B12869_input.txt", "r", stdin);
	
	cin >> N;
	
	for(int i = 1; i <= N; i++)
	{
		cin >> scv[i];
	}
	
	if(N == 1)
	{
		cout << solve(scv[1], 0, 0);
	}
	else if(N == 2)
	{
		cout << solve(scv[1], scv[2], 0);
	}
	else
	{
		cout << solve(scv[1], scv[2], scv[3]);
	}
	
	return 0;
}
