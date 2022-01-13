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

int N, M;
int num[1050][1050];
int dp[1050][1050];
int x1, y1, x2, y2;

int main(void)
{
//	freopen("B11660_input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> M;
	
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			cin >> num[i][j];
		}
	}
	
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + num[i][j];
		}
	}
	
//	for(int i = 1; i <= N; i++)
//	{
//		for(int j = 1; j <= N; j++)
//		{
//			cout << dp[i][j] << " ";
//		}
//		cout << endl;
//	}
	
	for(int i = 1; i <= M; i++)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		
		cout << dp[x2][y2] + dp[x1-1][y1-1] - dp[x2][y1-1] - dp[x1-1][y2] << "\n";
	}
	
	return 0;
}
