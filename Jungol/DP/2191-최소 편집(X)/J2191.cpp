#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
string a, b;
int dp[1010][1010];

int solve(int left, int right)
{
	if(left == a.size() && right == b.size())
	{
		return 0;
	}
	else if(left == a.size() || right == b.size())
	{
		return abs(left-right);
	}
	
	if(dp[left][right] != -1)
	{
		return dp[left][right];
	}
	dp[left][right] = 987654321;
	
	if(a[left] == b[right])
	{
		dp[left][right] = min(dp[left][right], solve(left+1, right+1));
	}
	else
	{
		dp[left][right] = min({dp[left][right], solve(left+1, right) + 1, solve(left, right+1) + 1, solve(left+1, right+1) + 1});
	}
	
	return dp[left][right];
}

int main(void)
{
//	freopen("J2191_input.txt", "r", stdin);

	memset(dp, -1, sizeof(dp));

	cin >> N >> a;
	cin >> M >> b;
	
	cout << solve(0, 0);
	
	return 0;
}
