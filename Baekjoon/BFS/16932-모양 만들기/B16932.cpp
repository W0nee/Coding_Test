#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

int row, col;
int Map[1010][1010];
int paint_cnt[100010];
int visited[1010][1010];
int Max;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int safe(int x, int y)
{
	if(1 <= x && x <= row && 1 <= y && y <= col)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void painting(int x, int y, int color)
{
	queue<pair<int, int>> q;
	
	q.push({x, y});
	visited[x][y] = color;
	int cnt = 1;
	
	while(!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();
		
		for(int i = 0; i < 4; i++)
		{
			int nx = x+dx[i];
			int ny = y+dy[i];
			
			if(safe(nx, ny) == 1 && Map[nx][ny] == 1 && visited[nx][ny] == 0)
			{
				visited[nx][ny] = color;
				q.push({nx, ny});
				cnt++;
			}
		}
	}
	
	paint_cnt[color] = cnt;
}

int main(void)
{
//	freopen("B16932_input.txt", "r", stdin);
	
	cin >> row >> col;
	
	for(int i = 1; i <= row; i++)
	{
		for(int j = 1; j <= col; j++)
		{
			cin >> Map[i][j];		
		}
	}
	
	int color = 0;
	for(int i = 1; i <= row; i++)
	{
		for(int j = 1; j <= col; j++)
		{
			if(Map[i][j] == 1 && visited[i][j] == 0)
			{
				++color;
				painting(i, j, color);
			}
		}
	}
	
//	for(int i = 1; i <= row; i++)
//	{
//		for(int j = 1; j <= col; j++)
//		{
//			cout << visited[i][j] << " ";
//		}
//		cout << endl;
//	}
	
	for(int i = 1; i <= row; i++)
	{
		for(int j = 1; j <= col; j++)
		{
			if(Map[i][j] == 0)
			{
				int result = 1;
				map<int, int> check_color;
				
//				cout << i << " " << j << endl;
				
				for(int k = 0; k < 4; k++)
				{
					int nx = i+dx[k];
					int ny = j+dy[k];
					
					if(safe(nx, ny) == 1 && Map[nx][ny] == 1 && check_color[visited[nx][ny]] == 0)
					{
						check_color[visited[nx][ny]] = 1;
						result += paint_cnt[visited[nx][ny]];
					}
				}
				
//				cout << result << endl;
				
				if(Max < result)
				{
					Max = result;
				}
			}
		}
	}
	
	cout << Max;
	
	return 0;
}
