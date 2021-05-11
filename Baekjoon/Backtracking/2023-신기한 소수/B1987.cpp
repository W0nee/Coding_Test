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

int row, col;
char Map[25][25];
int alphabet[26];
int Max;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int safe(int x, int y)
{
	if(1 <= x && x <= row && 1 <= y && y <= col)
	{
		return 1;
	}
	
	return 0;
}

void solve(int x, int y, int cnt)
{
	Max = max(Max, cnt);
	
	for(int i = 0; i < 4; i++)
	{
		int nx = x+dx[i];
		int ny = y+dy[i];
		
		if(safe(nx, ny) == 0)
		{
			continue;
		}
		
		if(alphabet[Map[nx][ny]-'A'] == 0)
		{
			alphabet[Map[nx][ny]-'A'] = 1;
			solve(nx, ny, cnt+1);
			alphabet[Map[nx][ny]-'A'] = 0;
		}
	}
}

int main(void)
{
//	freopen("B1987_input.txt", "r", stdin);

	cin >> row >> col;
	
	for(int i = 1; i <= row; i++)
	{
		for(int j = 1; j <= col; j++)
		{
			cin >> Map[i][j];
		}
	}
	
	alphabet[Map[1][1]-'A'] = 1;
	solve(1, 1, 1);
	
	cout << Max;
	
	return 0;
}
