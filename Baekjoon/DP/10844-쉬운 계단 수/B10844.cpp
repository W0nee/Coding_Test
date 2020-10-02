#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 1000000000

int N;
long long dp[110][10];
long long ans;

long long solve(int n, int now)
{
	if(n == N)
	{
		return 1;
	}
	
	if(dp[n][now] != 0)
	{
		return dp[n][now];
	}
	
	if(now == 0)
	{
		dp[n][now] += solve(n+1, now+1) % INF;
	}
	else if(now == 9)
	{
		dp[n][now] += solve(n+1, now-1) % INF;
	}
	else
	{
		dp[n][now] += solve(n+1, now-1) % INF + solve(n+1, now+1) % INF;
	}
	
	return dp[n][now] % INF;
}

int main(void)
{
//	freopen("B10844_input.txt", "r", stdin);
	
	cin >> N;
	
	for(int i = 1; i <= 9; i++)
	{
		ans += solve(1, i) % INF;
	}
	
	cout << ans % INF;
	
	return 0;
}
