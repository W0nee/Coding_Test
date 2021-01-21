#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

int row, col;
int Map[60][60];
int visited[60][60];
int cnt;
int Max;
int Max2;

int area[2600];
vector<int> close_area[2600];

int dx[4] = {0, -1, 0, 1}; // ¼­ºÏµ¿³²
int dy[4] = {-1, 0, 1, 0}; // ¼­ºÏµ¿³²

int safe(int x, int y)
{
	if(1 <= x && x <= row && 1 <= y && y <= col)
	{
		return 1;
	}
	
	return 0;
}

void BFS(int x, int y, int cnt)
{
	queue<pair<int, int>> q;
	int area_size = 0;
	
	q.push({x, y});
	visited[x][y] = cnt;
	area_size++;
	
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
			
			if((Map[x][y] & (1 << i)) == 0 && visited[nx][ny] == 0)
			{
				q.push({nx, ny});
				visited[nx][ny] = cnt;
				area_size++;
			}
		}
	}
	
	area[cnt] = area_size;
	Max = max(Max, area_size);
}

void crash_wall(int x, int y)
{
	queue<pair<int, int>> q;
	int check[60][60] = {0};
	
	q.push({x, y});
	check[x][y] = 1;
	
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
			
			if(visited[nx][ny] == visited[x][y] && check[nx][ny] == 0)
			{
				q.push({nx, ny});
				check[nx][ny] = 1;
			}
			else if(visited[nx][ny] != visited[x][y] && check[nx][ny] == 0)
			{
				Max2 = max(Max2, area[visited[x][y]] + area[visited[nx][ny]]);
				check[nx][ny] = 1;
			}
		}
	}
}

void print()
{
	cout << "\n";
	for(int i = 1; i <= row; i++)
	{
		for(int j = 1; j <= col; j++)
		{
			cout << visited[i][j] << " ";
		}
		cout << "\n";
	}
}

void solve()
{
	for(int i = 1; i <= row; i++)
	{
		for(int j = 1; j <= col; j++)
		{
			if(visited[i][j] == 0)
			{
				BFS(i, j, ++cnt);
			}
		}
	}
	
//	print();

	int same[2600] = {0};
	
	for(int i = 1; i <= row; i++)
	{
		for(int j = 1; j <= col; j++)
		{
			if(same[visited[i][j]] == 0)
			{
				same[visited[i][j]] = 1;
				crash_wall(i, j);
			}
		}
	}
}

int main(void)
{
//	freopen("B2234_input.txt", "r", stdin);
	
	cin >> col >> row;
	
	for(int i = 1; i <= row; i++)
	{
		for(int j = 1; j <= col; j++)
		{
			cin >> Map[i][j];
		}
	}
	
	solve();
	
	cout << cnt << "\n";
	cout << Max << "\n";
	cout << Max2 << "\n";
	
	return 0;
}
