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
int dp[10010][110];

int solve(int sum, int idx)
{
	if(sum == K)
	{
		return 0;
	}
//	else if(sum > K)
//	{
//		return INF;
//	}
	
	if(dp[sum][idx] != 0)
	{
		return dp[sum][idx];
	}
	dp[sum][idx] = INF;
	
//	for(int i = idx; i <= N; i++)
//	{
//		dp[sum][idx] = min(dp[sum][idx], solve(sum + coin[i], i) + 1);
//	}
	
	if(sum + coin[idx] <= K)
	{
		dp[sum][idx] = min(dp[sum][idx], solve(sum + coin[idx], idx) + 1);
	}
	
	if(idx+1 <= N)
	{
		dp[sum][idx] = min(dp[sum][idx], solve(sum, idx+1));
	}
	
	return dp[sum][idx];
}

int main(void)
{
//	freopen("B2294_input.txt", "r", stdin);
	
	cin >> N >> K;
	
	for(int i = 1; i <= N; i++)
	{
		cin >> coin[i];
	}
	
	// 오름차순 정렬이 중요
//	sort(coin+1, coin+N+1);                                                                                     
	
	solve(0, 1);

	if(dp[0][1] == INF)
	{
		cout << -1;
	}
	else
	{
		cout << dp[0][1];
	}
	
	return 0;
}
