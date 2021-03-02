#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
int dp[10010][110];
vector<int> coin;

int solve(int sum, int idx)
{
	if(sum == K)
	{
		return 0;
	}
	else if(sum > K || idx == coin.size())
	{
		return 987654321;
	}
	
	if(dp[sum][idx] != 0)
	{
		return dp[sum][idx];
	}
	dp[sum][idx] = 987654321;
	
	dp[sum][idx] = min({dp[sum][idx], solve(sum, idx+1), solve(sum + coin[idx], idx) + 1});
	
	return dp[sum][idx];
}

int main(void)
{
//	freopen("B2294_input.txt", "r", stdin);
	
	cin >> N >> K;
	
	map<int, int> check;
	for(int i = 1; i <= N; i++)
	{
		int input;
		cin >> input;
		
		if(check[input] == 0)
		{
			check[input] = 1;
			coin.push_back(input);
		}
	}
	
	int val = solve(0, 0);
	
	if(val == 987654321)
	{
		cout << "-1";
	}
	else
	{
		cout << val;
	}
	
	return 0;
}
