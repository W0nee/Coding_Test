#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct node
{
	int x;
	int y;
	int dir;
}node;

char Map[110][110];
int visited[110][110][4];
int dist[110][110][4];

int startX, startY = -1;
int arriveX, arriveY;
int row, col;
int ans = 99999999;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int safe(int x, int y)
{
	if(0 <= x && x < row && 0 <= y && y < col)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void BFS(int x, int y)
{
	queue<node> q;
	
	for(int i = 0; i < 4; i++)
	{
		q.push({x, y, i});
		visited[x][y][i] = 1;
		dist[x][y][i] = 0;
	}
	
	while(!q.empty())
	{
		x = q.front().x;
		y = q.front().y;
		int dir = q.front().dir;
		q.pop();
		
		for(int i = 0; i < 4; i++)
		{
			int nx = x+dx[i];
			int ny = y+dy[i];
			int ndir = i;
			
			if(safe(nx, ny) == 0)
			{
				continue;
			}
			
			if(Map[nx][ny] == '.' && visited[nx][ny][ndir] == 0)
			{
				// 전과 같은방향 -> 거울그대로 
				if(dir == ndir)
				{
					q.push({nx, ny, ndir});
					visited[nx][ny][ndir] = 1;
					dist[nx][ny][ndir] = dist[x][y][dir];
				}
				// 전과 다른방향 -> 거울추가 
				else
				{
					q.push({nx, ny, ndir});
					visited[nx][ny][ndir] = 1;
					dist[nx][ny][ndir] = dist[x][y][dir] + 1;
				}
			}
			else if(Map[nx][ny] == '.' && visited[nx][ny][ndir] == 1 && dist[x][y][dir] < dist[nx][ny][ndir])
			{
				// 전과 같은방향 -> 거울그대로 
				if(dir == ndir)
				{
					q.push({nx, ny, ndir});
					dist[nx][ny][ndir] = dist[x][y][dir];
				}
				// 전과 다른방향 -> 거울추가 
				else
				{
					q.push({nx, ny, ndir});
					dist[nx][ny][ndir] = dist[x][y][dir] + 1;
				}
			}
			// 도착점 
			else if(nx == arriveX && ny == arriveY)
			{
				// 전과 같은방향 -> 거울그대로 
				if(dir == ndir)
				{
					ans = min(ans, dist[x][y][dir]);	
				}
				// 전과 다른방향 -> 거울추가 
				else
				{
					ans = min(ans, dist[x][y][dir] + 1);
				}
			}
		}
	}
}

int main(void)
{
//	freopen("B6087_input.txt", "r", stdin);

	cin >> col >> row;
	
	for(int i = 0; i < row; i++)
	{
		string input;
		cin >> input;
		
		for(int j = 0; j < col; j++)
		{
			Map[i][j] = input[j];
			
			if(Map[i][j] == 'C' && startY == -1)
			{
				startX = i;
				startY = j;
			}
			else if(Map[i][j] == 'C' && startY != -1)
			{
				arriveX = i;
				arriveY = j;
			}
			
			for(int k = 0; k < 4; k++)
			{
				dist[i][j][k] = 99999999;
			}
		}
	}
	
	BFS(startX, startY);
	
	cout << ans;
	
	return 0;
}
