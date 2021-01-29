#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

string s;
int dp[50];

int solve(int idx)
{
	if(idx == s.size())
	{
		return 1;
	}
	else if(idx > s.size())
	{
		return 0;
	}
	
	if(dp[idx] != -1)
	{
		return dp[idx];
	}
	dp[idx] = 0;
	
	if(s[idx] != '0')
	{
		dp[idx] += solve(idx+1);	
	}
	
	if(s[idx] == '1')
	{
		dp[idx] += solve(idx+2);	
	}
	else if(s[idx] == '2')
	{
		dp[idx] += solve(idx+2);
	}
	else if(s[idx] == '3' && '0' <= s[idx+1] && s[idx+1] <= '4')
	{
		dp[idx] += solve(idx+2);
	}
	
	return dp[idx];
}

int main(void)
{
//	freopen("J1407_input.txt", "r", stdin);

	memset(dp, -1, sizeof(dp));
	
	cin >> s;
	
	cout << solve(0);
	
	return 0;
}
