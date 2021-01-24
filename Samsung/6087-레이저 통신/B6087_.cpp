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
char Map[110][110];
vector<pair<int, int>> pos;

queue<node> q;
int visited[110][110][4];

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
	for(int i = 0; i < 4; i++)
	{
		q.push({pos[0].first, pos[0].second, i});
		visited[pos[0].first][pos[0].second][i] = 0;
	}
	
	while(!q.empty())
	{
		int x = q.front().x;
		int y = q.front().y;
		int dir = q.front().dir;
		q.pop();

		for(int i = 0; i < 4; i++)
		{
			int nx = x+dx[i];
			int ny = y+dy[i];
			
			if(safe(nx, ny) == 0)
			{
				continue;
			}
		
			if(dir == i)
			{
//				if(Map[nx][ny] != '*' && visited[nx][ny][i] == 987654321)
//				{
//					q.push({nx, ny, i});
//					visited[nx][ny][i] = visited[x][y][dir];
//				}

				if(Map[nx][ny] != '*' && visited[x][y][dir] < visited[nx][ny][i])
				{
					q.push({nx, ny, i});
					visited[nx][ny][i] = visited[x][y][dir];
				}
			}
			else if(dir != i)
			{
//				if(Map[nx][ny] != '*' && visited[nx][ny][i] == 987654321)
//				{
//					q.push({nx, ny, i});
//					visited[nx][ny][i] = visited[x][y][dir] + 1;
//				}

				if(Map[nx][ny] != '*' && visited[x][y][dir] + 1 < visited[nx][ny][i])
				{
					q.push({nx, ny, i});
					visited[nx][ny][i] = visited[x][y][dir] + 1;
				}
			}
		}	
	}
}

int main(void)
{
//	freopen("B6087_input.txt", "r", stdin);
	
	cin >> col >> row;
	
	for(int i = 1; i <= row; i++)
	{
		for(int j = 1; j <= col; j++)
		{
			cin >> Map[i][j];
			
			if(Map[i][j] == 'C')
			{
				pos.push_back({i, j});
			}
			
			for(int k = 0; k < 4; k++)
			{
				visited[i][j][k] = 987654321;		
			}
		}
	}
	
	BFS();
	
	int Min = 987654321;
	for(int i = 0; i < 4; i++)
	{
		Min = min(Min, visited[pos[1].first][pos[1].second][i]);
	}
	
	cout << Min;
	
	return 0;
}
