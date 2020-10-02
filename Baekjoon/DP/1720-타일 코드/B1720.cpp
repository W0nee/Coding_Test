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
int dp[40];
int ans;

int solve(int n)
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
	
	dp[n] += solve(n-1) + solve(n-2) + solve(n-2);
	
	return dp[n];
}

int main(void)
{
//	freopen("B1720_input.txt", "r", stdin);
	
	cin >> N;
	
	if(N % 2 == 1)
	{
		ans = solve(N) + solve((N-1)/2);
	}
	else
	{
		ans = solve(N) + solve(N/2) + solve((N-2)/2) + solve((N-2)/2);
	}
	
	cout << ans / 2;
	
	return 0;
}
