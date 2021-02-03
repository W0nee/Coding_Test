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

int row, col;
int Map[1010][1010];
int dp[1010][1010]; 
int Max;

int main(void)
{
//	freopen("B14925_input.txt", "r", stdin);
	
	cin >> row >> col;
	
	for(int i = 1; i <= row; i++)
	{
		for(int j = 1; j <= col; j++)
		{
			cin >> Map[i][j];
			
			if(Map[i][j] == 0)
			{
				dp[i][j] = 1;
				Max = 1;
			}
		}
	}
	
	for(int i = 2; i <= row; i++)
	{
		for(int j = 2; j <= col; j++)
		{
			if(dp[i-1][j-1] >= 1 && dp[i-1][j] >= 1 && dp[i][j-1] >= 1)
			{
				if(dp[i][j] >= 1)
				{
					dp[i][j] = min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]}) + 1;				
					Max = max(Max, dp[i][j]);	
				}
			}
		}
	}
	
	cout << Max;
	
	return 0;
}
