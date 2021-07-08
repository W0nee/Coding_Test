#include <stdio.h>
#include <iostream>
#include <queue>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;

int T;
int N;
int psum[510];
int dp[510][510];

int solve(int a, int b)
{
	if(a == b)
	{
		return psum[b] - psum[b-1];
	}
	
	if(dp[a][b] != 0)
	{
		return dp[a][b];
	}
	dp[a][b] = 999999999;
	
	for(int mid = a; mid < b; mid++)
	{
		dp[a][b] = min(dp[a][b], solve(a, mid) + solve(mid+1, b) + psum[b] - psum[a-1]);	
	}
	
	return dp[a][b];
}

int main(void)
{
//	freopen("B11066_input.txt", "r", stdin);
	
	cin >> T;
	
	while(T--)
	{
		cin >> N;
		
		for(int i = 1; i <= N; i++)
		{
			int num;
			cin >> num;
			
			psum[i] = psum[i-1] + num;
		}
		
		cout << solve(1, N);
	}
	
	return 0;
}
