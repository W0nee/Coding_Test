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
int Map[350][350];
int Temp[350][350];

queue<pair<int, int>> q;
int visited[350][350];

queue<pair<int, int>> c;
int check[350][350];

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

void melt()
{
	int cnt = q.size();
	
	while(cnt--)
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		int cnt = 0;
		
		for(int i = 0; i < 4; i++)
		{
			int nx = x+dx[i];
			int ny = y+dy[i];
			
			if(safe(nx, ny) == 1 && Map[nx][ny] == 0)
			{
				cnt++;
			}
		}
		
		Temp[x][y] = Temp[x][y] - cnt < 0 ? 0 : Temp[x][y] - cnt;
		
		if(Temp[x][y] >= 1)
		{
			q.push({x, y});
		}
	}
	
	for(int i = 1; i <= row; i++)
	{
		for(int j = 1; j <= col; j++)
		{
			Map[i][j] = Temp[i][j];
		}
	}
}

void check_ice(int ice)
{
	while(!c.empty())
	{
		int x = c.front().first;
		int y = c.front().second;
		c.pop();
		
		for(int i = 0; i < 4; i++)
		{
			int nx = x+dx[i];
			int ny = y+dy[i];
			
			if(safe(nx, ny) == 1 && Map[nx][ny] >= 1 && check[nx][ny] == 0)
			{
				c.push({nx, ny});
				check[nx][ny] = ice;
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
			cout << Map[i][j] << " ";
		}
		cout << "\n";
	}
}

void solve()
{
	int day = 0;
	
	while(1)
	{
		int ice = 0;
		memset(check, 0, sizeof(check));
		
		day++;
		
		melt();
		
		for(int i = 1; i <= row; i++)
		{
			for(int j = 1; j <= col; j++)
			{
				if(Map[i][j] >= 1 && check[i][j] == 0)
				{
					c.push({i, j});
					check[i][j] = ++ice;
					check_ice(ice);
				}
			}
		}
		
//		print();
		
		if(ice >= 2)
		{
			cout << day;
			return;
		}
		else if(ice == 0)
		{
			cout << "0";
			return;
		}
	}
}

int main(void)
{
//	freopen("B2573_input.txt", "r", stdin);
	
	cin >> row >> col;
	
	for(int i = 1; i <= row; i++)
	{
		for(int j = 1; j <= col; j++)
		{
			cin >> Map[i][j];
			Temp[i][j] = Map[i][j];
			
			if(Map[i][j] >= 1)
			{
				q.push({i, j});
			}
		}
	}
	
	solve();
	
	return 0;
}
