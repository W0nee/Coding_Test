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
int arr[1010];
int dp[1010];

int solve(int n)
{
	if(n > N)
	{
		return INF;
	}
	else if(n == N)
	{
		return 0;
	}
	
	if(dp[n] != 0)
	{
		return dp[n];
	}
	dp[n] = INF;
	
	for(int i = 1; i <= arr[n]; i++)
	{
		dp[n] = min(dp[n], solve(n+i) + 1);
	}
	
	return dp[n];
}

int main(void)
{
//	freopen("B11060_input.txt", "r", stdin);
	
	cin >> N;
	
	for(int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}
	
	solve(1);
	
	if(dp[1] == INF)
	{
		cout << -1;
	}
	else
	{
		cout << dp[1];
	}
	
	return 0;
}
