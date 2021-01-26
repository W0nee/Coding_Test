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
int child[220];
int dp[220];
int Max;

int solve(int idx)
{
	if(dp[idx] != 0)
	{
		return dp[idx];
	}
	
	for(int i = idx+1; i <= N; i++)
	{
		if(child[idx] < child[i])
		{
			dp[idx] = max(dp[idx], solve(i) + 1);
		}
	}
	
	return dp[idx];
}

int main(void)
{
//	freopen("B2096_input.txt", "r", stdin);
	
	cin >> N;
	
	for(int i = 1; i <= N; i++)
	{
		cin >> child[i];
	}
	
	for(int i = 1; i <= N; i++)
	{
		Max = max(Max, solve(i) + 1);
	}
	
	cout << N - Max;
	
	return 0;
}
