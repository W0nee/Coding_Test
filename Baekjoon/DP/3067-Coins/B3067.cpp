#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string.h>
#include <algorithm>
using namespace std;

int T, N, K;
vector<int> coin;
int dp[10010][22];

int solve(int sum, int idx)
{
	if(sum == K)
	{
		return 1;
	}
	else if(sum > K)
	{
		return 0;
	}
	
	if(dp[sum][idx] != -1)
	{
		return dp[sum][idx];
	}
	dp[sum][idx] = 0;
	
	for(int i = idx; i < coin.size(); i++)
	{
		dp[sum][idx] += solve(sum + coin[i], i);
	}
	
	return dp[sum][idx];
}

int main(void)
{
//	freopen("B3067_input.txt", "r", stdin);

	cin >> T;
	
	while(T--)
	{
		memset(dp, -1, sizeof(dp));
		coin.clear();
		
		cin >> N;
		
		for(int i = 1; i <= N; i++)
		{
			int num;
			cin >> num;
			
			coin.push_back(num);
		}
		
		cin >> K;	
		
		cout << solve(0, 0) << "\n";
	}
	
	return 0;
}
