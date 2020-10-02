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
int dp[1010];

int solve(int n)
{
	if(n == 0)
	{
		return 1;
	}
	else if(n < 0)
	{
		return 0;
	}
	
	if(dp[n] != 0)
	{
		return dp[n];
	}
	
	dp[n] += solve(n-1) % 10007 + solve(n-2) % 10007;
	
	return dp[n] % 10007;
}

int main(void)
{
//	freopen("B11726_input.txt", "r", stdin);
	
	cin >> N;
	
	cout << solve(N);
	
	return 0;
}
