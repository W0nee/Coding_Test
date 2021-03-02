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
int num[100010];
int dp[100010];
int Max = -987654321;

int solve(int idx)
{
	if(idx == N)
	{
		return 0;
	}
	
	if(dp[idx] != -987654321)
	{
		return dp[idx];
	}
	dp[idx] = 0;
	
	dp[idx] = max(dp[idx], solve(idx+1) + num[idx+1]);
	
	return dp[idx];
}

int main(void)
{
//	freopen("B1912_input.txt", "r", stdin);
	
	cin >> N;

	for(int i = 1; i <= N; i++)
	{
		cin >> num[i];
		
		dp[i] = -987654321;
	}
	
	for(int i = 1; i <= N; i++)
	{
		Max = max(Max, solve(i) + num[i]);
	}
	
	cout << Max;
	
	return 0;
}
