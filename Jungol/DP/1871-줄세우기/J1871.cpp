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
vector<int> child;
int dp[210];
int Max;

int solve(int idx)
{
	if(idx == N)
	{
		return 0;
	}
	
	if(dp[idx] != -1)
	{
		return dp[idx];
	}
	dp[idx] = 0;
	
	for(int i = idx+1; i < child.size(); i++)
	{
		if(child[idx] < child[i])
		{
			dp[idx] = max(dp[idx], solve(i) + 1);
		}
	}
	
	return dp[idx];
}

int main(void)
{
//	freopen("J1871_input.txt", "r", stdin);

	memset(dp, -1, sizeof(dp));

	cin >> N;
	
	for(int i = 1; i <= N; i++)
	{
		int num;
		cin >> num;
		
		child.push_back(num);
	}
	
	for(int i = 0; i < child.size(); i++)
	{
		Max = max(Max, solve(i) + 1);
	}
	
	cout << N - Max;
	
	return 0;
}
