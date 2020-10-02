#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;

int N;
int dp[10000010];

int main(void)
{
//	freopen("B8394_input.txt", "r", stdin);
	
	cin >> N;
	
	dp[1] = 1;
	dp[2] = 2;
	for(int i = 3; i <= N; i++)
	{
		dp[i] = dp[i-1] % 10 + dp[i-2] % 10;
	}
	
	cout << dp[N] % 10;
	
	return 0;
}
