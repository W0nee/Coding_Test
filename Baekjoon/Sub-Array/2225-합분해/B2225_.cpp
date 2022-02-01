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

int N, K;
long long dp[210][210];

long long solve(int sum, int cnt)
{
	if(sum > N || cnt > K)
	{
		return 0;
	}
	else if(sum == N && cnt == K)
	{
		return 1;
	}
	
	if(dp[sum][cnt] != -1)
	{
		return dp[sum][cnt];
	}
	dp[sum][cnt] = 0;
	
	for(int i = 0; i <= N-sum; i++)
	{
		dp[sum][cnt] += solve(sum + i, cnt + 1) % 1000000000;
	}
	
	return dp[sum][cnt] % 1000000000;
}

int main(void)
{
//	freopen("B2225_input.txt", "r", stdin);
	
	memset(dp, -1, sizeof(dp));
	
	cin >> N >> K;
	
	cout << solve(0, 0);
	
	return 0;
}
