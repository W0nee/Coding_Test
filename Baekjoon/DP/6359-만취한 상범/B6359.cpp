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
int dp[110][110]; // 0: ´ÝÈû, 1: ¿­¸² 

int main(void)
{
//	freopen("B2167_input.txt", "r", stdin);
	
	cin >> T;
	
	for(int i = 1; i <= 100; i++)
	{
		for(int j = 1; j <= 100; j++)
		{
			if(j % i == 0)
			{
				if(dp[i-1][j] == 0)
				{
					dp[i][j] = 1;
				}
				else if(dp[i-1][j] == 1)
				{
					dp[i][j] = 0;
				}
			}
			else
			{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	
	while(T--)
	{
		cin >> N;
		
		int cnt = 0;
		
		for(int i = 1; i <= N; i++)
		{
			if(dp[N][i] == 1)
			{
				cnt++;
			}
		}
		
		cout << cnt << endl;
	}
	
	return 0;
}
