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
float num[10010];
float dp[10010];
float Max = -1;

float solve(int idx)
{
	if(idx > N)
	{
		return 1;
	}
	
	if(dp[idx] != -1)
	{
		return dp[idx];
	}
	dp[idx] = num[idx];
	
	dp[idx] = max(dp[idx], solve(idx+1) * num[idx]);
	
	return dp[idx];
}

int main(void)
{
//	freopen("B2670_input.txt", "r", stdin);
	
	cin >> N;
	
	for(int i = 1; i <= N; i++)
	{
		cin >> num[i];
		
		dp[i] = -1;
	}
	
	for(int i = 1; i <= N; i++)
	{
		Max = max(Max, solve(i));
	}
	
	printf("%.3f", Max);
	
	return 0;
}
