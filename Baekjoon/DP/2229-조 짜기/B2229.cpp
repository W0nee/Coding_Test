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
int student[1010];
int dp[1010];
int Max;

int solve(int idx)
{
	if(idx >= N)
	{	
		return 0;
	}
	
	if(dp[idx] != -1)
	{
		return dp[idx];
	}
	dp[idx] = 0;
	
	int Max = 0;
	int Min = 987654321;
	
	for(int i = idx; i <= N; i++)
	{
		Max = max(Max, student[i]);
		Min = min(Min, student[i]);
		
		dp[idx] = max(dp[idx], solve(i+1) + Max-Min);
	}
	
	return dp[idx];
}

int main(void)
{
//	freopen("B2229_input.txt", "r", stdin);
	
	memset(dp, -1, sizeof(dp));
	
	cin >> N;
	
	for(int i = 1; i <= N; i++)
	{
		cin >> student[i];
	}
	
	cout << solve(1);

	return 0;
}
