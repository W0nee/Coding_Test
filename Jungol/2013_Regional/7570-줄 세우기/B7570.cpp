#include <stdio.h>
#include <iostream>
#include <queue>
#include <stack>
#include <map>
#include <math.h>
#include <string>
#include <algorithm>
using namespace std;

int N;
int num[1000010];
int dp[1000010];
int Max;

int main(void)
{
//	freopen("B7570_input.txt", "r", stdin);

	cin >> N;
	
	for(int i = 1; i <= N; i++)
	{
		cin >> num[i];
	}
	
	for(int i = 1; i <= N; i++)
	{
		dp[num[i]] = dp[num[i]-1] + 1;
		Max = max(Max, dp[num[i]]);
	}
	
	cout << N - Max;
	
	return 0;
}
