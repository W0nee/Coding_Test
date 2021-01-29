#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int fix[50];
int dp[50];

int solve(int n)
{
	if(n < 0)
	{
		return 0;
	}
	
	if(dp[n] != 0)
	{
		return dp[n];
	}
	
	return dp[n] = solve(n-1) + solve(n-2);
}

int main(void)
{
//	freopen("J1848_input.txt", "r", stdin);
	
	cin >> N >> M;
	
	for(int i = 1; i <= M; i++)
	{
		int num;
		cin >> num;
		
		fix[num] = 1;
	}
	
	dp[0] = 1, dp[1] = 1;
	
	solve(N); 
	
	int ans = 1;
	int cnt = 0;
	
	for(int i = 1; i <= N; i++)
	{
		if(fix[i] == 0)
		{
			cnt++;
		}
		else
		{
			ans *= dp[cnt];
			cnt = 0;
		}
	}
	
	if(fix[N] == 0)
	{
		ans *= dp[cnt];
	}
	
	cout << ans;
	
	return 0;
}
