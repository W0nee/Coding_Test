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

int N;
long long dp[1010];

long long solve(int n)
{
	if(n == 0)
	{
		return 1;
	}
	else if(n < 0)
	{
		return 0;
	}
	
	if(dp[n] != 0)
	{
		return dp[n];
	}
	
	dp[n] += solve(n-1) % INF + solve(n-2) % INF + solve(n-2) % INF;
	
	return dp[n] % INF;
}

int main(void)
{
//	freopen("B11727_input.txt", "r", stdin);
	
	cin >> N;
	
	cout << solve(N);
	
	return 0;
}
