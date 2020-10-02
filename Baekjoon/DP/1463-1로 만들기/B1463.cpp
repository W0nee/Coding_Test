#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int dp[1000010];

int solve(int n)
{
	if(n == 1)
	{
		return 0;
	}
	
	if(dp[n] != 0)
	{
		return dp[n];
	}
	dp[n] = 999999999;
	
	if(n % 3 == 0) dp[n] = min(dp[n], solve(n/3)+1);
	if(n % 2 == 0) dp[n] = min(dp[n], solve(n/2)+1);
	if(n - 1 >= 1)dp[n] = min(dp[n], solve(n-1)+1);
	
	return dp[n];
}

int main(void)
{
//	freopen("B1463_input.txt", "r", stdin);
	
	cin >> N;
	
	cout << solve(N);
	
	return 0;
}
