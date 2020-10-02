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
char Map[1010][1010];
int visited[1010][1010];
bool flag;
int newColor;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void DFS(int x, int y, int color)
{
	int nx, ny;
	if(Map[x][y] == 'U')
	{
		nx = x+dx[0];
		ny = y+dy[0];
	}
	else if(Map[x][y] == 'D')
	{
		nx = x+dx[1];
		ny = y+dy[1];
	}
	else if(Map[x][y] == 'L')
	{
		nx = x+dx[2];
		ny = y+dy[2];
	}
	else if(Map[x][y] == 'R')
	{
		nx = x+dx[3];
		ny = y+dy[3];
	}
	
	if(visited[nx][ny] == 0)
	{
		visited[nx][ny] = color;
		DFS(nx, ny, color);
		if(flag)
		{
			visited[nx][ny] = newColor;
		}
	}
	else if(visited[nx][ny] != color)
	{
		newColor = visited[nx][ny];
		flag = true;
	}
}

int main(void)
{
//	freopen("B16724_input.txt", "r", stdin);
	
	cin >> row >> col;
	
	for(int i = 1; i <= row; i++)
	{
		for(int j = 1; j <= col; j++)
		{
			cin >> Map[i][j];
		}
	}
	
	int cnt = 0;
	for(int i = 1; i <= row; i++)
	{
		for(int j = 1; j <= col; j++)
		{
			if(visited[i][j] == 0)
			{
				flag = false;
				visited[i][j] = ++cnt;
				DFS(i, j, cnt);
				if(flag)
				{
					visited[i][j] = newColor;
					cnt--;
				}
			}
		}
	}
	
	cout << cnt;
	
	return 0;
}
