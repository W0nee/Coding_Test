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

string a, b;
int dp[1010][1010];

int Max;
string word;

int solve(int left, int right)
{
	if(left == a.size() || right == b.size())
	{
		return 0;
	}
		
	if(dp[left][right] != -1)
	{
		return dp[left][right];
	}
	dp[left][right] = 0;
	
	if(a[left] == b[right])
	{
		dp[left][right] += solve(left+1, right+1) + 1;
	}
	else
	{
		dp[left][right] += max(solve(left+1, right), solve(left, right+1));
	}
	
	return dp[left][right];
}

void find_word(int left, int right, int val)
{
	if(left == a.size() || right == b.size())
	{
		return;
	}
	
	if(a[left] == b[right])
	{
		word += a[left];
		find_word(left+1, right+1, val-1);
	}
	else
	{
		if(dp[left+1][right] > dp[left][right+1])
		{
			find_word(left+1, right, val);	
		}
		else
		{
			find_word(left, right+1, val);	
		}
	}
}

int main(void)
{
//	freopen("B9252_input.txt", "r", stdin);

	memset(dp, -1, sizeof(dp));
	
	cin >> a >> b;
	
	Max = solve(0, 0);
	
	find_word(0, 0, Max);
	
	cout << Max << "\n";
	cout << word << "\n";
	
	return 0;
}
