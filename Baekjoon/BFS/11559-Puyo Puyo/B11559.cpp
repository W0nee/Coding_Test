#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;

char Map[20][10];
int check[20][10];
bool Flag = false;
int num;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int safe(int x, int y)
{
	if(1 <= x && x <= 12 && 1 <= y && y <= 6)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void bomb(int x, int y, char color)
{
	queue<pair<int, int>> q;
	vector<pair<int, int>> list;
	
	q.push({x, y});
	check[x][y] = 1;
	list.push_back({x, y});
	
	while(!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();
		
		for(int i = 0; i < 4; i++)
		{
			int nx = x+dx[i];
			int ny = y+dy[i];
			
			if(safe(nx, ny) == 0)
			{
				continue;
			}
			
			if(Map[nx][ny] == color && check[nx][ny] == 0)
			{
				q.push({nx, ny});
				check[nx][ny] = 1;
				list.push_back({nx, ny});
			}
		}
	}
	
	if(list.size() >= 4)
	{
		Flag = true;
		
		for(int i = 0; i < list.size(); i++)
		{
			x = list[i].first;
			y = list[i].second;
			
			Map[x][y] = '.';
		}
	}
}

void down()
{
	for(int j = 1; j <= 6; j++)
	{
		vector<char> temp;
		
		for(int i = 12; i >= 1; i--)
		{
			if(Map[i][j] != '.')
			{
				temp.push_back(Map[i][j]);
				Map[i][j] = '.';
			}
		}
		
		for(int i = 0; i < temp.size(); i++)
		{
			Map[12-i][j] = temp[i];
		}
	}
}

int main(void)
{
//	freopen("B11559_input.txt", "r", stdin);
	
	for(int i = 1; i <= 12; i++)
	{
		string temp;
		cin >> temp;
		
		for(int j = 1; j <= 6; j++)
		{
			Map[i][j] = temp[j-1];
		}
	}
	
	while(1)
	{
		memset(check, 0, sizeof(check));
		Flag = false;
	
		for(int i = 1; i <= 12; i++)
		{
			for(int j = 1; j <= 6; j++)
			{
				if(Map[i][j] != '.' && check[i][j] == 0)
				{
					bomb(i, j, Map[i][j]);
				}
			}
		}
		
		if(Flag == false)
		{
			cout << num;
			break;
		}
		else
		{
			num++;
			down();
		}
	}

	return 0;
}
