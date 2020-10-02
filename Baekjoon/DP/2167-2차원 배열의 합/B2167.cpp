#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, K;
int arr[310][310];
int dp[310][310];

int main(void)
{
//	freopen("B2167_input.txt", "r", stdin);
	
	cin >> N >> M;
	
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= M; j++)
		{
			cin >> arr[i][j];
		}
	}
	
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= M; j++)
		{
			dp[i][j] = arr[i][j] + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
		}
	}
	
	cin >> K;
	
	for(int i = 1; i <= K; i++)
	{
		int leftX, leftY, rightX, rightY;
		cin >> leftX >> leftY >> rightX >> rightY;
		
		cout << dp[rightX][rightY] - dp[leftX-1][rightY] - dp[rightX][leftY-1] + dp[leftX-1][leftY-1] << endl;
	}
	
	return 0;
}
