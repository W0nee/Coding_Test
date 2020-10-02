#include <stdio.h>
#include <iostream>
#include <queue>
#include <stack>
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
		dp[left][right] = 1 + solve(left+1, right+1);
	}
	
	return dp[left][right];
}

int main(void)
{
//	freopen("B5582_input.txt", "r", stdin);
	
	cin >> a >> b;
	
	memset(dp, -1, sizeof(dp));
	
	for(int i = 0; i < a.size(); i++)
	{
		for(int j = 0; j < b.size(); j++)
		{
			Max = max(Max, solve(i, j));
		}
	}
	
	cout << Max;
	
	return 0;
}
