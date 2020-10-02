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

int getLen(int left, int right)
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
		dp[left][right] = max(dp[left][right], 1 + getLen(left+1, right+1));
	}
	else
	{
		dp[left][right] = max({dp[left][right], getLen(left+1, right), getLen(left, right+1)});
	}

	return dp[left][right];
}

string getStr(int left, int right)
{
	if(left == a.size() || right == b.size())
	{
		return "";
	}
	
	if(a[left] == b[right])
	{
		return a[left] + getStr(left+1, right+1);
	}
	else
	{
		if(dp[left+1][right] > dp[left][right+1])
		{
			return getStr(left+1, right);
		}
		else
		{
			return getStr(left, right+1);
		}
	}
}

int main(void)
{ 
//	freopen("B9252_input.txt", "r", stdin);
	
	cin >> a >> b;
	
	memset(dp, -1, sizeof(dp));

	cout << getLen(0, 0) << "\n";
	cout << getStr(0, 0);
	
	return 0;
}
