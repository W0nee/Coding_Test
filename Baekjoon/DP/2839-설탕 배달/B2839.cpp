#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int K;
int sugar[3];
int dp[5010][3];

int solve(int sum, int idx)
{
	if(sum == K)
	{
		return 0;
	}
	else if(idx > 2)
	{
		return 999999999;
	}
	
	if(dp[sum][idx] != 0)
	{
		return dp[sum][idx];
	}
	dp[sum][idx] = 999999999;
	
	if(sum + sugar[idx] <= K)
	{
		dp[sum][idx] = 1 + solve(sum + sugar[idx], idx);
	}
	
	dp[sum][idx] = min(dp[sum][idx], solve(sum, idx+1));
	
	return dp[sum][idx];
}

int main(void)
{
//	freopen("B2839_input.txt", "r", stdin);
	
	cin >> K;
	
	sugar[1] = 3;
	sugar[2] = 5;
	
	int result = solve(0, 1);
	
	if(result == 999999999)
	{
		cout << -1;
	}
	else
	{
		cout << result;
	}
	
	return 0;
}
