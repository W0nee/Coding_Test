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
int sticker[3][100010];
int dp[3][100010];

int solve(int row, int col)
{
	if(col > N)
	{
		return 0;
	}
	
	if(dp[row][col] != -1)
	{
		return dp[row][col];
	}
	
	if(row == 1)
	{
		dp[row][col] = sticker[row][col] + max({solve(row+1, col+1), solve(row+1, col+2), solve(row, col+2)});	
	}
	else if(row == 2)
	{
		dp[row][col] = sticker[row][col] + max({solve(row-1, col+1), solve(row-1, col+2), solve(row, col+2)});	
	}	
	
	return dp[row][col];
}

int main(void)
{
//	freopen("B9465_input.txt", "r", stdin);
	
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);

	cin >> T;
	
	while(T--)
	{
		memset(dp, -1, sizeof(dp));
		
		cin >> N;
	
		for(int i = 1; i <= 2; i++)
		{
			for(int j = 1; j <= N; j++)
			{
				cin >> sticker[i][j];
			}
		}	
		
		cout << max(solve(1, 1), solve(2, 1)) << "\n";
	}
	
	return 0;
}
