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
int dp[50];
vector<int> vip;
int ans = 1;

int main(void)
{
//	freopen("B2302_input.txt", "r", stdin);
	
	cin >> N >> M;
	
	for(int i = 1; i <= M; i++)
	{
		int input;
		cin >> input; 
		
		vip.push_back(input);
	}
	
	dp[0] = 1;
	dp[1] = 1;
	for(int i = 2; i <= N; i++)
	{
		dp[i] = dp[i-1] + dp[i-2];
	}
	
	int std = 0;
	for(int i = 0; i < vip.size(); i++)
	{
		ans *= dp[vip[i]-std-1];
		std = vip[i];
	}
	ans *= dp[N-std];	
	
	cout << ans;
	
	return 0;
}
