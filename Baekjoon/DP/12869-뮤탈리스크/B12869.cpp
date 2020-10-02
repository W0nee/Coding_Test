#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 999999999;

int N;
int scv[5];
int dp2[70][70];
int dp3[70][70][70];

int solve2(int a, int b)
{
	if(a < 0) a = 0;
	if(b < 0) b = 0;
	
	if(a == 0 && b == 0)
	{
		return 0;
	}
	
	if(dp2[a][b] != 0)
	{
		return dp2[a][b];
	}
	dp2[a][b] = INF;
	
	dp2[a][b] = min(dp2[a][b], 1 + solve2(a-9, b-3));
	dp2[a][b] = min(dp2[a][b], 1 + solve2(a-3, b-9));
	
	return dp2[a][b];
}

int solve3(int a, int b, int c)
{
	if(a < 0) a = 0;
	if(b < 0) b = 0;
	if(c < 0) c = 0;
	
	if(a == 0 && b == 0 && c == 0)
	{
		return 0;
	}
	
	if(dp3[a][b][c] != 0)
	{
		return dp3[a][b][c];
	}
	dp3[a][b][c] = INF;
	
	dp3[a][b][c] = min(dp3[a][b][c], 1 + solve3(a-9, b-3, c-1));
	dp3[a][b][c] = min(dp3[a][b][c], 1 + solve3(a-9, b-1, c-3));
	dp3[a][b][c] = min(dp3[a][b][c], 1 + solve3(a-3, b-9, c-1));
	dp3[a][b][c] = min(dp3[a][b][c], 1 + solve3(a-3, b-1, c-9));
	dp3[a][b][c] = min(dp3[a][b][c], 1 + solve3(a-1, b-3, c-9));
	dp3[a][b][c] = min(dp3[a][b][c], 1 + solve3(a-1, b-9, c-3));
	
	return dp3[a][b][c];
}

int main(void)
{
//	freopen("B12869_input.txt", "r", stdin);
	
	cin >> N;
	
	for(int i = 1; i <= N; i++)
	{
		cin >> scv[i];
	}
	
	if(N == 1)
	{
		if(scv[1] % 9 == 0)
		{
			cout << scv[1] / 9;
		}
		else
		{
			cout << scv[1] / 9 + 1;	
		}
	}
	else if(N == 2)
	{
		cout << solve2(scv[1], scv[2]);
	}
	else
	{
		cout << solve3(scv[1], scv[2], scv[3]);
	}
	
	return 0;
}
