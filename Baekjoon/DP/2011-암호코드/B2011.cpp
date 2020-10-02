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
	if(idx == s.size()-1)
	{
		return 1;
	}

	if(dp[idx] != 0)
	{
		return dp[idx];
	}
	
	if('1' <= s[idx+1] && idx+1 <= s.size()-1)
	{
		dp[idx] += solve(idx+1) % INF;
	}
	
	if((s[idx+1] == '1') || (s[idx+1] == '2' && s[idx+2] <= '6') && idx+2 <= s.size()-1)
	{
		dp[idx] += solve(idx+2) % INF;
	}
	
	return dp[idx] % INF;
}

int main(void)
{
//	freopen("B2011_input.txt", "r", stdin);
	
	cin >> s;
	
	s = "0" + s;
	
	cout << solve(0);
	
	return 0;
}
