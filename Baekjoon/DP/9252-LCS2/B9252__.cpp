#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int dp[1010][1010];
string a, b;
string result;

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
		dp[left][right] = max(dp[left][right], solve(left+1, right+1) + 1);
	}
	else
	{
		dp[left][right] = max({dp[left][right], solve(left+1, right), solve(left, right+1)});
	}
	
	return dp[left][right];
}

string find(int left, int right)
{
	if(left == a.size() || right == b.size())
	{
		return "";
	}
	
	if(a[left] == b[right])
	{
		return a[left] + find(left+1, right+1);
	}
	else
	{
		if(dp[left+1][right] > dp[left][right+1])
		{
			return find(left+1, right);	
		}
		else
		{
			return find(left, right+1);	
		}
	}
}

int main(void)
{
//	freopen("B9252_input.txt", "r", stdin);

	memset(dp, -1, sizeof(dp));
	
	cin >> a >> b;
	
	cout << solve(0, 0) << "\n";
	cout << find(0, 0) << "\n";
	
	return 0;
}
