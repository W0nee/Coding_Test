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
	int cnt;
	int time;
}node;

int row, col, K;
int Map[1010][1010];
int visited[1010][1010][12][2];
int Min = 99999999;

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
	queue<node> q;
	
	q.push({1, 1, 0, 0});
	visited[1][1][0][0] = 1;
	
	while(!q.empty())
	{
		int x = q.front().x;
		int y = q.front().y;
		int cnt = q.front().cnt;
		int time = q.front().time;
		q.pop();
		
		if(x == row && y == col)
		{
			Min = visited[x][y][cnt][time];
			return;
		}
		
		for(int i = 0; i < 4; i++)
		{
			int nx = x+dx[i];
			int ny = y+dy[i];
			
			if(safe(nx, ny) == 0)
			{
				continue;
			}
			
			if(time == 0)
			{
				// 이동하지 않고 같은 칸에 머무르는 경우에도 낮과 밤이 바뀌게 된다.
				if(visited[x][y][cnt][1] == 0)
				{
					q.push({x, y, cnt, 1});
					visited[x][y][cnt][1] = visited[x][y][cnt][0] + 1;
				}
				
				if(Map[nx][ny] == 0 && visited[nx][ny][cnt][1] == 0)
				{
					q.push({nx, ny, cnt, 1});
					visited[nx][ny][cnt][1] = visited[x][y][cnt][0] + 1;
				}
				else if(Map[nx][ny] == 1 && visited[nx][ny][cnt+1][1] == 0 && cnt+1 <= K)
				{
					q.push({nx, ny, cnt+1, 1});
					visited[nx][ny][cnt+1][1] = visited[x][y][cnt][0] + 1;
				}
			}
			else if(time == 1)
			{
				// 이동하지 않고 같은 칸에 머무르는 경우에도 낮과 밤이 바뀌게 된다.
				if(visited[x][y][cnt][0] == 0)
				{
					q.push({x, y, cnt, 0});
					visited[x][y][cnt][0] = visited[x][y][cnt][1] + 1;
				}
				
				if(Map[nx][ny] == 0 && visited[nx][ny][cnt][0] == 0)
				{
					q.push({nx, ny, cnt, 0});
					visited[nx][ny][cnt][0] = visited[x][y][cnt][1] + 1;
				}
			}
		}	
	}
}

int main(void)
{
//	freopen("B14442_input.txt", "r", stdin);
	
	cin >> row >> col >> K;
	
	for(int i = 1; i <= row; i++)
	{
		for(int j = 1; j <= col; j++)
		{
			scanf("%1d", &Map[i][j]);
		}
	}
	
	BFS();
	
	if(Min == 99999999)
	{
		cout << "-1";
	}
	else
	{
		cout << Min;	
	}
	
	return 0;
}
