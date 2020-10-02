#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;

#define INF 987654321

int N;
long long dp[10010];

long long solve(int n)
{
	if(n == 0 || n == 2)
	{
		return 1;
	}
	
	if(dp[n] != 0)
	{
		return dp[n];
	}
	
	for(int i = 0; i <= n-2; i += 2)
	{
		dp[n] += solve(i) % INF * solve(n-2-i) % INF;	
		dp[n] %= INF;
	}
	
	return dp[n] % INF;
}

int main(void)
{
//	freopen("B1670_input.txt", "r", stdin);
	
	cin >> N;
	
	cout << solve(N);
	
	return 0;
}
