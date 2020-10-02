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
int dp1[42];
int dp2[42];

int solve1(int n)
{
	if(n == 0)
	{
		return 0;
	}
	else if(n == 1)
	{
		return 1;
	}
	
	if(dp1[n] != 0)
	{
		return dp1[n];
	}
	
	return dp1[n] = solve1(n-2) + solve1(n-1);
}

int solve2(int n)
{
	if(n == 0)
	{
		return 1;
	}
	else if(n == 1)
	{
		return 0;
	}
	
	if(dp2[n] != 0)
	{
		return dp2[n];
	}
	
	return dp2[n] = solve2(n-2) + solve2(n-1);
}

int main(void)
{
//	freopen("B1003_input.txt", "r", stdin);
	
	cin >> T;
	
	while(T--)
	{
		memset(dp1, 0, sizeof(dp1));
		memset(dp2, 0, sizeof(dp2));
		
		cin >> N;
		
		cout << solve2(N) << " " << solve1(N) << endl;	
	}
	
	return 0;
}
