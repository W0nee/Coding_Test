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

int row, col;
int N;
vector<pair<int, int>> pos;
int startX, startY;
int ans;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int BFS(int arriveX, int arriveY)
{
	queue<pair<int, int>> q;
	int visited[110][110] = {0};
	int Min = 987654321;
	
	q.push({startX, startY});
	visited[startX][startY] = 1;
	
	while(!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		for(int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(0 <= nx && nx <= row && 0 <= ny && ny <= col)
			{
				if(i == 0 || i == 1)
				{
					if(nx == 0 || nx == row)
					{
						if(nx == arriveX && ny == arriveY)
						{
							return visited[x][y];
						}
						
						if(visited[nx][ny] == 0)
						{
							q.push({nx, ny});
							visited[nx][ny] = visited[x][y] + 1;
						}
					}
				}
				else
				{
					if(ny == 0 || ny == col)
					{
						if(nx == arriveX && ny == arriveY)
						{
							return visited[x][y];
						}
						
						if(visited[nx][ny] == 0)
						{
							q.push({nx, ny});
							visited[nx][ny] = visited[x][y] + 1;
						}
					}
				}
			}
		}
	}
}

int main(void)
{
//	freopen("B2564_input.txt", "r", stdin);
	
	cin >> col >> row >> N;
	
	for(int i = 1; i <= N+1; i++)
	{
		int dir, d;
		cin >> dir >> d;
		
		if(dir == 1)
		{
			pos.push_back({0, d});
		}
		else if(dir == 2)
		{
			pos.push_back({row, d});
		}
		else if(dir == 3)
		{
			pos.push_back({d, 0});
		}
		else
		{
			pos.push_back({d, col});
		}
	}
	
	startX = pos[pos.size()-1].first;
	startY = pos[pos.size()-1].second;
	
	for(int i = 0; i < pos.size()-1; i++)
	{
		int x = pos[i].first;
		int y = pos[i].second;
		
		ans += BFS(x, y);
	}

	cout << ans;
	
	return 0;
}
