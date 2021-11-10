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

int solve(int cnt)
{
	if(cnt == N)
	{
		return 0;
	}
	
	if(dp[cnt] != 0)
	{
		return dp[cnt];
	}	
	
	if(cnt+1 <= N)
	{
		dp[cnt] = solve(cnt+1) + 1;	
	}
	
	if(cnt+3 <= N)
	{
		dp[cnt] = solve(cnt+3) + 1;
	}
	
	return dp[cnt];
}

int main(void)
{
//	freopen("B9656_input.txt", "r", stdin);
	
	cin >> N;

	if(solve(0) % 2 == 0)
	{
		cout << "SK";
	}
	else
	{
		cout << "CY";
	}
	
	return 0;
}
