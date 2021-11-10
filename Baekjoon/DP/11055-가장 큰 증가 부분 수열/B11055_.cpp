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
int num[1010];
int dp[1010];
int Max;

int solve(int idx)
{
	if(dp[idx] != 0)
	{
		return dp[idx];
	}
	dp[idx] = num[idx];
	
	for(int i = idx+1; i <= N; i++)
	{
		if(num[idx] < num[i])
		{
			dp[idx] = max(dp[idx], solve(i) + num[idx]);	
		}
	}
	
	return dp[idx];
}

int main(void)
{
//	freopen("B11055_input.txt", "r", stdin);
	
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
