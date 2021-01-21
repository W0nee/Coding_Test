#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

int row, col;
char Map[1010][1010];
bool Flag = false;

queue<pair<int, int>> q;
queue<pair<int, int>> m;

int dx[4] = {0, -1, 0, 1}; 
int dy[4] = {-1, 0, 1, 0}; 

int safe(int x, int y)
{
	if(1 <= x && x <= row && 1 <= y && y <= col)
	{
		return 1;
	}
	
	return 0;
}

void fire_spread()
{
	int cnt = q.size();
	
	while(cnt--)
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
			
			if(Map[nx][ny] == '.' || Map[nx][ny] == 'J')
			{
				Map[nx][ny] = 'F';
				q.push({nx, ny});
			}
		}
	}	
}

void jihoon_move()
{
	int cnt = m.size();
	
	while(cnt--)
	{
		int x = m.front().first;
		int y = m.front().second;
		m.pop();
		
		// 지훈이가 불에 붙은 경우 
		if(Map[x][y] == 'F')
		{
			continue;
		}
		
		// 지훈이가 가장자리에 있는 경우
		if(x == 1 || x == row || y == 1 || y == col)
		{
			Flag = true;
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
			
			if(Map[nx][ny] == '.')
			{
				Map[nx][ny] = 'J';
				m.push({nx, ny});
			}
		}
	}	
	
}

void solve()
{
	int day = 0;
	
	while(1)
	{
		jihoon_move();
		
		day++;
		
		if(Flag)
		{
			cout << day;
			return;
		}
		else if(m.empty())
		{
			cout << "IMPOSSIBLE";
			return;
		}
		
		fire_spread();	
	}
}

int main(void)
{
//	freopen("B4179_input.txt", "r", stdin);
	
	cin >> row >> col;
	
	for(int i = 1; i <= row; i++)
	{
		for(int j = 1; j <= col; j++)
		{
			cin >> Map[i][j];
			
			if(Map[i][j] == 'F')
			{
				q.push({i, j});
			}
			else if(Map[i][j] == 'J')
			{
				m.push({i, j});
			}
		}
	}
	
	solve();
	
	return 0;
}
