#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 10007

int N;
long long dp[1010][10];
long long ans;

long long solve(int n, int num)
{
	if(n == N)
	{
		return 1;
	}
	
	if(dp[n][num] != 0)
	{
		return dp[n][num];
	}
	
	for(int i = num; i <= 9; i++)
	{
		dp[n][num] += solve(n+1, i) % INF;
	}
	
	return dp[n][num] % INF;
}

int main(void)
{
//	freopen("B11057_input.txt", "r", stdin);
	
	cin >> N;
	
	for(int i = 0; i <= 9; i++)
	{
		ans += solve(1, i);
	}
	
	cout << ans % INF;
	
	return 0;
}
