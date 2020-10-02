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
vector<pair<int, int>> line;
int dp[110];
int Max;

bool cmp(pair<int, int> a, pair<int, int> b)
{
	if(a.first < b.first)
	{
		return true;
	}
	
	return false;
}

int solve(int idx)
{
	if(dp[idx] != 0)
	{
		return dp[idx];
	}
	dp[idx] = 1;
	
	for(int i = idx+1; i < line.size(); i++)
	{
		if(line[idx].first < line[i].first && line[idx].second < line[i].second)
		{
			dp[idx] = max(dp[idx], 1 + solve(i));
		}
	}
	
	return dp[idx];
}

int main(void)
{
//	freopen("B2565_input.txt", "r", stdin);
	
	cin >> N;
	
	for(int i = 1; i <= N ; i++)
	{
		int from, to;
		cin >> from >> to;
		
		line.push_back({from, to});
	}
	
	sort(line.begin(), line.end(), cmp);

	for(int i = 0; i < line.size(); i++)
	{
		Max = max(Max, solve(i));
	}
	
	cout << N - Max;
	
	return 0;
}
