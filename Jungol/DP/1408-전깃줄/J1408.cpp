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
int dp[110];
vector<pair<int, int>> line;
int Max;

int solve(int idx)
{
	if(idx == line.size()-1)
	{
		return 0;
	}
	
	if(dp[idx] != -1)
	{
		return dp[idx];
	}
	dp[idx] = 0;
	
	for(int i = idx+1; i < line.size(); i++)
	{
		if(line[idx].first < line[i].first && line[idx].second < line[i].second)
		{
			dp[idx] = max(dp[idx], solve(i) + 1);	
		}
	}
	
	return dp[idx];
}

int main(void)
{
//	freopen("J1408_input.txt", "r", stdin);

	memset(dp, -1, sizeof(dp));
	
	cin >> N;
	
	for(int i = 1; i <= N; i++)
	{
		int a, b;
		cin >> a >> b;
		
		line.push_back({a, b});
	}
	
	sort(line.begin(), line.end());
	
	for(int i = 0; i < line.size(); i++)
	{
		Max = max(Max, solve(i) + 1);
	}
	
	cout << N - Max;
	
	return 0;
}
