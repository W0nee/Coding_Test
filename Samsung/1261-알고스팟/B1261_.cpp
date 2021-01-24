#include <iostream>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <string>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int row, col;
int Map[110][110];

queue<pair<int, int>> q;
int visited[110][110];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int safe(int x, int y)
{
	if(1 <= x && x <= row && 1 <= y && y <= col)
	{
		return 1;
	}
	
	return 0;
}

void BFS()
{
	q.push({1, 1});
	visited[1][1] = 0;
	
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
			
			if(Map[nx][ny] == 0 && visited[x][y] < visited[nx][ny])
			{
				q.push({nx, ny});
				visited[nx][ny] = visited[x][y];
			}
			else if(Map[nx][ny] == 1 && visited[x][y] + 1 < visited[nx][ny])
			{
				q.push({nx, ny});
				visited[nx][ny] = visited[x][y] + 1;
			}
		}
	}
}

int main(void)
{
//	freopen("B1261_input.txt", "r", stdin);
	
	cin >> col >> row;
	
	for(int i = 1; i <= row; i++)
	{
		for(int j = 1; j <= col; j++)
		{
			scanf("%1d", &Map[i][j]);
			
			visited[i][j] = 987654321;
		}
	}
	
	BFS();
	
	cout << visited[row][col];
	
	return 0;
}
