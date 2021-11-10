#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

string a, b;
int dp[4010][4010];
int Max;

int solve(int left, int right)
{
	if(left == a.size() || right == b.size())
	{
		return 0;
	}
	
	if(dp[left][right] != -1)
	{
		return dp[left][right];
	}
	dp[left][right] = 0;
	
	if(a[left] == b[right])
	{
		dp[left][right] += solve(left+1, right+1) + 1;
	}
	
	solve(left+1, right);
	solve(left, right+1);
	
	Max = max(Max, dp[left][right]);
	
	return dp[left][right];
}

int main(void)
{
//	freopen("B5582_input.txt", "r", stdin);

	memset(dp, -1, sizeof(dp));
	
	cin >> a >> b;
	
	solve(0, 0);
	
	cout << Max;
	
	return 0;
}
