#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

int N;
int Map[110][110];
int color;
vector<pair<int, int>> outside[10010];
int Min = 987654321;

queue<pair<int, int>> q;
int visited[110][110];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int safe(int x, int y)
{
	if(1 <= x && x <= N && 1 <= y && y <= N)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void paint(int x, int y, int color)
{
	q.push({x, y});
	visited[x][y] = 1;
	Map[x][y] = color;
	
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
			
			if(Map[nx][ny] == 1 && visited[nx][ny] == 0)
			{
				q.push({nx, ny});
				visited[nx][ny] = 1;
				Map[nx][ny] = color;
			}
		}
	}	
}

void find_outside(int color)
{
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			if(Map[i][j] == color)
			{
				for(int k = 0; k < 4; k++)
				{
					int nx = i+dx[k];
					int ny = j+dy[k];
					
					if(safe(nx, ny) == 0)
					{
						continue;
					}
					
					if(Map[nx][ny] == 0)
					{
						outside[color].push_back({i, j});
						break;
					}
				}	
			}
		}
	}
}

void connect(int color)
{
	queue<pair<int, int>> q;
	int visited[110][110] = {0};
	
	for(int i = 0; i < outside[color].size(); i++)
	{
		int x = outside[color][i].first;
		int y = outside[color][i].second;
		
		q.push({x, y});
		visited[x][y] = 1;
	}
	
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
			
			if(Map[nx][ny] == 0 && visited[nx][ny] == 0)
			{
				q.push({nx, ny});
				visited[nx][ny] = visited[x][y] + 1;
			}
			else if(Map[nx][ny] != 0 && Map[nx][ny] != color)
			{
				Min = min(Min, visited[x][y] - 1);
				break;
			}
		}
	}		
}

int main(void)
{
//	freopen("B2146_input.txt", "r", stdin);
	
	cin >> N;
	
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			cin >> Map[i][j];
		}
	}
	
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			if(Map[i][j] != 0 && visited[i][j] == 0)
			{
				paint(i, j, ++color);
			}
		}
	}
	
	for(int i = 1; i <= color; i++)
	{
		find_outside(i);
	}
	
	for(int i = 1; i <= color; i++)
	{
		connect(i);
	}
	
	cout << Min;
	
	return 0;
}
