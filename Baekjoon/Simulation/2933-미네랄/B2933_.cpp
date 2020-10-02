#include <stdio.h>
#include <iostream>
#include <queue>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;

int row, col;
char Map[110][110];
int visited[110][110];
int N;

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

void down(int Min)
{
	for(int i = row; i >= 1; i--)
	{
		for(int j = 1; j <= col; j++)
		{
			if(Map[i][j] == 'x' && visited[i][j] == 0)
			{	
				Map[i+Min][j] = 'x';	
				Map[i][j] = '.';
			}
		}
	}
}

void DFS(int x, int y)
{
	visited[x][y] = 1;
	
	for(int i = 0; i < 4; i++)
	{
		int nx = x+dx[i];
		int ny = y+dy[i];
		
		if(safe(nx, ny) == 0)
		{
			continue;
		}
		
		if(Map[nx][ny] == 'x'  && visited[nx][ny] == 0)
		{
			DFS(nx, ny);
		}
	}
}

void crash(int h, int dir)
{
	if(dir == 1)
	{
		for(int j = 1; j <= col; j++)
		{
			if(Map[h][j] == 'x')
			{
				Map[h][j] = '.';
				return;
			}
		}
	}
	else
	{
		for(int j = col; j >= 1; j--)
		{
			if(Map[h][j] == 'x')
			{
				Map[h][j] = '.';
				return;
			}
		}
	}
}

int main(void)
{
//	freopen("B2933_input.txt", "r", stdin);
	
	cin >> row >> col;

	for(int i = 1; i <= row; i++)
	{
		for(int j = 1; j <= col; j++)
		{
			cin >> Map[i][j];
		}
	}
	
	cin >> N;
	
	for(int n = 1; n <= N; n++)
	{
		int h;
		cin >> h;
		
		if(n % 2)
		{
			crash(row-h+1, 1);
		}
		else
		{
			crash(row-h+1, 2);
		}
		
		memset(visited, 0, sizeof(visited));
		
		for(int j = 1; j <= col; j++)
		{
			if(Map[row][j] == 'x' && visited[row][j] == 0)
			{
				DFS(row, j);
			}
		}
		
		vector<pair<int,int>> v;
		for(int j = 1; j <= col; j++)
		{
			for(int i = row; i >= 1; i--)
			{
				if(Map[i][j] == 'x' && visited[i][j] == 0)
				{
					v.push_back({i, j});
					break;
				}
			}
		}
		
		int Min = 999999999;
		for(int k = 0; k < v.size(); k++)
		{
			int x = v[k].first;
			int y = v[k].second;
			int downCnt = 0;
			
			for(int i = x+1; i <= row; i++)
			{
				if(Map[i][y] == '.')
				{
					downCnt = i-x;
				}
				else if(Map[i][y] == 'x' && visited[i][y] == 1)
				{
					downCnt = i-x-1;
					break;
				}
			}
			
			Min = min(downCnt, Min);
		}
		
		if(Min != 999999999 && Min != 0)
		{
			down(Min);	
		}
	}
	
	for(int i = 1; i <= row; i++)
	{
		for(int j = 1; j <= col; j++)
		{
			cout << Map[i][j];
		}
		cout << endl;
	}
	
	return 0;
}
