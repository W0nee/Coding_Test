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
int triangle[810];
int figure[810];
int cnt;
int dp[300010];

int main(void)
{
//	freopen("B1660_input.txt", "r", stdin);
	
	cin >> N;
	
	for(int i = 1; i <= N; i++)
	{
		dp[i] = 99999999;
	}
	
	for(int i = 1; i <= 800; i++)
	{
		triangle[i] = triangle[i-1] + i;
	}
	
	for(int i = 1; i <= 800; i++)
	{
		figure[i] = figure[i-1] + triangle[i];
		
		if(figure[i] > N)
		{
			cnt = i-1;
			break;
		}
	}
	
	for(int i = 1; i <= cnt; i++)
	{
		for(int j = figure[i]; j <= N; j++)
		{
			dp[j] = min(dp[j], dp[j-figure[i]] + 1);
		}
	}
	
	cout << dp[N];
	
	return 0;
}
