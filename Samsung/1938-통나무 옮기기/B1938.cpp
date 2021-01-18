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
	int shape; // 가로: 0, 세로: 1 
}node;

int N;
char Map[55][55];
vector<pair<int, int>> start;
vector<pair<int, int>> arrive;
int arriveShape; 
int Min;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int safe(int x, int y)
{
	if(1 <= x && x <= N && 1 <= y && y <= N)
	{
		return 1;
	}
	
	return 0;
}

void BFS(int x, int y, int shape)
{
	queue<node> q;
	int visited[55][55][2] = {0}; 
	
	q.push({x, y, shape});
	visited[x][y][shape] = 1;
	
	while(!q.empty())
	{
		x = q.front().x;
		y = q.front().y;
		shape = q.front().shape;
		q.pop();
		
		if(x == arrive[1].first && y == arrive[1].second && shape == arriveShape)
		{
			Min = visited[x][y][shape] - 1;
			return;
		}
		
		for(int i = 0; i < 4; i++)
		{
			int nx = x+dx[i];
			int ny = y+dy[i];
			
			if(shape == 0)
			{
				if(safe(nx, ny-1) == 1 && safe(nx, ny+1) == 1)
				{
					if(Map[nx][ny-1] != '1' && Map[nx][ny] != '1' && Map[nx][ny+1] != '1' && visited[nx][ny][shape] == 0)
					{
						q.push({nx, ny, shape});
						visited[nx][ny][shape] = visited[x][y][shape] + 1;
					}
				}
			}
			else if(shape == 1)
			{
				if(safe(nx-1, ny) == 1 && safe(nx+1, ny) == 1)
				{
					if(Map[nx-1][ny] != '1' && Map[nx][ny] != '1' && Map[nx+1][ny] != '1' && visited[nx][ny][shape] == 0)
					{
						q.push({nx, ny, shape});
						visited[nx][ny][shape] = visited[x][y][shape] + 1;
					}
				}
			}
		}
		
		if(safe(x-1, y-1) == 1 && safe(x+1, y+1) == 1)
		{
			int cnt = 0;
			
			for(int i = x-1; i <= x+1; i++)
			{
				for(int j = y-1; j <= y+1; j++)
				{
					if(Map[i][j] != '1')
					{
						cnt++;
					}
				}
			}
			
			if(cnt == 9)
			{
				if(shape == 0)
				{
					if(visited[x][y][1] == 0)
					{
						q.push({x, y, 1});
						visited[x][y][1] = visited[x][y][0] + 1;
					}	
				}	
				else if(shape == 1)
				{
					if(visited[x][y][0] == 0)
					{
						q.push({x, y, 0});
						visited[x][y][0] = visited[x][y][1] + 1;
					}	
				}
			}
		}
	}
}

void solve()
{
	if(arrive[1].second - arrive[0].second == 1)
	{
		arriveShape = 0;
	}
	else if(arrive[1].first - arrive[0].first == 1)
	{
		arriveShape = 1;
	}
	
	if(start[1].second - start[0].second == 1)
	{
		BFS(start[1].first, start[1].second, 0);
	}
	else if(start[1].first - start[0].first == 1)
	{
		BFS(start[1].first, start[1].second, 1);
	}
	
	cout << Min;
}

int main(void)
{
//	freopen("B1938_input.txt", "r", stdin);
	
	cin >> N;
	
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			cin >> Map[i][j];
			
			if(Map[i][j] == 'B')
			{
				start.push_back({i, j});
			}
			else if(Map[i][j] == 'E')
			{
				arrive.push_back({i, j});
			}
		}
	}
	
	solve();
	
	return 0;
}
