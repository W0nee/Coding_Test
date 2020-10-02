#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <math.h>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
int memory[110];
int cost[110];
int dp[10010][110];

int solve(int result, int idx)
{ 	
	if(idx > N)
	{
		return 0;
	}
	
	if(dp[result][idx] != 0)
	{
		return dp[result][idx];
	}
	
	if(result - cost[idx] >= 0)
	{
		dp[result][idx] = memory[idx] + solve(result - cost[idx], idx+1);
	}
	
	dp[result][idx] = max(dp[result][idx], solve(result, idx+1));
	
	return dp[result][idx];
}

int main(void)
{
//	freopen("B7579_input.txt", "r", stdin);
	
	cin >> N >> K;
	
	for(int i = 1; i <= N; i++)
	{
		cin >> memory[i];
	}
	
	for(int i = 1; i <= N; i++)
	{
		cin >> cost[i];
	}
	
	for(int i = 0; i <= 10000; i++)
	{
		if(solve(i, 1) >= K)
		{
			cout << i;
			break;
		}
	}
	
	return 0;
}
