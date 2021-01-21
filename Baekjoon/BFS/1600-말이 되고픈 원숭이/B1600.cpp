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

typedef struct node
{
	int x;
	int y;
	int cnt;
}node;

int K;
int row, col;
int Map[210][210];
int visited[210][210][35];
int ans;

int dx[12] = {0, 0, 1, -1, -1, -2, -2, -1, 1, 2, 2, 1};
int dy[12] = {1, -1, 0, 0, -2, -1, 1, 2, 2, 1, -1, -2};

int safe(int x, int y)
{
	if(1 <= x && x <= row && 1 <= y && y <= col)
	{
		return 1;
	}
	
	return 0;
}

int BFS()
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
			ans = visited[row][col][cnt] - 1;
			return 1;
		}
		
		for(int i = 0; i < 12; i++)
		{
			int nx = x+dx[i];
			int ny = y+dy[i];
			
			if(safe(nx, ny) == 0)
			{
				continue;
			}
			
			if(4 <= i && i < 12)
			{
				if(Map[nx][ny] == 0 && visited[nx][ny][cnt+1] == 0 && cnt+1 <= K)
				{
					q.push({nx, ny, cnt+1});
					visited[nx][ny][cnt+1] = visited[x][y][cnt] + 1;
				}	
			}
			else
			{
				if(Map[nx][ny] == 0 && visited[nx][ny][cnt] == 0)
				{
					q.push({nx, ny, cnt});
					visited[nx][ny][cnt] = visited[x][y][cnt] + 1;
				}
			}
		}
	}
	
	return 0;
}

int main(void)
{
//	freopen("B1600_input.txt", "r", stdin);
	
	cin >> K >> col >> row;
	
	for(int i = 1; i <= row; i++)
	{
		for(int j = 1; j <= col; j++)
		{
			cin >> Map[i][j];
		}
	}
	
	if(BFS() == 1)
	{
		cout << ans;
	}
	else
	{
		cout << "-1";
	}
	
	return 0;
}
