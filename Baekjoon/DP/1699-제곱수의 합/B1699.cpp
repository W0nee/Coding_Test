#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <string.h>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

int N;
int dp[100010];

int solve(int sum)
{
	if(sum == N)
	{
		return 0;
	}
	
	if(dp[sum] != 0)
	{
		return dp[sum];
	}
	dp[sum] = 99999999;
	
	for(int i = sqrt(N); i >= 1; i--)
	{
		if(sum + i*i <= N)
		{
			dp[sum] = min(dp[sum], solve(sum + i*i) + 1);	
		}
	}
	
	return dp[sum];
}

int main(void)
{
//	freopen("B1699_input.txt", "r", stdin);
	
	cin >> N;
	
	cout << solve(0);
	
	return 0;
}
