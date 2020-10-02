#include <stdio.h>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

typedef struct node
{
	int x;
	int y;
	int crash;
}node;

int Map[110][110];
int visited[110][110][250];
int row, col;
int Min = 99999999;

int dx[4] = {-1, 1, 0, 0}; // 상하좌우 
int dy[4] = {0, 0, -1, 1}; // 상하좌우

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
	queue<node> q;
	q.push({0, 0, 0});
	visited[0][0][0] = 1;
	
	while(!q.empty())
	{
		int x = q.front().x;
		int y = q.front().y;
		int crash = q.front().crash;
		q.pop();
		
		if(x == row-1 && y == col-1)
		{
			Min = min(crash, Min);
		}
		
		for(int i = 0; i < 4; i++)
		{
			int xpos = x+dx[i];
			int ypos = y+dy[i];
			
			// 벽 안 부술때 
			if(safe(xpos, ypos) == 1 && Map[xpos][ypos] == 0 && visited[xpos][ypos][crash] == 0)
			{
				visited[xpos][ypos][crash] = 1;
				q.push({xpos, ypos, crash});
			}
			// 벽 부술때 
			else if(safe(xpos, ypos) == 1 && Map[xpos][ypos] == 1 && visited[xpos][ypos][crash+1] == 0 && crash+1 <= row+col-3)
			{	
				visited[xpos][ypos][crash+1] = 1;
				q.push({xpos, ypos, crash+1});
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
		}
	}
	
	BFS();
	
	cout << Min;
	
	return 0;
}
