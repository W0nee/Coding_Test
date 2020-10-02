#include <stdio.h>
#include <iostream>
#include <queue>
#include <stack>
#include <map>
#include <math.h>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int N;
long long dp[100][3];

long long solve(int idx, int num)
{
	if(idx == N)
	{
		return 1;
	}
	
	if(dp[idx][num] != 0)
	{
		return dp[idx][num];
	}
	
	if(num == 1)
	{
		dp[idx][num] += solve(idx+1, 0); 
	}
	else if(num == 0)
	{
		dp[idx][num] += solve(idx+1, 1) + solve(idx+1, 0); 
	} 
	
	return dp[idx][num];
}

int main(void)
{
//	freopen("B2193_input.txt", "r", stdin);
	
	cin >> N;
	
	cout << solve(1, 1);	
	
	return 0;
}
