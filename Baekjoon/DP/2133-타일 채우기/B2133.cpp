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
	
	for(int i = n; i >= 4; i -= 2)
	{
		dp[n] += 2 * solve(n-i);
	}
	dp[n] += 3 * solve(n-2);
	
	return dp[n];
}

int main(void)
{
//	freopen("B2133_input.txt", "r", stdin);
	
	cin >> N;
	
	if(N % 2 == 1)
	{
		cout << 0;
	}
	else
	{
		cout << solve(N);	
	}
	
	return 0;
}
