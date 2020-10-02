#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int N;
pair<int, int> consult[20];
int dp[20];

int solve(int day)
{
	if(day > N)
	{
		return 0;
	}
	
	if(dp[day] != 0)
	{
		return dp[day];
	}
	
	if(day + consult[day].first - 1 <= N)
	{
		dp[day] = consult[day].second + solve(day + consult[day].first);
	}
	
	dp[day] = max(dp[day], solve(day+1));
	
	return dp[day];
}

int main(void)
{
//	freopen("B14501_input.txt", "r", stdin);
	
	cin >> N;
	
	for(int i = 1; i <= N; i++)
	{
		cin >> consult[i].first >> consult[i].second;
	}
	
	cout << solve(1);
	
	return 0;
}
