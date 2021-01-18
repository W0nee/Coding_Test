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

int Map[10][10];
vector<pair<int, int>> Empty;
bool Flag = false;

int check_garo(int x, int y, int num)
{
	for(int i = 0; i < 9; i++)
	{
		if(Map[x][i] == num)
		{
			return 0;
		}
	}
	
	return 1;	
}

int check_sero(int x, int y, int num)
{
	for(int i = 0; i < 9; i++)
	{
		if(Map[i][y] == num)
		{
			return 0;
		}
	}
	
	return 1;
}

int check_33(int x, int y, int num)
{
	int startX = 3 * (x / 3);
	int startY = 3 * (y / 3);
	
	for(int i = startX; i < startX+3; i++)
	{
		for(int j = startY; j < startY+3; j++)
		{
			if(Map[i][j] == num)
			{
				return 0;
			}
		}
	}
	
	return 1;
}

void solve(int idx, int cnt)
{
	if(cnt == Empty.size())
	{
		Flag = true;
		return;
	}
	
	for(int i = 1; i <= 9; i++)
	{
		int x = Empty[idx].first;
		int y = Empty[idx].second;
		
		if(check_garo(x, y, i) && check_sero(x, y, i) && check_33(x, y, i))
		{
			Map[x][y] = i;
			solve(idx+1, cnt+1);
			if(Flag)
			{
				return;
			}
			Map[x][y] = 0;
		}
	}
}

int main(void)
{
//	freopen("B2580_input.txt", "r", stdin);

	for(int i = 0; i < 9; i++)
	{
		for(int j = 0; j < 9; j++)
		{
			cin >> Map[i][j];
			
			if(Map[i][j] == 0)
			{
				Empty.push_back({i, j});
			}
		}
	}
	
	solve(0, 0);
	
	for(int i = 0; i < 9; i++)
	{
		for(int j = 0; j < 9; j++)
		{
			cout << Map[i][j] << " ";
		}
		cout << "\n";
	}
	
	return 0;
}
