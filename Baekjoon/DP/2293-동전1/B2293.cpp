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
int coin[110];
int dp[10010];

int main(void)
{
//	freopen("B2293_input.txt", "r", stdin);
	
	cin >> N >> K;
	
	for(int i = 1; i <= N; i++)
	{
		cin >> coin[i];
	}
	
	dp[0] = 1;
	for(int i = 1; i <= N; i++)
	{
		for(int j = coin[i]; j <= K; j++)
		{
			dp[j] = dp[j] + dp[j-coin[i]];
		}
	}
		
	cout << dp[K];
	
	return 0;
}
