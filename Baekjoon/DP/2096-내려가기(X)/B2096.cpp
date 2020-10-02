#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int Map[100010][4];
int dp1[100010][4];
int dp2[100010][4];

int solve1(int row, int col)
{
	if(row == N+1)
	{
		return 0;
	}
	
	if(dp1[row][col] != 0)
	{
		return dp1[row][col];
	}
	
	if(col == 1)
	{
		dp1[row][col] = max({dp1[row][col], Map[row][col] + solve1(row+1, 1), Map[row][col] + solve1(row+1, 2)});
	}
	else if(col == 2)
	{
		dp1[row][col] = max({dp1[row][col], Map[row][col] + solve1(row+1, 1), Map[row][col] + solve1(row+1, 2),  Map[row][col] + solve1(row+1, 3)});
	}
	else if(col == 3)
	{
		dp1[row][col] = max({dp1[row][col], Map[row][col] + solve1(row+1, 2), Map[row][col] + solve1(row+1, 3)});
	}
	
	return dp1[row][col];
}

int solve2(int row, int col)
{
	if(row == N+1)
	{
		return 0;
	}
	
	if(dp2[row][col] != 0)
	{
		return dp2[row][col];
	}
	dp2[row][col] = 99999999;
	
	if(col == 1)
	{
		dp2[row][col] = min({dp2[row][col], Map[row][col] + solve2(row+1, 1), Map[row][col] + solve2(row+1, 2)});
	}
	else if(col == 2)
	{
		dp2[row][col] = min({dp2[row][col], Map[row][col] + solve2(row+1, 1), Map[row][col] + solve2(row+1, 2),  Map[row][col] + solve2(row+1, 3)});
	}
	else if(col == 3)
	{
		dp2[row][col] = min({dp2[row][col], Map[row][col] + solve2(row+1, 2), Map[row][col] + solve2(row+1, 3)});
	}
	
	return dp2[row][col];
}

int main(void)
{
//	freopen("B2096_input.txt", "r", stdin);
	
	cin >> N;
	
	for(int i = 1; i <= N; i++)
	{
		cin >> Map[i][1] >> Map[i][2] >> Map[i][3];
	}

	cout << max({solve1(1, 1), solve1(1, 2), solve1(1, 3)}) << " ";
	cout << min({solve2(1, 1), solve2(1, 2), solve2(1, 3)});
	
	return 0;
}
