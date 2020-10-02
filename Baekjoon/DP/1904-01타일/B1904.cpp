#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 15746

int N;
long long dp[1000010];

long long solve(int n)
{
	if(n == N)
	{
		return 1;
	}
	else if(n > N)
	{
		return 0;
	}
	
	if(dp[n] != 0)
	{
		return dp[n];
	}

	dp[n] += solve(n+2) % INF + solve(n+1) % INF;
	
	return dp[n] % INF;
}

int main(void)
{
//	freopen("B11053_input.txt", "r", stdin);
	
	cin >> N;
	
	cout << solve(0);
	
	return 0;
}
