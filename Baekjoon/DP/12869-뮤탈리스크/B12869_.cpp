#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <math.h>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int scv[4];
int dp[65][65][65];

int solve(int a, int b, int c)
{ 	
	if(a < 0) a = 0;
	if(b < 0) b = 0;
	if(c < 0) c = 0;
	
	if(a == 0 && b == 0 && c == 0)
	{
		return 0;
	}

	if(dp[a][b][c] != -1)
	{
		return dp[a][b][c];
	}
	dp[a][b][c] = 99999999;
	
	dp[a][b][c] = min(dp[a][b][c], solve(a-9, b-3, c-1) + 1);
	dp[a][b][c] = min(dp[a][b][c], solve(a-9, b-1, c-3) + 1);
	dp[a][b][c] = min(dp[a][b][c], solve(a-3, b-9, c-1) + 1);
	dp[a][b][c] = min(dp[a][b][c], solve(a-3, b-1, c-9) + 1);
	dp[a][b][c] = min(dp[a][b][c], solve(a-1, b-3, c-9) + 1);
	dp[a][b][c] = min(dp[a][b][c], solve(a-1, b-9, c-3) + 1);
	
	return dp[a][b][c];
}

int main(void)
{
//	freopen("B12869_input.txt", "r", stdin);

	memset(dp, -1, sizeof(dp));
	
	cin >> N;
	
	for(int i= 1; i <= N; i++)
	{
		cin >> scv[i];
	}
	
	cout << solve(scv[1], scv[2], scv[3]);
	
	return 0;
}
