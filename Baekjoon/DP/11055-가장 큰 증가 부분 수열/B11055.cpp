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
//	if(n > N)
//	{
//		return 0;
//	}

	if(dp[n] != 0)
	{
		return dp[n];
	}
	dp[n] = num[n];
	
	for(int i = n+1; i <= N; i++)
	{
		if(num[n] < num[i])
		{
			dp[n] = max(dp[n], num[n] + solve(i));
		}
	}
	
	return dp[n];
}

int main(void)
{
//	freopen("B11055_input.txt", "r", stdin);
	
	cin >> N;
	
	for(int i = 1; i <= N; i++)
	{
		cin >> num[i];
	}
	
	for(int i = 1; i <= N; i++)
	{
		Max = max(Max, solve(i));
	}

	cout << Max;
	
	return 0;
}
