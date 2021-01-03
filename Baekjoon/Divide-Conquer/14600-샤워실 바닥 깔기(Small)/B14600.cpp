#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <math.h>
#include <string>
#include <algorithm>
using namespace std;

int K;
int x, y;
int Map[300][300];
int cnt;

int check(int x, int y, int size)
{
	for(int i = y; i < y+size; i++)
	{
		for(int j = x; j < x+size; j++)
		{
			if(Map[i][j] != 0)
			{
				return 0;
			}
		}
	}
	
	return 1;
}

void divide(int x, int y, int size)
{
	cnt++;
	if(check(x, y, (size >> 1))) Map[y + (size >> 1) - 1][x + (size >> 1) - 1] = cnt;
	if(check(x + (size >> 1), y, (size >> 1))) Map[y + (size >> 1) - 1][x + (size >> 1)] = cnt;
	if(check(x, y + (size >> 1), (size >> 1))) Map[y + (size >> 1)][x + (size >> 1) - 1] = cnt;
	if(check(x + (size >> 1), y + (size >> 1), (size >> 1))) Map[y + (size >> 1)][x + (size >> 1)] = cnt;
	
	if(size == 2)
	{
		return;
	}
	
	divide(x, y, (size >> 1));
	divide(x + (size >> 1), y, (size >> 1));
	divide(x, y + (size >> 1), (size >> 1));
	divide(x + (size >> 1), y + (size >> 1), (size >> 1));
}

int main(void)
{
//	freopen("B14600_input.txt", "r", stdin);
	
	cin >> K >> x >> y;
	
	Map[y][x] = -1;
	
	divide(1, 1, 1 << K);
	
	for(int i = (1 << K); i >= 1; i--)
	{
		for(int j = 1; j <= (1 << K); j++)
		{
			cout << Map[i][j] << " ";
		}
		cout << "\n";
	}
	
	return 0;
}
