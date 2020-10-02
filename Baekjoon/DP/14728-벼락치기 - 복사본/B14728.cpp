#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
int coin[10010];
int dp[10010][110];

int solve(int result, int idx)
{
	if(result == K)
	{
		return 0;
	}
	else if(idx == N+1)
	{
		return 999999999;
	}
	
	if(dp[result][idx] != 0)
	{
		return dp[result][idx];
	}
	dp[result][idx] = 999999999;
	
	if(result + coin[idx] <= K)
	{
		dp[result][idx] = solve(result + coin[idx], idx) + 1;	
	}
	dp[result][idx] = min(dp[result][idx], solve(result, idx+1));
	
	return dp[result][idx];
}

int main(void)
{
//	freopen("B14728_input.txt", "r", stdin);
	
	cin >> N >> K;
	
	for(int i = 1; i <= N ; i++)
	{
		cin >> coin[i];
	}
	
	int val = solve(0, 1);
	
	if(val == 999999999)
	{
		cout << -1;
	}
	else
	{
		cout << val;
	}
	
	return 0;
}
