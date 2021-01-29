#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int N, W;
vector<pair<int, int>> jewel;
int dp[10010];

int solve(int sum)
{
	if(sum > W)
	{
		return -987654321;
	}
	else if(sum == W)
	{
		return 0;
	}
	
	if(dp[sum] != 0)
	{
		return dp[sum];
	}
	
	for(int i = 0; i < jewel.size(); i++)
	{
		dp[sum] = max(dp[sum], solve(sum + jewel[i].first) + jewel[i].second);
	}
	
	return dp[sum];
}

int main(void)
{
//	freopen("J1077_input.txt", "r", stdin);

	cin >> N >> W;
	
	for(int i = 1; i <= N; i++)
	{
		int weight, val;
		cin >> weight >> val;
		
		jewel.push_back({weight, val});
	}
	
//	sort(jewel.begin(), jewel.end());
	
	cout << solve(0);
	
	return 0;
}
