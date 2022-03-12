#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

int N;
int dp[1010];

int main(void)
{
//	freopen("B9657_input.txt", "r", stdin);
	
	cin >> N;
	
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 1;
	dp[4] = 1;
	
	for(int i = 5; i <= N; i++)
	{
		if(dp[i-1] == 2 || dp[i-3] == 2 || dp[i-4] == 2)
		{
			dp[i] = 1;
		}
		else
		{
			dp[i] = 2;
		}
	}
	
	if(dp[N] == 1)
	{
		cout << "SK";
	}
	else
	{
		cout << "CY";
	}
	
	return 0;
}
