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
vector<pair<int, int>> jewel;
int dp[10010][1010];

int solve(int sum, int idx)
{
	if(sum > W)
	{
		return -987654321;
	}
	else if(sum == W || idx >= N)
	{
		return 0;
	}
	
	if(dp[sum][idx] != -1)
	{
		return dp[sum][idx];
	}
	dp[sum][idx] = 0;
	
	for(int i = 0; i <= 1; i++)
	{
		dp[sum][idx] = max(dp[sum][idx], solve(sum + jewel[idx].first * i, idx+1) + jewel[idx].second * i);
	}
	
	return dp[sum][idx];
}

int main(void)
{
//	freopen("J1278_input.txt", "r", stdin);

	memset(dp, -1, sizeof(dp));

	cin >> N >> W;
	
	for(int i = 1; i <= N; i++)
	{
		int weight, val;
		cin >> weight >> val;
		
		jewel.push_back({weight, val});
	}
	
//	sort(jewel.begin(), jewel.end());
	
	cout << solve(0, 0);
	
	return 0;
}
