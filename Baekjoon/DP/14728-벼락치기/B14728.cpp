#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
pair<int, int> study[110];
int dp[10010][110];

int solve(int result, int idx)
{
	if(idx > N)
	{
		return 0;
	}
	
	if(dp[result][idx] != 0)
	{
		return dp[result][idx];
	}
	
	if(result + study[idx].first <= K)
	{
		dp[result][idx] = study[idx].second + solve(result + study[idx].first, idx+1);	
	}
	
	dp[result][idx] = max(dp[result][idx], solve(result, idx+1));
	
	return dp[result][idx];
}

int main(void)
{
//	freopen("B14728_input.txt", "r", stdin);
	
	cin >> N >> K;
	
	for(int i = 1; i <= N ; i++)
	{
		cin >> study[i].first >> study[i].second;
	}
	
	cout << solve(0, 1);
	
	return 0;
}
