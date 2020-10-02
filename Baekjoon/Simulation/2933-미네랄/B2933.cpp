#include <stdio.h>
#include <iostream>
#include <queue>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;

int row, col;
int Map[110][110]; 
char Result[110][110];
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

void down(int mineral)
{
	for(int n = 1; n <= mineral; n++)
	{
		vector<pair<int, int>> v;
		int Min = 999999999;
		
		for(int j = 1; j <= col; j++)
		{
			for(int i = row; i >= 1; i--)
			{
				if(Map[i][j] == n)
				{
					v.push_back({i, j});
					break;
				}
			}
		}	
		
		for(int k = 0; k < v.size(); k++)
		{
			int x = v[k].first;
			int y = v[k].second;
			int downCnt = 0;
			
			for(int i = x+1; i <= row; i++)
			{
				if(Map[i][y] == 0)
				{
					downCnt = i-x;
				}
				else if(Map[i][y] == n)
				{
					downCnt = 0;
					break;
				}
			}
			
			Min = min(downCnt, Min);
		}
		
		if(Min != 999999999 && Min != 0)
		{
			for(int i = row; i >= 1; i--)
			{
				for(int j = 1; j <= col; j++)
				{
					if(Map[i][j] == n)
					{	
						Map[i+Min][j] = n;	
						Map[i][j] = 0;
					}
				}
			}
			
			return;
		}
	}
}

void paint(int x, int y, int cnt)
{
	visited[x][y] = 1;
	Map[x][y] = cnt;
	
	for(int i = 0; i < 4; i++)
	{
		int nx = x+dx[i];
		int ny = y+dy[i];
		
		if(safe(nx, ny) == 0)
		{
			continue;
		}
		
		if(Map[nx][ny] != 0  && visited[nx][ny] == 0)
		{
			paint(nx, ny, cnt);
		}
	}
}

void crash(int h, int dir)
{
	if(dir == 1)
	{
		for(int j = 1; j <= col; j++)
		{
			if(Map[h][j] != 0)
			{
				Map[h][j] = 0;
				return;
			}
		}
	}
	else
	{
		for(int j = col; j >= 1; j--)
		{
			if(Map[h][j] != 0)
			{
				Map[h][j] = 0;
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
			char input;
			cin >> input;
			
			if(input == '.')
			{
				continue;
			}
			else
			{
				Map[i][j] = 1;
			}
		}
	}
	
	cin >> N;
	int mineral = 0;
	
	for(int i = 1; i <= N; i++)
	{
		int h;
		cin >> h;
		
		if(i % 2)
		{
			crash(row-h+1, 1);
		}
		else
		{
			crash(row-h+1, 2);
		}
		
		mineral = 0;
		memset(visited, 0, sizeof(visited));
		
		for(int i = 1; i <= row; i++)
		{
			for(int j = 1; j <= col; j++)
			{
				if(Map[i][j] != 0 && visited[i][j] == 0)
				{
					visited[i][j] = 1;
					paint(i, j, ++mineral);
				}
			}
		}	
		
		down(mineral);
	}
	
	for(int i = 1; i <= row; i++)
	{
		for(int j = 1; j <= col; j++)
		{
			if(Map[i][j] != 0)
			{
				Result[i][j] = 'x';
			}
			else
			{
				Result[i][j] = '.';
			}
		}
	}
	
	for(int i = 1; i <= row; i++)
	{
		for(int j = 1; j <= col; j++)
		{
			cout << Result[i][j];
		}
		cout << endl;
	}
	
	return 0;
}
