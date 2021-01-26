#include <iostream>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <string>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int T;
int N, M;
long long dp[40][40];

long long solve(int left, int right)
{
  	if(left == 1)
	{
		return 1;
	} 
	
	if(dp[left][right] != 0)
	{
		return dp[left][right];
	}
	  	
	for(int i = right; i >= left; i--)
	{
		dp[left][right] += solve(left-1, i-1);
	}
	
	return dp[left][right];
}

int main(void)
{
//	freopen("B1010_input.txt", "r", stdin);
	
	cin >> T;
	
	while(T--)
	{
		memset(dp, 0, sizeof(dp));
		
		cin >> N >> M;

		long long sum = 0;
		
		for(int i = M; i >= N; i--)
		{
			sum += solve(N, i);
		}
		
		cout << sum << "\n";
	}
	
	return 0;
}
