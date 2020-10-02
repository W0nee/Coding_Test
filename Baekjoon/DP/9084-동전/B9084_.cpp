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
int coin[25];
int dp[10010];
int sum;

int main(void)
{
//	freopen("B9084_input.txt", "r", stdin);

	cin >> T;
	
	while(T--)
	{
		memset(dp, 0, sizeof(dp));
		
		cin >> N;
		
		for(int i = 1; i <= N; i++)
		{
			cin >> coin[i];
		}
		
		cin >> sum;
		
		dp[0] = 1;
		for(int i = 1; i <= N; i++)
		{
			for(int j = coin[i]; j <= sum; j++)
			{
				dp[j] = dp[j] + dp[j-coin[i]];
			}
		}
		
		cout << dp[sum] << "\n";
	}
	
	return 0;
}
