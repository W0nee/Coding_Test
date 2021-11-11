#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

typedef struct node
{
	int x;
	int y;
	int z;
}node;

int row, col, h;
int Map[110][110][110];
int day;

queue<node> q;
int visited[110][110][110];

int dx[6] = {-1, 1, 0, 0, 0, 0};
int dy[6] = {0, 0, -1, 1, 0, 0};
int dz[6] = {0, 0, 0, 0, -1, 1};

int safe(int x, int y, int z)
{
	if(1 <= x && x <= row && 1 <= y && y <= col && 1 <= z && z <= h)
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
	int cnt = q.size();
	
	while(cnt--)
	{
		int x = q.front().x;
		int y = q.front().y;
		int z = q.front().z;
		q.pop();
		
		for(int i = 0; i < 6; i++)
		{
			int nx = x+dx[i];
			int ny = y+dy[i];
			int nz = z+dz[i];
			
			if(safe(nx, ny, nz) == 0)
			{
				continue;
			}
			
			if(Map[nx][ny][nz] == 0)
			{
				q.push({nx, ny, nz});
				Map[nx][ny][nz] = 1;
			}
		}
	}
}

int check()
{
	for(int k = 1; k <= h; k++)
	{
		for(int i = 1; i <= row; i++)
		{
			for(int j = 1; j <= col; j++)
			{
				if(Map[i][j][k] == 0)
				{
					return 0;
				}
			}
		}	
	}
	
	return 1;
}

int main(void)
{
//	freopen("B7569_input.txt", "r", stdin);
	
	cin >> col >> row >> h;
	
	for(int k = 1; k <= h; k++)
	{
		for(int i = 1; i <= row; i++)
		{
			for(int j = 1; j <= col; j++)
			{
				cin >> Map[i][j][k];	
				
				if(Map[i][j][k] == 1)
				{
					q.push({i, j, k});
				}
			}
		}	
	}

	while(1)
	{
		if(check())
		{
			cout << day;
			break;
		}
		else if(q.size() == 0)
		{
			cout << "-1";
			break;		
		}
		
		day++;

		BFS();		
	}
	
	return 0;
}
