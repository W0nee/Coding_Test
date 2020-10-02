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
	int zeroCnt = 0;
	int oneCnt = 0;
	
	for(int i = x; i < x+size; i++)
	{
		for(int j = y; j < y+size; j++)
		{
			if(Map[i][j] == 0)
			{
				zeroCnt++;
			}
			else
			{
				oneCnt++;
			}
		}
	}
	
	if(zeroCnt == size*size)
	{
		return 0;
	}
	else if(oneCnt == size*size)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}

string solve(int x, int y, int size)
{
	if(check(x, y, size) == 0)
	{
		return "0";
	}
	else if(check(x, y, size) == 1)
	{
		return "1";		
	}
	
	string str1 = solve(x, y, size/2);
	string str2 = solve(x, y+size/2, size/2);
	string str3 = solve(x+size/2, y, size/2);
	string str4 = solve(x+size/2, y+size/2, size/2);
	
	return "(" + str1 + str2 + str3 + str4 + ")";
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
	
	cout << solve(1, 1, N);
	
	return 0;
}
