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
int dp[100100];

int solve(int cnt)
{
	if(cnt == N)
	{
		return 1;
	}
	else if(cnt > N)
	{
		return 0;
	}
	
	if(dp[cnt] != -1)
	{
		return dp[cnt];
	}
	dp[cnt] = 0;
	
	dp[cnt] += solve(cnt+1) % 20100529 + solve(cnt+2) * 2 % 20100529;
	
	return dp[cnt] % 20100529;
}

int main(void)
{
//	freopen("J1411_input.txt", "r", stdin);

	memset(dp, -1, sizeof(dp));
	
	cin >> N;
	
	cout << solve(0);
	
	return 0;
}
