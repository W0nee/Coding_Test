#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int N, S, M;
int volume[110];
int dp[1010][110];
bool Find = false;
int Max;

int solve(int v, int idx)
{
	if(v < 0 || v > M)
	{
		return -100;
	}
	else if(idx == N)
	{
		Find = true;
		Max = max(Max, v);
		return v;
	}

	if(dp[v][idx] != -1)
	{
		return dp[v][idx];
	}
	
	dp[v][idx] = max(solve(v + volume[idx+1], idx+1), solve(v - volume[idx+1], idx+1));
	
	return dp[v][idx];
}

int main(void)
{
//	freopen("B2011_input.txt", "r", stdin);
	
	cin >> N >> S >> M;
	
	memset(dp, -1, sizeof(dp));
	
	for(int i = 1; i <= N; i++)
	{
		cin >> volume[i];
	}
	
	solve(S, 0);
	
	if(Find)
	{
		cout << Max;
	}
	else
	{
		cout << -1;
	}
	
	return 0;
}
