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

//int dp[1010][1010];
//int solve(int garo, int sero)
//{
//	if(idx == N)
//	{
//		return stair[idx];
//	}
//	else if(idx > N)
//	{
//		return -987654321;
//	}
//	
//	if(dp[garo][sero] != -1)
//	{
//		return dp[garo][sero];
//	}
//	dp[garo][sero] = 0;
//	
//	for(int i)
//	
//	return dp[garo][sero];
//}

int solve(int idx)
{
	if(idx == paper.size()-1)
	{
		return 1;
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
	
//	for(int i = 0; i < paper.size(); i++)
//	{
//		cout << paper[i].first << " " << paper[i].second << "\n";
//	}
	
	for(int i = 0; i < paper.size(); i++)
	{
		Max = max(Max, solve(i));
	}
	
	cout << Max;
	
	return 0;
}
