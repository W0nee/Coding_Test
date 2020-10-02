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
int card[1010];
int dp[1010];

int solve(int n)
{
	if(n <= 0)
	{
		return 0;
	}
	
	if(dp[n] != 0)
	{
		return dp[n];
	}
	
	for(int i = 1; i <= n; i++)
	{
		dp[n] = max(dp[n], card[i] + solve(n-i));	
	}
	
	return dp[n];
}

int main(void)
{
//	freopen("B11502_input.txt", "r", stdin);
	
	cin >> N;
	
	for(int i = 1; i <= N; i++)
	{
		cin >> card[i];
	}
	
	cout << solve(N);
	
	return 0;
}
