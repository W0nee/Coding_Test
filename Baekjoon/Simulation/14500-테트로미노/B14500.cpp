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
int Map[550][550];
int visited[550][550];
int Max;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int safe(int x, int y)
{
	if(1 <= x && x <= row && 1 <= y && y <= col)
	{
		return 1;
	}
	
	return 0;
}

void DFS(int x, int y, int val, int cnt)
{
	if(cnt == 4)
	{
		Max = max(Max, val);
		return;
	}
	
	for(int i = 0; i < 4; i++)
	{
		int nx = x+dx[i];
		int ny = y+dy[i];
		
		if(safe(nx, ny))
		{
			if(visited[nx][ny] == 0)
			{
				visited[nx][ny] = 1;
				DFS(nx, ny, val+Map[nx][ny], cnt+1);	
				visited[nx][ny] = 0;
			}
		}
	}
}

void solve(int x, int y)
{
	// ぬ
	int val = 0;
	if(safe(x, y+2))
	{
		val += Map[x][y] + Map[x][y+1] + Map[x+1][y+1] + Map[x][y+2];	
	}
	Max = max(Max, val);   
	
	// っ 
	val = 0;
	if(safe(x+2, y-1))
	{
		val += Map[x][y] + Map[x+1][y] + Map[x+1][y-1] + Map[x+2][y];
	}
	Max = max(Max, val);   
	
	// で 
	val = 0;
	if(safe(x-1, y+2))
	{
		val += Map[x][y] + Map[x][y+1] + Map[x-1][y+1] + Map[x][y+2];	
	}
	Max = max(Max, val);   
	
	// た 
	val = 0;
	if(safe(x+2, y))
	{
		val += Map[x][y] + Map[x+1][y] + Map[x+1][y+1] + Map[x+2][y];	
	}
	Max = max(Max, val);     
}

int main(void)
{
//	freopen("B14500_input.txt", "r", stdin);
	
	cin >> row >> col;
	
	for(int i = 1; i <= row; i++)
	{
		for(int j = 1; j <= col; j++)
		{
			cin >> Map[i][j];
		}
	}
	
	for(int i = 1; i <= row; i++)
	{
		for(int j = 1; j <= col; j++)
		{
			visited[i][j] = 1;
			DFS(i, j, Map[i][j], 1);
			solve(i, j);
			visited[i][j] = 0;
		}
	}
	
	cout << Max;
	
	return 0;
}
