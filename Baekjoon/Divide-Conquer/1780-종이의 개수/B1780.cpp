#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

int N;
int Map[2200][2200];
int zeroCnt;
int oneCnt;
int minusCnt;

int check(int x, int y, int size)
{
	int zero = 0;
	int one = 0;
	int minus = 0;
	
	for(int i = x; i < x+size; i++)
	{
		for(int j = y; j < y+size; j++)
		{
			if(Map[i][j] == 0)
			{
				zero++;
			}
			else if(Map[i][j] == 1)
			{
				one++;
			}
			else if(Map[i][j] == -1)
			{
				minus++;
			}
		}
	}
	
	if(zero == size*size)
	{
		return 0;
	}
	else if(one == size*size)
	{
		return 1;
	}
	else if(minus == size*size)
	{
		return -1;
	}
	else
	{
		return -2;
	}
}

void solve(int x, int y, int size)
{
	if(check(x, y, size) != -2)
	{
		if(Map[x][y] == 0)
		{
			zeroCnt += 1;
		}
		else if(Map[x][y] == 1)
		{
			oneCnt += 1;
		}
		else if(Map[x][y] == -1)
		{
			minusCnt += 1;
		}
		
		return;
	}
	
	solve(x, y, size/3);
	solve(x, y+size/3, size/3);
	solve(x, y+size/3*2, size/3);
	
	solve(x+size/3, y, size/3);
	solve(x+size/3, y+size/3, size/3);
	solve(x+size/3, y+size/3*2, size/3);
	
	solve(x+size/3*2, y, size/3);
	solve(x+size/3*2, y+size/3, size/3);
	solve(x+size/3*2, y+size/3*2, size/3);
}

int main(void)
{
//	freopen("B1992_input.txt", "r", stdin);
	
	cin >> N;
	
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			cin >> Map[i][j];
		}
	}
	
	solve(1, 1, N);
	
	cout << minusCnt << endl;
	cout << zeroCnt << endl;
	cout << oneCnt << endl;
	
	return 0;
}
