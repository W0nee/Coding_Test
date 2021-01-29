#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int T, K;
vector<pair<int, int>> coin;
int dp[10010][110];

int solve(int sum, int idx)
{
	if(sum == T)
	{
		return 1;
	}
	else if(sum > T || idx >= K)
	{
		return 0;
	}
	
	if(dp[sum][idx] != -1)
	{
		return dp[sum][idx];
	}
	dp[sum][idx] = 0;
	
	for(int i = 0; i <= coin[idx].second; i++)
	{
		dp[sum][idx] += solve(sum + coin[idx].first * i, idx+1);	
	}
	
	return dp[sum][idx];
}

int main(void)
{
//	freopen("J1382_input.txt", "r", stdin);
	
	memset(dp, -1, sizeof(dp));
	
	cin >> T >> K;
	
	for(int i = 1; i <= K; i++)
	{
		int val, n;
		cin >> val >> n;
		
		coin.push_back({val, n});
	}
	
//	sort(coin.begin(), coin.end());
	
	cout << solve(0, 0);
	
	return 0;
}
