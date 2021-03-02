#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int N, K;
ll dp[210][210];

ll solve(int sum, int cnt)
{
	if(sum == N && cnt == K)
	{
		return 1;
	}	
	else if(sum > N || cnt == K)
	{
		return 0;
	}
	
	if(dp[sum][cnt] != -1)
	{
		return dp[sum][cnt];
	}
	dp[sum][cnt] = 0;
	
	for(int i = 0; i <= N; i++)
	{
		dp[sum][cnt] += solve(sum + i, cnt+1) % 1000000000;	
	}
	
	return dp[sum][cnt] % 1000000000;	
}

int main(void)
{
//	freopen("B2225_input.txt", "r", stdin);
	
	cin >> N >> K;
	
	memset(dp, -1, sizeof(dp));
	
	cout << solve(0, 0);
	
	return 0;
}
