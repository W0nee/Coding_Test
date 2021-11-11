#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

int row, col;
int Map[110][110];
map<int, int> cheeseCnt;
int time;

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

int count()
{
	int cnt = 0;
	
	for(int i = 1; i <= row; i++)
	{
		for(int j = 1; j <= col; j++)
		{
			if(Map[i][j] == 1)
			{
				cnt++;
			}
		}
	}

	return cheeseCnt[time] = cnt;
}

void melt()
{
	queue<pair<int, int>> q;
	int visited[110][110] = {0};
	
	q.push({1, 1});
	visited[1][1] = 1;
	
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
				visited[nx][ny] = 1;
			}
			else if(Map[nx][ny] == 1 && visited[nx][ny] == 0)
			{
				Map[nx][ny] = 0;
				visited[nx][ny] = 1;
			}
		}
	}
}

int main(void)
{
//	freopen("B2636_input.txt", "r", stdin);
	
	cin >> row >> col;
	
	for(int i = 1; i <= row; i++)
	{
		for(int j = 1; j <= col; j++)
		{
			cin >> Map[i][j];
		}
	}
	
	while(1)
	{
		int cnt = count();
		
		if(cnt == 0)
		{
			break;
		}
		
		melt();
		
		time++;
	}
	
	cout << time << endl;
	cout << cheeseCnt[time-1] << endl;
	
	return 0;
}
