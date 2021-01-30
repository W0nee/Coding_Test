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
int stair[310];
int dp[310][3];

int solve(int idx, int cnt)
{
	if(idx == N)
	{
		return stair[idx];
	}
	else if(idx > N)
	{
		return -987654321;
	}
	
	if(dp[idx][cnt] != 0)
	{
		return dp[idx][cnt];
	}
	
	if(cnt == 1)
	{
		dp[idx][cnt] = max({dp[idx][cnt], solve(idx+1, 2) + stair[idx], solve(idx+2, 1) + stair[idx]});
	}
	else if(cnt == 2)
	{
		dp[idx][cnt] = max(dp[idx][cnt], solve(idx+2, 1) + stair[idx]);
	}
	
	return dp[idx][cnt];
}

int main(void)
{
//	freopen("J1520_input.txt", "r", stdin);

	cin >> N;
	
	for(int i = 1; i <= N; i++)
	{
		cin >> stair[i];
	}
	
	cout << max(solve(1, 1), solve(2, 1));
	
	return 0;
}
