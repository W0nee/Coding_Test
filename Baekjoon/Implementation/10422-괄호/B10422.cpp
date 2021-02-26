#include <stdio.h>
#include <iostream>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int T;
int L;
int dp[2510][2510];

int solve(int left, int right)
{
//	cout << left << " " << right << endl;
	
	if(left < right || left > L/2)
	{
		return 0;
	}
	else if(left + right == L)
	{
		return 1;
	}
	
	if(dp[left][right] != -1)
	{
		return dp[left][right];
	}
	dp[left][right] = 0;
	
	dp[left][right] += solve(left, right+1) % 1000000007;	
	dp[left][right] += solve(left+1, right) % 1000000007;	
	
	return dp[left][right] % 1000000007;
}

int main(void)
{
//	freopen("B10422_input.txt", "r", stdin);
	
	cin >> T;
	
	while(T--)
	{
		memset(dp, -1, sizeof(dp));
		
		cin >> L;
		
		if(L % 2 == 1)
		{
			cout << "0\n";
		}	
		else
		{
			cout << solve(0, 0) << "\n";
		}
	}
	
	return 0;
}
