#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

string s;
string bridge[3];
int dp[3][110][30];

int solve(int row, int col, int idx)
{
	if(idx == s.size())
	{
		return 1;
	}
	else if(col == bridge[1].size())
	{
		return 0;
	}
	
	if(dp[row][col][idx] != -1)
	{
		return dp[row][col][idx];
	}
	dp[row][col][idx] = 0;
	
	if(row == 1)
	{
		if(bridge[1][col] == s[idx])
		{
			dp[row][col][idx] += solve(2, col+1, idx+1);
		}
		
		dp[row][col][idx] += solve(1, col+1, idx);
	}
	else if(row == 2)
	{
		if(bridge[2][col] == s[idx])
		{
			dp[row][col][idx] += solve(1, col+1, idx+1);
		}
		
		dp[row][col][idx] += solve(2, col+1, idx);
	}
	
	return dp[row][col][idx];
}


int main(void)
{
//	freopen("B2602_input.txt", "r", stdin);

	cin >> s >> bridge[1] >> bridge[2];
	
	memset(dp, -1, sizeof(dp));
	
	cout << solve(1, 0, 0) + solve(2, 0, 0);
	
	return 0;
}
