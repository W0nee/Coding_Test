#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string.h>
#include <algorithm>
using namespace std;

int row, col;
int Map[1010][1010];
int paint[1010][1010];
map<int, int> paint_cnt;
int visited[1010][1010];
int result[1010][1010];
int cnt;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int safe(int x, int y)
{
	if(1 <= x && x <= row && 1 <= y && y <= col)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void painting(int x, int y, int color)
{
	queue<pair<int, int>> q;
	
	q.push({x, y});
	visited[x][y] = 1;
	int cnt = 1;
	
	while(!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();
		
		paint[x][y] = color;
		
		for(int i = 0; i < 4; i++)
		{
			int nx = x+dx[i];
			int ny = y+dy[i];
			
			if(safe(nx, ny) == 1 && Map[nx][ny] == 0 && visited[nx][ny] == 0)
			{
				visited[nx][ny] = 1;
				q.push({nx, ny});
				++cnt;
			}
		}	
	}
	
	paint_cnt[color] = cnt;
}

void BFS(int x, int y)
{
	queue<pair<int, int>> q;
	map<pair<int, int>, int> visited;
	map<int, int> visited_color;
	
	q.push({x, y});
	visited[{x, y}] = 1;
	cnt = 1;
	
	while(!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();
		
		for(int i = 0; i < 4; i++)
		{
			int nx = x+dx[i];
			int ny = y+dy[i];
			
			if(safe(nx, ny) == 1 && Map[nx][ny] == 0 && visited[{nx, ny}] == 0 && visited_color[paint[nx][ny]] == 0)
			{
				visited[{nx, ny}] = 1;
				visited_color[paint[nx][ny]] = 1;
				cnt += paint_cnt[paint[nx][ny]];
			}
		}	
	}
}

int main(void)
{
//	freopen("B16946_input.txt", "r", stdin);
	
	cin >> row >> col;
	
	for(int i = 1; i <= row; i++)
	{
		for(int j = 1; j <= col; j++)
		{
			scanf("%1d", &Map[i][j]);
		}
	}
	
	int color = 0;
	for(int i = 1; i <= row; i++)
	{
		for(int j = 1; j <= col; j++)
		{
			if(Map[i][j] == 0 && visited[i][j] == 0)
			{
				++color;
				painting(i, j, color);
			}
		}
	}
	
	for(int i = 1; i <= row; i++)
	{
		for(int j = 1; j <= col; j++)
		{
			if(Map[i][j] == 1)
			{
				BFS(i, j);
				result[i][j] = cnt % 10;	
			}
		}
	}
	
	for(int i = 1; i <= row; i++)
	{
		for(int j = 1; j <= col; j++)
		{
			cout << result[i][j];
//			cout << paint[i][j];
		}
		cout << "\n";
	}
	
	return 0;
}
