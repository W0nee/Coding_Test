#include <stdio.h>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int Map[110][110];
int visited[110][110];
int dist[110][110];
int row, col;
int Min = 99999999;

int dx[4] = {-1, 1, 0, 0}; // »óÇÏÁÂ¿ì 
int dy[4] = {0, 0, -1, 1}; // »óÇÏÁÂ¿ì

int safe(int x, int y)
{
	if(x >= 0 && y >= 0 && x < row && y < col)
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
	queue<pair<int, int>> q;
	
	q.push({0, 0});
	visited[0][0] = 1;
	dist[0][0] = 0;
	
	while(!q.empty())
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
			
			if(Map[nx][ny] == 0 && visited[nx][ny] == 0)
			{
				q.push({nx, ny});
				visited[nx][ny] = 1;
				dist[nx][ny] = dist[x][y];
			}
			else if(Map[nx][ny] == 0 && dist[x][y] < dist[nx][ny])
			{
				q.push({nx, ny});
				visited[nx][ny] = 1;
				dist[nx][ny] = dist[x][y];
			}
			else if(Map[nx][ny] == 1 && visited[nx][ny] == 0)
			{
				q.push({nx, ny});
				visited[nx][ny] = 1;
				dist[nx][ny] = dist[x][y] + 1;
			}
			else if(Map[nx][ny] == 1 && dist[x][y] + 1 < dist[nx][ny])
			{
				q.push({nx, ny});
				dist[nx][ny] = dist[x][y] + 1;
			}
		}
	}
}

int main(void)
{
//	freopen("B1261_input.txt", "r", stdin);
	
	scanf("%d %d", &col, &row);
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
		{
			scanf("%1d", &Map[i][j]);
			
			dist[i][j] = 99999999;
		}
	}
	
	BFS();
	
	cout << dist[row-1][col-1];
	
	return 0;
}
