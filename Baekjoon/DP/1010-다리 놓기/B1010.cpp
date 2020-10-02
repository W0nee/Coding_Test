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
int N, M;
long long dp[40][40];

long long solve(int n, int m)
{
	if(n == 0)
	{
		return 1;
	}
	
	if(dp[n][m] != 0)
	{
		return dp[n][m];
	}
	
	for(int i = m-1; i >= n-1; i--)
	{
		dp[n][m] += solve(n-1, i);
	}
	
	return dp[n][m];
}

int main(void)
{
//	freopen("B1010_input.txt", "r", stdin);

	cin >> T;
	
	while(T--)
	{
		memset(dp, 0, sizeof(dp));
		
		cin >> N >> M;
	
		cout << solve(N, M) << "\n";
	}
	
	return 0;
}
