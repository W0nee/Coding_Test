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
int dp[10010];
vector<pair<int, int>> build;

int solve(int idx)
{
	if(idx >= N)
	{
		return 0;
	}
	
	if(dp[idx] != 987654321)
	{
		return dp[idx];
	}
	
	int Max = 0;
	
	for(int i = idx; i < N; i++)
	{
		Max = max({Max, build[i].first - build[idx].first, 2 * build[i].second});
		
		dp[idx] = min(dp[idx], solve(i+1) + Max);
	}
	
	return dp[idx];
}

int main(void)
{
//	freopen("B2300_input.txt", "r", stdin);

	cin >> N;
	
	for(int i = 0; i < N; i++)
	{
		int x, y;
		cin >> x >> y;
		
		build.push_back({x, abs(y)});
		
		dp[i] = 987654321;
	}
	
	sort(build.begin(), build.end());
	
	cout << solve(0);
	
	return 0;
}
