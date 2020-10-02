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

int Map[1010][1010];
int visited[1010][1010][4];
int dist[1010][1010][4]; 

int row, col, crash;
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

void BFS()
{
	queue<node> q;
	
	for(int i = 0; i < 4; i++)
	{
		q.push({0, 0, i});
		visited[0][0][i] = 1;
		dist[0][0][i] = 0;
	}
	
	while(!q.empty())
	{
		int x = q.front().x;
		int y = q.front().y;
		int dir = q.front().dir;
		q.pop();
		
		if(x == row-1 && y == col-1)
		{
			ans = min(ans, visited[x][y][dir]);
		}
		
		for(int i = 0; i < 4; i++)
		{
			int nx = x+dx[i];
			int ny = y+dy[i];
			int ndir = i;
			
			if(safe(nx, ny) == 0)
			{
				continue;
			}
			
			if(Map[nx][ny] == 0 && visited[nx][ny][ndir] == 0)
			{
				q.push({nx, ny, ndir});
				visited[nx][ny][ndir] = visited[x][y][dir] + 1;
				dist[nx][ny][ndir] = dist[x][y][dir];
			}
			else if(Map[nx][ny] == 0 && visited[nx][ny][ndir] != 0 && dist[x][y][dir] < dist[nx][ny][ndir])
			{
				q.push({nx, ny, ndir});
				visited[nx][ny][ndir] = visited[x][y][dir] + 1;
				dist[nx][ny][ndir] = dist[x][y][dir];
			}
			else if(Map[nx][ny] == 1 && visited[nx][ny][ndir] == 0 && dist[x][y][dir] + 1 <= crash)
			{
				q.push({nx, ny, ndir});
				visited[nx][ny][ndir] = visited[x][y][dir] + 1;
				dist[nx][ny][ndir] = dist[x][y][dir] + 1;
			}
			else if(Map[nx][ny] == 1 && visited[nx][ny][ndir] != 0 && dist[x][y][dir] + 1 < dist[nx][ny][ndir] && dist[x][y][dir] + 1 <= crash)
			{
				q.push({nx, ny, ndir});
				visited[nx][ny][ndir] = visited[x][y][dir] + 1;
				dist[nx][ny][ndir] = dist[x][y][dir] + 1;
			}
		}
	}
}

int main(void)
{
//	freopen("B14442_input.txt", "r", stdin);

	cin >> row >> col >> crash;
	
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
		{
			scanf("%1d", &Map[i][j]);
			
			for(int k = 0; k < 4; k++)
			{
				dist[i][j][k] = 99999999;	
			}
		}
	}
	
	BFS();
	
	if(ans == 99999999)
	{
		cout << -1;
	}
	else
	{
		cout << ans;
	}
	
	return 0;
}
