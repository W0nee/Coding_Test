#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int T;
int N;
int dp[15];

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
	
	dp[n] += solve(n-3);
	dp[n] += solve(n-2);
	dp[n] += solve(n-1);
	
	return dp[n];
}

int main(void)
{
//	freopen("B9095_input.txt", "r", stdin);
	
	cin >> T;
	
	while(T--)
	{
		memset(dp, 0, sizeof(dp));
		
		cin >> N;
		
		cout << solve(N) << endl;	
	}
	
	return 0;
}
