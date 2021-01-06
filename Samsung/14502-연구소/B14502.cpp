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
int Map[10][10];
int Temp[10][10];
vector<pair<int, int>> list;
vector<pair<int, int>> virus;
vector<pair<int, int>> wall;
int Max;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int count_safe()
{
	int cnt = 0;
	
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
		{
			if(Map[i][j] == 0) cnt++;
		}
	}
	
	return cnt;
}

int safe(int x, int y)
{
	if(0 <= x && x < row && 0 <= y && y < col)
	{
		return 1;
	}
	
	return 0;
}

void spread_virus()
{
	queue<pair<int, int>> q;
	int visited[10][10] = {0};
	
	for(int i = 0; i < virus.size(); i++)
	{
		visited[virus[i].first][virus[i].second] = 1;
		q.push({virus[i].first, virus[i].second});
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
			
			if(safe(nx, ny) == 1 && Map[nx][ny] == 0 && visited[nx][ny] == 0)
			{
				visited[nx][ny] = 1;
				Map[nx][ny] = 2;
				q.push({nx, ny});
			}
		}		
	}
}

void combination(int idx, int cnt)
{
	if(cnt == 3)
	{
		for(int i = 0; i < wall.size(); i++)
		{
			Map[wall[i].first][wall[i].second] = 1;
		}
		
		spread_virus();
		Max = max(Max, count_safe());
		
		for(int i = 0; i < row; i++)
		{
			for(int j = 0; j < col; j++)
			{
				Map[i][j] = Temp[i][j];
			}
		}
		
		return;
	}
	
	for(int i = idx; i < list.size(); i++)
	{
		wall.push_back(list[i]);
		combination(i+1, cnt+1);
		wall.pop_back();
	}
}

int main(void)
{
//	freopen("B14503_input.txt", "r", stdin);
	
	cin >> row >> col;
	
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
		{
			cin >> Map[i][j];
			Temp[i][j] = Map[i][j];
			
			if(Map[i][j] == 0)
			{
				list.push_back({i, j});
			}
			else if(Map[i][j] == 2)
			{
				virus.push_back({i, j});
			}
		}
	}
	
	combination(0, 0);
	
	cout << Max;
	
	return 0;
}
