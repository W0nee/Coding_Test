#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 10007

int N, K;
long long dp[1010][1010];

long long solve(int n, int k)
{
	if(k == 0 || k == n)
	{
		return 1;
	}
	
	if(dp[n][k] != 0)
	{
		return dp[n][k];
	}

	dp[n][k] += solve(n-1, k-1) % INF + solve(n-1, k) % INF;
	
	return dp[n][k] % INF;
}

int main(void)
{
//	freopen("B11051_input.txt", "r", stdin);
	
	cin >> N >> K;
	
	cout << solve(N, K);
	
	return 0;
}
