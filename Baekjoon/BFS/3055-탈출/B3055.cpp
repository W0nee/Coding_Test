#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

int row, col;
char Map[55][55];
int time;
bool Flag = false;

queue<pair<int, int>> qq;

queue<pair<int, int>> q;
int visited[110][110];

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

void move()
{
	int cnt = q.size();

	while(cnt--)
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		for(int i = 0; i < 4; i++)
		{
			int nx = x+dx[i];
			int ny = y+dy[i];
			
			if(safe(nx, ny) == 0)
			{
				continue;
			}
			
			if(Map[nx][ny] == '.' && visited[nx][ny] == 0)
			{
				q.push({nx, ny});
				visited[nx][ny] = visited[x][y] + 1;
			}
			else if(Map[nx][ny] == 'D')
			{
				time = visited[x][y];
				Flag = true;
				return;
			}
		}
	}
}

void water()
{
	int cnt = qq.size();
	
	while(cnt--)
	{
		int x = qq.front().first;
		int y = qq.front().second;
		qq.pop();
		
		for(int i = 0; i < 4; i++)
		{
			int nx = x+dx[i];
			int ny = y+dy[i];
			
			if(safe(nx, ny) == 0)
			{
				continue;
			}
			
			if(Map[nx][ny] == '.' || Map[nx][ny] == 'S')
			{
				qq.push({nx, ny});
				Map[nx][ny] = '*';
			}
		}
	}
}

int main(void)
{
//	freopen("B3055_input.txt", "r", stdin);
	
	cin >> row >> col;
	
	for(int i = 1; i <= row; i++)
	{
		string temp; 
		cin >> temp;
		
		for(int j = 1; j <= col; j++)
		{
			Map[i][j] = temp[j-1];
			
			if(Map[i][j] == 'S')
			{
				q.push({i, j});
				visited[i][j] = 1;
			}
			else if(Map[i][j] == '*')
			{
				qq.push({i, j});
			}
		}
	}
	
	while(1)
	{
		water();
		
		move();
		
		if(Flag)
		{
			cout << time;
			break;
		}
		else if(q.empty())
		{
			cout << "KAKTUS";
			break;
		}
	}
	
	return 0;
}
