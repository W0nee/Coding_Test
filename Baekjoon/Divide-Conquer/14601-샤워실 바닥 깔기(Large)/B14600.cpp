#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int row, col;
int Map[150][150];
int cnt;

bool check(int x, int y, int len)
{
	for(int i = x; i < x+len; i++)
	{
		for(int j = y; j < y+len; j++)
		{
			if(Map[i][j] != 0)
			{
				return false;
			}
		}
	}
	
	return true;
}

void paint(int x, int y, int len)
{
	cnt++;
	int nlen = len / 2;
	
	if(check(x, y, nlen)) Map[x+nlen-1][y+nlen-1] = cnt;
	if(check(x, y+nlen, nlen)) Map[x+nlen-1][y+nlen] = cnt;
	if(check(x+nlen, y, nlen)) Map[x+nlen][y+nlen-1] = cnt;
	if(check(x+nlen, y+nlen, nlen)) Map[x+nlen][y+nlen] = cnt;
	if(len == 2) return;
	
	paint(x, y, nlen);
	paint(x, y+nlen, nlen);
	paint(x+nlen, y, nlen);
	paint(x+nlen, y+nlen, nlen);
}

void print()
{
	for(int i = pow(2, N); i >= 1; i--)
	{
		for(int j = 1; j <= pow(2, N); j++)
		{
			cout << Map[i][j] << " ";
		}
		cout << endl;
	}
}

int main(void)
{
//	freopen("B14600_input.txt", "r", stdin);
	
	cin >> N >> col >> row;
	
	Map[row][col] = -1;
	
	paint(1, 1, pow(2, N));
	
	print();
	
	return 0;
}
