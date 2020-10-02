#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int T;
int N;
int num[1010];
int dp[1010];

int solve(int idx)
{
	if(idx > N)
	{
		return 0;
	}
	
	if(dp[idx] != -999999999)
	{
		return dp[idx];
	}
	dp[idx] = num[idx];
	
	dp[idx] = max(dp[idx], solve(idx+1) + num[idx]);
	
	return dp[idx];
}

int main(void)
{
//	freopen("B10211_input.txt", "r", stdin);
	
	cin >> T;
	
	while(T--)
	{
		int Max = -999999999;
		
		cin >> N;
		
		for(int i = 1; i <= N; i++)
		{
			cin >> num[i];
			
			dp[i] = -999999999;
		}
		
		for(int i = 1; i <= N; i++)
		{
			Max = max(Max , solve(i));
		}
		
		cout << Max << "\n";
	}
	
	return 0;
}
