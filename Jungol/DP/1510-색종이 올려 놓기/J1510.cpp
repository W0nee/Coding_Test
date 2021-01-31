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
vector<pair<int, int>> paper;
int dp[1010];
int Max;

int solve(int idx)
{
	if(idx == paper.size()-1)
	{
		return 0;
	}
	
	if(dp[idx] != -1)
	{
		return dp[idx];
	}
	dp[idx] = 0;
	
	for(int i = idx+1; i < paper.size(); i++)
	{
		if(paper[idx].second >= paper[i].second)
		{
			dp[idx] = max(dp[idx], solve(i) + 1);	
		}
	}
	
	return dp[idx];
}

int main(void)
{
//	freopen("J1510_input.txt", "r", stdin);

	memset(dp, -1, sizeof(dp));

	cin >> N;
	
	for(int i = 1; i <= N; i++)
	{
		int garo, sero;
		cin >> garo >> sero;
		
		if(sero > garo)
		{
			int temp = sero;
			sero = garo;
			garo = temp;
		}
		
		paper.push_back({garo, sero});
	}
	
	sort(paper.begin(), paper.end(), greater<pair<int, int>>());
	
	for(int i = 0; i < paper.size(); i++)
	{
		Max = max(Max, solve(i) + 1);
	}
	
	cout << Max << "\n";
	
	return 0;
}
