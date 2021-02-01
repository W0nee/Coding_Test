#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
string a, b;
int dp[1010][1010];
int arr[1010][1010];
int leftIdx, rightIdx;

int solve(int left, int right)
{
	if(left == a.size() || right == b.size())
	{
		return 0;
	}
	
	if(dp[left][right] != -987654321)
	{
		return dp[left][right];
	}
	dp[left][right] = 0;
	
	if(a[left] == b[right])
	{
		dp[left][right] = max(dp[left][right], solve(left+1, right+1) + 3);
	}
	else
	{
		dp[left][right] = max({dp[left][right], solve(left+1, right) - 2, solve(left, right+1) - 2});
	}
	
	return dp[left][right];
}

int main(void)
{
//	freopen("J1858_input.txt", "r", stdin);

	for(int i = 0; i <= 1000; i++)
	{
		for(int j = 0; j <= 1000; j++)
		{
			dp[i][j] = -987654321;	
			arr[i][j] = 1;
		}
	}

	cin >> N >> a;
	cin >> M >> b;
	
	cout << solve(0, 0);
	
	return 0;
}
