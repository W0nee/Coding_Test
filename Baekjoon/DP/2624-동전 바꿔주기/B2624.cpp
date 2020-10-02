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
int K;
pair<int, int> coin[110];
int dp[10010][110];

int solve(int sum, int idx)
{
	if(sum == K)
	{
		return 1;
	}
	else if(idx > N)
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
		if(sum + coin[idx].first * i <= K)
		{
			dp[sum][idx] += solve(sum + coin[idx].first * i, idx+1);
		}
	}
	
	return dp[sum][idx];
}

int main(void)
{
//	freopen("B2624_input.txt", "r", stdin);
	
	cin >> K >> N;
	
	for(int i = 1; i <= N; i++)
	{
		cin >> coin[i].first >> coin[i].second;
	}

	memset(dp, -1, sizeof(dp));
	
	cout << solve(0, 1);

	return 0;
}
