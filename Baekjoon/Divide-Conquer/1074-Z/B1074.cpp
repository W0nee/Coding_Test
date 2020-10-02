#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

int N;
int row, col;
int cnt;
int ans;

void solve(int x, int y, int size)
{
	if(size == 1)
	{
		if(x == row && y == col)
		{
			ans = cnt;
		}
		
		cnt++;
		
		return;
	}
	
	if(!(x <= row && row < x+size && y <= col && col < y+size))
	{
		cnt += size*size;
		return;
	}
	
	solve(x, y, size/2);
	solve(x, y+size/2, size/2);
	solve(x+size/2, y, size/2);
	solve(x+size/2, y+size/2, size/2);
}

int main(void)
{
//	freopen("B1074_input.txt", "r", stdin);
	
	cin >> N >> row >> col;
	
	solve(0, 0, pow(2, N));
	
	cout << ans;
	
	return 0;
}
