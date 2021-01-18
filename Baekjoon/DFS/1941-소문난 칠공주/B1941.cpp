#include <stdio.h>
#include <iostream>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

char Map[10][10];
vector<int> choice;
int ans;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int BFS(int x, int y, int Select[10][10])
{
	queue<pair<int, int>> q;
	int visited[10][10] = {0};
	
	q.push({x, y});
	visited[x][y] = 1;
	int princess = 1;
	
	while(!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();
		
		for(int i = 0; i < 4; i++)
		{
			int nx = x+dx[i];
			int ny = y+dy[i];
		
			if(!(0 <= nx && nx < 5 && 0 <= ny && ny < 5))
			{
				continue;	
			}	
			
			if(Select[nx][ny] == 1 && visited[nx][ny] == 0)
			{
				q.push({nx, ny});
				visited[nx][ny] = 1;
				princess++;
			}
		}
	}
	
	if(princess == 7)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void combination(int idx, int cnt)
{
	if(cnt == 7)
	{
		int Select[10][10] = {0};
		int x, y;
		int dasom = 0;
	
		for(int i = 0; i < choice.size(); i++)
		{
			x = choice[i] / 5;
			y = choice[i] % 5;
			
			Select[x][y] = 1;
			
			if(Map[x][y] == 'S')
			{
				dasom++;
			}
		}
		
		if(dasom >= 4)
		{
			if(BFS(x, y, Select))
			{
				ans++;
			}
		}
		
		return;
	}
	
	for(int i = idx; i < 25; i++)
	{
		choice.push_back(i);
		combination(i+1, cnt+1);
		choice.pop_back();
	}
}

int main(void)
{
//	freopen("B1941_input.txt", "r", stdin);
	
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			cin >> Map[i][j];
		}
	}
	
	combination(0, 0);
	
	cout << ans;
	
	return 0;
}
