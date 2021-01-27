#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int N, W;
int coin[20];
int dp[65100];

int solve(int sum)
{
	if(sum == W)
	{
		return 0;
	}
	else if(sum > W)
	{
		return 987654321;
	}
	
	if(dp[sum] != 0)
	{
		return dp[sum];
	}
	dp[sum] = 987654321;
	
	for(int i = 1; i <= N; i++)
	{
		dp[sum] = min(dp[sum], solve(sum + coin[i]) + 1);
	}
	
	return dp[sum];
}

int main(void)
{
//	freopen("J2000_input.txt", "r", stdin);
	
	cin >> N;
	
	for(int i = 1; i <= N; i++)
	{
		cin >> coin[i];	
	}
	
	cin >> W;
	
	int val = solve(0);
	
	if(val == 987654321)
	{
		cout << "impossible";
	}
	else
	{
		cout << val;
	}
	
	return 0;
}
