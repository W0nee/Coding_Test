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
int coin[30];
int dp[10010][30];

int solve(int sum, int idx)
{
	if(sum == K)
	{
		return 1;
	}
	
	if(dp[sum][idx] != -1)
	{
		return dp[sum][idx];
	}
	dp[sum][idx] = 0;
	
	// 현재동전O 
	if(sum + coin[idx] <= K)
	{
		dp[sum][idx] += solve(sum + coin[idx], idx);
	}
	
	// 현재동전X, 다음동전 
	if(idx+1 <= N)
	{
		dp[sum][idx] += solve(sum, idx+1);	
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
