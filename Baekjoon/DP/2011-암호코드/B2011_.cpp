#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 1000000

string s;
long long dp[5010];

long long solve(int idx)
{
	if(idx == s.size())
	{
		return 1;
	}
	
	if(dp[idx] != 0)
	{
		return dp[idx];
	}
	
	if('1' <= s[idx] && idx < s.size())
	{
		dp[idx] += solve(idx+1) % INF;	
	}
	
	if((s[idx] == '1' || (s[idx] == '2' && s[idx+1] <= '6')) && idx+1 < s.size())
	{
		dp[idx] += solve(idx+2 % INF);
	}
	
	return dp[idx] % INF;
}

int main(void)
{
//	freopen("B2011_input.txt", "r", stdin);
	
	cin >> s;
	
	if('1' <= s[0] && s.size() >= 1)
	{
		dp[0] += solve(1);
	}
	
	if((s[0] == '1' || (s[0] == '2' && s[1] <= '6')) && s.size() >= 2)
	{
		dp[0] += solve(2);
	}
	
	cout << dp[0] % INF;
	
	return 0;
}
