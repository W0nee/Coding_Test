#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <math.h>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
pair<int, int> item[110];
int dp[100010][110];

int solve(int result, int idx)
{ 	
	if(idx > N)
	{
		return 0;
	}
	
	if(dp[result][idx] != -1)
	{
		return dp[result][idx];
	}
	dp[result][idx] = 0;
	
	if(result + item[idx].first <= K)
	{
		dp[result][idx] = item[idx].second + solve(result + item[idx].first, idx+1);
	}
	
	dp[result][idx] = max(dp[result][idx], solve(result, idx+1));
	
	return dp[result][idx];
}

int main(void)
{
//	freopen("B12865_input.txt", "r", stdin);
	
	cin >> N >> K;
	
	memset(dp, -1, sizeof(dp));
	
	for(int i = 1; i <= N; i++)
	{
		cin >> item[i].first >> item[i].second;
	}
	
	cout << solve(0, 1);
	
	return 0;
}
