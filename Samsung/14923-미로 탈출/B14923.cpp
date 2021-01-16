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
	int magic;
}node;

int row, col;
int startX, startY;
int endX, endY;
int Map[1010][1010];
int visited[1010][1010][2];
int ans;

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

int BFS()
{
	queue<node> q;
	
	q.push({startX, startY, 0});
	visited[startX][startY][0] = 1;
	
	while(!q.empty())
	{
		int x = q.front().x;
		int y = q.front().y;
		int magic = q.front().magic;
		q.pop();
		
		if(x == endX && y == endY)
		{
			ans = visited[x][y][magic]-1;
			return 1;
		}
		
		for(int i = 0; i < 4; i++)
		{
			int nx = x+dx[i];
			int ny = y+dy[i];
			
			if(safe(nx, ny) == 1)
			{
				if(Map[nx][ny] == 0 && visited[nx][ny][magic] == 0)
				{
					q.push({nx, ny, magic});
					visited[nx][ny][magic] = visited[x][y][magic] + 1;
				}
				else if(Map[nx][ny] == 1 && visited[nx][ny][magic+1] == 0 && magic == 0)
				{
					q.push({nx, ny, magic+1});
					visited[nx][ny][magic+1] = visited[x][y][magic] + 1;
				}	
			}
		}
	}
	
	return 0;
}

void solve()
{
	if(BFS() == 1)
	{
		cout << ans;
	}
	else
	{
		cout << "-1";
	}
}

int main(void)
{
//	freopen("B14923_input.txt", "r", stdin);
	
	cin >> row >> col;
	
	cin >> startX >> startY >> endX >> endY;
	
	for(int i = 1; i <= row; i++)
	{
		for(int j = 1; j <= col; j++)
		{
			cin >> Map[i][j];
		}
	}
	
	solve();
	
	return 0;
}
