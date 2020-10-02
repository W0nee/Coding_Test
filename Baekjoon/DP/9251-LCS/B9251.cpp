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
int dp[1010][1010];

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
		dp[left][right] = max(dp[left][right], 1 + solve(left+1, right+1));
	}
	else
	{
		dp[left][right] = max({dp[left][right], solve(left+1, right), solve(left, right+1)});
	}

	return dp[left][right];
}

int main(void)
{
//	freopen("B9251_input.txt", "r", stdin);
	
	cin >> a >> b;
	
	memset(dp, -1, sizeof(dp));

	cout << solve(0, 0);
	
	return 0;
}
