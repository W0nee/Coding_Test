#include <stdio.h>
#include <iostream>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int dp[100010];
int num[100010];
int Max = -987654321;

int solve(int idx)
{
	if(idx == N+1)
	{
		return 0;
	}
	
	if(dp[idx] != 0)
	{
		return dp[idx];
	}
	dp[idx] = num[idx];
	
	dp[idx] = max(dp[idx], solve(idx+1) + num[idx]);
	
	return dp[idx];
}

int main(void)
{
//	freopen("B1912_input.txt", "r", stdin);
	
	cin >> N;
	
	for(int i = 1; i <= N; i++)
	{
		cin >> num[i];
	}
	
	for(int i = 1; i <= N; i++)
	{
		Max = max(Max, solve(i));
	}
	
	cout << Max;
	
	return 0;
}
