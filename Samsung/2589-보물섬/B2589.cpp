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
char Map[110][110];
int Max;

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

void BFS(int x, int y)
{
	queue<pair<int, int>> q;
	int visited[60][60] = {0};
	
	q.push({x, y});
	visited[x][y] = 1;
	
	while(!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();
		
		Max = max(Max, visited[x][y] - 1);
		
		for(int i = 0; i < 4; i++)
		{
			int nx = x+dx[i];
			int ny = y+dy[i];
			
			if(safe(nx, ny) == 0)
			{
				continue;
			}
			
			if(Map[nx][ny] == 'L' && visited[nx][ny] == 0)
			{
				q.push({nx, ny});
				visited[nx][ny] = visited[x][y] + 1;
			}
		}
	}
}

int main(void)
{
//	freopen("B2589_input.txt", "r", stdin);
	
	cin >> row >> col;
	
	for(int i = 1; i <= row; i++)
	{
		for(int j = 1; j <= col; j++)
		{
			cin >> Map[i][j];
		}
	}
	
	for(int i = 1; i <= row; i++)
	{
		for(int j = 1; j <= col; j++)
		{
			if(Map[i][j] == 'L')
			{
				BFS(i, j);
			}
		}
	}
	
	cout << Max;
	
	return 0;
}
