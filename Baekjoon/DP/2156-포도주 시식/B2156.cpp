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
int dp[10010][4];

int solve(int n, int cnt)
{
	if(n > N)
	{
		return 0;
	}
	
	if(dp[n][cnt] != 0)
	{
		return dp[n][cnt];
	}
	
	if(cnt == 1)
	{
		dp[n][cnt] = max({dp[n][cnt], grape[n] + solve(n+1, 2), grape[n] + solve(n+2, 1)});
	}
	else if(cnt == 2)
	{
		dp[n][cnt] = max({dp[n][cnt], grape[n] + solve(n+2, 1), grape[n] + solve(n+3, 1)});
	}
	
	return dp[n][cnt];
}

int main(void)
{
//	freopen("B2156_input.txt", "r", stdin);
	
	cin >> N;
	
	for(int i = 1; i <= N; i++)
	{
		cin >> grape[i];
	}
	
	cout << max(solve(1, 1), solve(2, 1));
	
	return 0;
}
