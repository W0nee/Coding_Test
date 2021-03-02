#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int T;
int N, K;
int coin[25];
int dp[10010][22];

int solve(int sum, int idx)
{
	if(sum == K)
	{
		return 1;
	}
	else if(idx == N+1)
	{
		return 0;
	}
	
	if(dp[sum][idx] != -1)
	{
		return dp[sum][idx];	
	}
	dp[sum][idx] = 0;
	
	int cnt = K / coin[idx];
	for(int i = 0; i <= cnt; i++)
	{
		if(sum + coin[idx] * i <= K)
		{
			dp[sum][idx] += solve(sum + coin[idx] * i, idx+1);
		}
	}
	
	return dp[sum][idx];
}

int main(void)
{
//	freopen("B9084_input.txt", "r", stdin);

	cin >> T;
	
	while(T--)
	{
		memset(dp, -1, sizeof(dp));
		
		cin >> N;
		
		for(int i = 1; i <= N; i++)
		{
			cin >> coin[i];
		}
		
		cin >> K;
		
		cout << solve(0, 1) << "\n";
	}
	
	return 0;
}
