#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

string a, b;
pair<string, int> dp[1010][1010];

string solve(int left, int right)
{
	if(left == a.size() || right == b.size())
	{
		return "";
	}
	
	if(dp[left][right].second != -1)
	{
		return dp[left][right].first;
	}
	dp[left][right].second = 0;
	
	if(a[left] == b[right])
	{
		dp[left][right].first = a[left] + solve(left+1, right+1);
	}
	else
	{
		string temp1 = solve(left+1, right);
		string temp2 = solve(left, right+1);
		
		if(temp1.size() > temp2.size())
		{
			dp[left][right].first = temp1;
		}
		else
		{
			dp[left][right].first = temp2;
		}
	}

	return dp[left][right].first;
}

int main(void)
{
//	freopen("B9252_input.txt", "r", stdin);
	
	cin >> a >> b;
	
	for(int i = 0; i <= 1000; i++)
	{
		for(int j = 0; j <= 1000; j++)
		{
			dp[i][j].second = -1;
		}
	}

	string result = solve(0, 0);
	
	cout << (int)result.size() << "\n";
	cout << result;

	return 0;
}
