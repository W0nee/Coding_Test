#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;

int N;
int virusCnt;
int Map[60][60];
int Result[60][60];
int visited[60][60];
vector<pair<int, int>> virus;

int candidate[15];
int Min = 999999999;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int BFS()
{
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			// º®: -2 
			if(Map[i][j] == 1)
			{
				Result[i][j] = -2;
//				visited[i][j] = -2;
			}
			// ºóÄ­: -1
			else
			{
				Result[i][j] = -1;
//				visited[i][j] = -1;
			}
		}
	}
	
	queue<pair<int, int>> q;
	memset(visited, -1, sizeof(visited));
	
	for(int i = 0; i < virusCnt; i++)
	{
		int num = candidate[i];
		int x = virus[num].first;
		int y = virus[num].second;
		
		q.push({x, y});
		visited[x][y] = 0;
		Result[x][y] = visited[x][y];
	}
	
	int Max = 0;
	while(!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		Max = max(Max, visited[x][y]);
		
		for(int i = 0; i < 4; i++)
		{
			int nx = x+dx[i];
			int ny = y+dy[i];
			
			if(!(1 <= nx && nx <= N && 1 <= ny && ny <= N))
			{
				continue;
			}
			
			if(Result[nx][ny] == -1 && visited[nx][ny] == -1)
			{
				q.push({nx, ny});
				visited[nx][ny] = visited[x][y] + 1;
				Result[nx][ny] = visited[nx][ny];
			}
		}
	}
	
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			if(Result[i][j] == -1)
			{
				Max = 999999999;
				return Max;
			}
		}
	}
	
	return Max;
}

void combination(int cnt, int idx)
{
	if(cnt == virusCnt)
	{
		Min = min(Min, BFS());
		return;
	}

	for(int i = idx; i < virus.size(); i++)
	{
		candidate[cnt] = i;
		combination(cnt+1, i+1);
	}	
}

int main(void)
{
//	freopen("B17141_input.txt", "r", stdin);
	
	cin >> N >> virusCnt;
	
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			cin >> Map[i][j];
			
			if(Map[i][j] == 2)
			{
				virus.push_back({i, j});
			}
		}
	}
	
	combination(0, 0);
	
	if(Min == 999999999)
	{
		cout << -1;
	}
	else
	{
		cout << Min;	
	}
	
	return 0;
}
