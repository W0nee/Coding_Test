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
int num[1010];
int dp[1010];
int Max;

int solve(int n)
{
	if(n == N)
	{
		return 0;
	}
	
	if(dp[n] != 0)
	{
		return dp[n];
	}

	for(int i = n+1; i <= N; i++)
	{
		if(num[n] < num[i])
		{
			dp[n] = max(dp[n], solve(i) + 1);
		}
	}
	
	return dp[n];
}

int main(void)
{
//	freopen("B11053_input.txt", "r", stdin);
	
	cin >> N;
	
	for(int i = 1; i <= N; i++)
	{
		cin >> num[i];
	}
	
	for(int i = 1; i <= N; i++)
	{
		Max = max(Max, solve(i) + 1);
	}
	
	cout << Max;
	
	return 0;
}
