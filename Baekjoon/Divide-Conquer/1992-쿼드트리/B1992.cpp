#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

int N;
int Map[70][70];

int check(int x, int y, int size)
{
	int val = Map[x][y];
	
	for(int i = x; i < x+size; i++)
	{
		for(int j = y; j < y+size; j++)
		{
			if(val != Map[i][j])
			{
				return 0;
			}
		}
	}
	
	return 1;
}

void solve(int x, int y, int size)
{
	if(check(x, y, size))
	{
		cout << Map[x][y];
		return;	
	}
	
	cout << "(";
	solve(x, y, size/2);
	solve(x, y+size/2, size/2);
	solve(x+size/2, y, size/2);
	solve(x+size/2, y+size/2, size/2);
	cout << ")";
	
	return;
}

int main(void)
{
//	freopen("B1992_input.txt", "r", stdin);
	
	cin >> N;
	
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			scanf("%1d", &Map[i][j]);
		}
	}
	
	solve(1, 1, N);
	
	return 0;
}
