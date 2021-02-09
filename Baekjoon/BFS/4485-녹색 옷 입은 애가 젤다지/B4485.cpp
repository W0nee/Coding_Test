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

int N;
int Map[130][130];
int visited[130][130];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1 ,1};

int safe(int x, int y)
{
	if(1 <= x && x <= N && 1 <= y && y <= N)
	{
		return 1;
	}
	
	return 0;
}

void BFS()
{
	queue<pair<int, int>> q;
	
	q.push({1, 1});
	visited[1][1] = Map[1][1];
	
	while(!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		for(int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(safe(nx, ny) == 0)
			{
				continue;
			}
			
			if(visited[x][y] + Map[nx][ny] < visited[nx][ny])
			{
				q.push({nx, ny});
				visited[nx][ny] = visited[x][y] + Map[nx][ny];
			}
		}
	}
}

int main(void)
{
//	freopen("B4485_input.txt", "r", stdin);
	
	int num = 0;
	
	while(1)
	{
		num++;
		memset(visited, 0, sizeof(visited));
		
		cin >> N;
		
		if(N == 0)
		{
			break;
		}	
		
		for(int i = 1; i <= N; i++)
		{
			for(int j = 1; j <= N; j++)
			{
				cin >> Map[i][j];
				
				visited[i][j] = 99999999;
			}
		}
		
		BFS();
		
		cout << "Problem " << num << ": " << visited[N][N] << "\n";
	}
	
	
	return 0;
}
