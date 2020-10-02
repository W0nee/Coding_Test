#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int row, col;
int Map[1010][1010];
int Max;

int main(void)
{
//	freopen("B1915_input.txt", "r", stdin);
	
	cin >> row >> col;
	
	for(int i = 1; i <= row; i++)
	{
		for(int j = 1; j <= col; j++)
		{
			scanf("%1d", &Map[i][j]);
		}
	}
	
	for(int i = 1; i <= row; i++)
	{
		for(int j = 1; j <= col; j++)
		{		
			int Min = min({Map[i-1][j], Map[i][j-1], Map[i-1][j-1]});

			if(Map[i][j] != 0)
			{
				Map[i][j] = Min+1;
			}

			Max = max(Max, Map[i][j]);
		}
	}
	
	cout << Max * Max;
	
	return 0;
}
