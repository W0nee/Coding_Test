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

typedef struct node
{
	int x;
	int y;
	int dir;
}node;

int row, col;
int Map[110][110];
int startX, startY, startDir;
int arriveX, arriveY, arriveDir;

int dx[5] = {0, 0, 0, 1, -1};
int dy[5] = {0, 1, -1, 0, 0};

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
	queue<node> q;
	int visited[110][110][5] = {0};
	
	q.push({startX, startY, startDir});
	visited[startX][startY][startDir] = 1;
	
	while(!q.empty())
	{
		int x = q.front().x;
		int y = q.front().y;
		int dir = q.front().dir;
		q.pop();
		
		if(x == arriveX && y == arriveY && dir == arriveDir)
		{
			cout << visited[x][y][dir] - 1;
			return;
		}
		
		// Go 1, 2, 3
		for(int i = 1; i <= 3; i++)
		{
			int nx = x + dx[dir] * i;
			int ny = y + dy[dir] * i;
			
			if(safe(nx, ny) == 0 || Map[nx][ny] == 1)
			{
				break;
			}
			
			if(Map[nx][ny] == 0 && visited[nx][ny][dir] == 0)
			{
				q.push({nx, ny, dir});
				visited[nx][ny][dir] = visited[x][y][dir] + 1;
			}
		}
		
		// Turn Left, Right
		if(dir == 1)
		{
			if(visited[x][y][4] == 0)
			{
				q.push({x, y, 4});
				visited[x][y][4] = visited[x][y][dir] + 1;
			}
			
			if(visited[x][y][3] == 0)
			{
				q.push({x, y, 3});
				visited[x][y][3] = visited[x][y][dir] + 1;
			}
		}
		else if(dir == 2)
		{
			if(visited[x][y][3] == 0)
			{
				q.push({x, y, 3});
				visited[x][y][3] = visited[x][y][dir] + 1;
			}
			
			if(visited[x][y][4] == 0)
			{
				q.push({x, y, 4});
				visited[x][y][4] = visited[x][y][dir] + 1;
			}
		}	
		else if(dir == 3)
		{
			if(visited[x][y][1] == 0)
			{
				q.push({x, y, 1});
				visited[x][y][1] = visited[x][y][dir] + 1;
			}
			
			if(visited[x][y][2] == 0)
			{
				q.push({x, y, 2});
				visited[x][y][2] = visited[x][y][dir] + 1;
			}
		}	
		else if(dir == 4)
		{
			if(visited[x][y][2] == 0)
			{
				q.push({x, y, 2});
				visited[x][y][2] = visited[x][y][dir] + 1;
			}
			
			if(visited[x][y][1] == 0)
			{
				q.push({x, y, 1});
				visited[x][y][1] = visited[x][y][dir] + 1;
			}
		}	
	}	
}

int main(void)
{
//	freopen("B1726_input.txt", "r", stdin);
	
	cin >> row >> col;
	
	for(int i = 1; i <= row; i++)
	{
		for(int j = 1; j <= col; j++)
		{
			cin >> Map[i][j];
		}
	}
	
	cin >> startX >> startY >> startDir;
	cin >> arriveX >> arriveY >> arriveDir;
	
	BFS();
	
	return 0;
}
