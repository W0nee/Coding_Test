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

char Map[20][10];
bool Flag = false;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int safe(int x, int y)
{
	if(1 <= x && x <= 12 && 1 <= y && y <= 12)
	{
		return 1;
	}
	
	return 0;
}

void bomb()
{
	queue<pair<int, int>> q;
	int visited[20][10] = {0};
	
	for(int i = 1; i <= 12; i++)
	{
		for(int j = 1; j <= 6; j++)
		{
			if(Map[i][j] != '.' && visited[i][j] == 0)
			{
				q.push({i, j});
				visited[i][j] = 1;
				
				vector<pair<int, int>> bomb_list;
				char color = Map[i][j];
				
				while(!q.empty())
				{
					int x = q.front().first;
					int y = q.front().second;
					q.pop();
					
					bomb_list.push_back({x, y});
					
					for(int i = 0; i < 4; i++)
					{
						int nx = x+dx[i];
						int ny = y+dy[i];
						
						if(safe(nx, ny) == 1 && Map[nx][ny] == color && visited[nx][ny] == 0)
						{
							q.push({nx, ny});
							visited[nx][ny] = 1;
						}	
					}
				}
				
				if(bomb_list.size() >= 4)
				{
					Flag = true;
					
					for(int k = 0; k < bomb_list.size(); k++)
					{
						int x = bomb_list[k].first; 
						int y = bomb_list[k].second;
						
						Map[x][y] = '.';
					}
				}
			}
		}
	}	
}

void down()
{
	for(int j = 1; j <= 6; j++)
	{
		deque<char> list;
		
		for(int i = 12; i >= 1; i--)
		{
			if(Map[i][j] != '.')
			{
				list.push_back(Map[i][j]);
				Map[i][j] = '.';
			}
		}
		
		int cnt = list.size();
		for(int i = 12; i > 12-cnt; i--)
		{
			Map[i][j] = list.front();
			list.pop_front();	
		}
	}
}

void print()
{
	cout << "\n";
	for(int i = 1; i <= 12; i++)
	{
		for(int j = 1; j <= 6; j++)
		{
			cout << Map[i][j] << " ";
		}
		cout << "\n";
	}
}

void solve()
{
	int ans = 0;
	
	while(1)
	{
		Flag = false;
		
		bomb();
		down();
		
		if(Flag == false)
		{
			cout << ans;
			return;
		}
		
		ans++;	
	}
}
 
int main(void)
{
//	freopen("B11599_input.txt", "r", stdin);
	
	for(int i = 1; i <= 12; i++)
	{
		for(int j = 1; j <= 6; j++)
		{
			cin >> Map[i][j];
		}
	}
	
	solve();
	
	return 0;
}
