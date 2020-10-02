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
int stair[310];
int dp[310][4];

int solve(int n, int cnt)
{
	if(n <= 0)
	{
		return 0;
	}
	
	if(dp[n][cnt] != 0)
	{
		return dp[n][cnt];
	}
	
	if(cnt == 1)
	{
		dp[n][cnt] = max({dp[n][cnt], stair[n] + solve(n-2, 1), stair[n] + solve(n-1, 2)});
	}
	else if(cnt == 2)
	{
		dp[n][cnt] = max(dp[n][cnt], stair[n] + solve(n-2, 1));
	}
	
	return dp[n][cnt];
}

int main(void)
{
//	freopen("B2579_input.txt", "r", stdin);
	
	cin >> N;
	
	for(int i = 1; i <= N; i++)
	{
		cin >> stair[i];
	}
	
	cout << solve(N, 1);
	
	return 0;
}
