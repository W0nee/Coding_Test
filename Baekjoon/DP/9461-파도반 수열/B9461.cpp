#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int T;
int N;
long long dp[110];

long long solve(int n)
{
	if(n == 1)
	{
		return 1;
	}
	else if(n == 2)
	{
		return 1;
	}
	else if(n == 3)
	{
		return 1;
	}
	
	if(dp[n] != 0)
	{
		return dp[n];
	}
	
	dp[n] = solve(n-2) + solve(n-3);
	
	return dp[n];
}

int main(void)
{
//	freopen("B9461_input.txt", "r", stdin);
	
	cin >> T;
	
	while(T--)
	{
		cin >> N;
	
		cout << solve(N) << "\n";
	}
	
	return 0;
}
