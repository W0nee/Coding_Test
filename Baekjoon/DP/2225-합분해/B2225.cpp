#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 1000000000

int N, K;
long long dp[210][210];

int safe(int x, int y)
{
	if(1 <= x && x <= N && 1 <= y && y <= N)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

long long solve(int sum, int cnt)
{
	if(sum == N && cnt == K)
	{
		return 1;
	}
	else if(sum > N || cnt > K)
	{
		return 0;
	}
	
	if(dp[sum][cnt] != 0)
	{
		return dp[sum][cnt];
	}
	
	for(int i = 0; i <= N; i++)
	{
		dp[sum][cnt] += solve(sum + i, cnt+1) % INF;
	}
	
	return dp[sum][cnt] % INF;
}

int main(void)
{
//	freopen("B2225_input.txt", "r", stdin);
	
	cin >> N >> K;
	
	cout << solve(0, 0);
	
	return 0;
}
