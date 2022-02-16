#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct node{
	int x;
	int y;
	int cnt;
}node;

int Map[1010][1010];
int visited[1010][1010][11];

int row, col, crash;
int ans = 99999999;

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

void BFS()
{
	queue<node> q;
	
	q.push({1, 1, 0});
	visited[1][1][0] = 1;
	
	while(!q.empty())
	{
		int x = q.front().x;
		int y = q.front().y;
		int cnt = q.front().cnt;
		q.pop();
		
		if(x == row && y == col)
		{
			ans = min(ans, visited[x][y][cnt]);
		}
		
		for(int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(safe(nx, ny) == 0)
			{
				continue;
			}
			
			if(Map[nx][ny] == 0 && visited[nx][ny][cnt] == 0)
			{
				q.push({nx, ny, cnt});
				visited[nx][ny][cnt] = visited[x][y][cnt] + 1;
			}
			else if(Map[nx][ny] == 1 && visited[nx][ny][cnt+1] == 0 && cnt+1 <= crash)
			{
				q.push({nx, ny, cnt+1});
				visited[nx][ny][cnt+1] = visited[x][y][cnt] + 1;
			}
		}
	}
}

int main(void)
{
//	freopen("B14442_input.txt", "r", stdin);

	cin >> row >> col >> crash;
	
	for(int i = 1; i <= row; i++)
	{
		for(int j = 1; j <= col; j++)
		{
			scanf("%1d", &Map[i][j]);
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
