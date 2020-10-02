#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int Map[1010][1010];
int visited[1010][1010];
int dist[1010][1010];

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

void BFS(int x, int y)
{
	queue<pair<int, int>> q;
	
	q.push({x, y});
	visited[x][y] = 1;
	dist[x][y] = 0;
	
	while(!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();
		
		if(x == row-1 && y == col-1)
		{
			ans = min(ans, visited[x][y]);
		}
		
		for(int i = 0; i < 4; i++)
		{
			int nx = x+dx[i];
			int ny = y+dy[i];
			
			if(safe(nx, ny) == 0)
			{
				continue;
			}
			
			if(Map[nx][ny] == 0 && visited[nx][ny] == 0)
			{
				q.push({nx, ny});
				visited[nx][ny] = visited[x][y] + 1;
				dist[nx][ny] = dist[x][y];
			}
			else if(Map[nx][ny] == 0 && visited[nx][ny] != 0 && dist[x][y] < dist[nx][ny])
			{
				q.push({nx, ny});
				visited[nx][ny] = visited[x][y] + 1;
				dist[nx][ny] = dist[x][y];
			}
			else if(Map[nx][ny] == 1 && visited[nx][ny] == 0 && dist[x][y] + 1 <= crash)
			{
				q.push({nx, ny});
				visited[nx][ny] = visited[x][y] + 1;
				dist[nx][ny] = dist[x][y] + 1;
			}
			else if(Map[nx][ny] == 1 && visited[nx][ny] != 0 && dist[x][y] + 1 < dist[nx][ny] && dist[x][y] + 1 <= crash)
			{
				q.push({nx, ny});
				visited[nx][ny] = visited[x][y] + 1;
				dist[nx][ny] = dist[x][y] + 1;
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
			
			dist[i][j] = 99999999;
		}
	}
	
	BFS(0, 0);
	
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
