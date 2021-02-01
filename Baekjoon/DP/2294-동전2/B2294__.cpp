#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 999999999

int N, K;
int coin[110];
int dp[10010];

int solve(int sum, int idx)
{
	if(sum == K)
	{
		return 0;
	}
	else if(sum > K)
	{
		return INF;
	}
	
	if(dp[sum] != 0)
	{
		return dp[sum];
	}
	dp[sum] = INF;
	
	for(int i = 1; i <= N; i++)
	{
		dp[sum] = min(dp[sum], solve(sum + coin[i], i) + 1);
	}
	
	return dp[sum];
}

int main(void)
{
//	freopen("B2294_input.txt", "r", stdin);
	
	cin >> N >> K;
	
	for(int i = 1; i <= N; i++)
	{
		cin >> coin[i];
	}
	
	int val = solve(0, 1);

	if(val == INF)
	{
		cout << "-1";
	}
	else
	{
		cout << val;
	}
	
	return 0;
}
