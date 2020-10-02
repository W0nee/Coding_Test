#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int M;
int num[110];
long long dp[110][30];

long long solve(int n, int sum)
{
	if(!(0 <= sum && sum <= 20))
	{
		return 0;
	}
	
	if(n == N && sum == num[N])
	{
		return 1;
	}
	else if(n == N)
	{
		return 0;
	}
	
	if(dp[n][sum] != 0)
	{
		return dp[n][sum];
	}
	
	dp[n][sum] = solve(n+1, sum+num[n]) + solve(n+1, sum-num[n]);
	
	return dp[n][sum];
}

int main(void)
{
//	freopen("B5557_input.txt", "r", stdin);
	
	cin >> N;
	
	for(int i = 1; i <= N; i++)
	{
		cin >> num[i];
	}
	
	cout << solve(2, num[1]);
	
	return 0;
}
