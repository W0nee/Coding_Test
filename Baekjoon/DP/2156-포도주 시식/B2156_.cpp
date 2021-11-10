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
int grape[10010];
int dp[10010][5];

int solve(int n, int cnt)
{
	if(n > N)
	{
		return 0;
	}
	
	if(dp[n][cnt] != -1)
	{
		return dp[n][cnt];
	}
	dp[n][cnt] = 0;
	
	if(cnt == 0)
	{
		dp[n][cnt] += max(solve(n+1, 1), solve(n+2, 0)) + grape[n];
	}
	else if(cnt == 1)
	{
		dp[n][cnt] += max(solve(n+2, 0), solve(n+3, 0)) + grape[n];
	}
	
	return dp[n][cnt];
}

int main(void)
{
//	freopen("B2156_input.txt", "r", stdin);
	
	cin >> N;
	
	memset(dp, -1, sizeof(dp));
	
	for(int i = 1; i <= N; i++)
	{
		cin >> grape[i];
	}
	
	cout << max(solve(0, 0), solve(1, 0));
	
	return 0;
}
