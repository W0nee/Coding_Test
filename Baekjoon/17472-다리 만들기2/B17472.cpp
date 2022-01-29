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

typedef struct node
{
	int x;
	int y;
	int dir;
}node;

int row, col;
int Map[11][11];
int Min = 100000;

vector<pair<int, int>> island[7];
int islandCnt;

int bridgeLen[7][7];

vector<pair<int, int>> list;
map<pair<int, int>, int> check;
map<string, int> same;

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

void cal_bridge_len()
{
	for(int i = 1; i <= islandCnt; i++)
	{
		for(int j = i + 1; j <= islandCnt; j++)
		{
			int from = i;
			int to = j;
			int len = 100000;
			
//			cout << i << " " << j << endl;
			
			queue<node> q;
			int visited[11][11][4] = {0};
			
			for(int k = 0; k < island[from].size(); k++)
			{
				int x = island[from][k].first;
				int y = island[from][k].second;
				
				for(int dir = 0; dir < 4; dir++)
				{
					q.push({x, y, dir});
					visited[x][y][dir] = 1;
				}
			}
			
			while(!q.empty())
			{
				int x = q.front().x;
				int y = q.front().y;
				int dir = q.front().dir;
				q.pop();
				
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				
				if(safe(nx, ny) == 0)
				{
					continue;
				}
				
				if(Map[nx][ny] == 0 && visited[nx][ny][dir] == 0)
				{
					q.push({nx, ny, dir});
					visited[nx][ny][dir] = visited[x][y][dir] + 1;
				}
				else if(Map[nx][ny] == to)
				{
					visited[nx][ny][dir] = visited[x][y][dir] + 1;
					
					if(visited[nx][ny][dir] - 2 >= 2)
					{
						len = min(len, visited[nx][ny][dir] - 2);	
					}
				}
			}
			
			bridgeLen[from][to] = len;
			bridgeLen[to][from] = len;
		}
	}
}

int check_bridge_connect()
{
	vector<int> graph[7];
	queue<int> q;
	int visited[7] = {0};
	
	for(int i = 0; i < list.size(); i++)
	{
		int from = list[i].first;
		int to = list[i].second;
		
		graph[from].push_back(to);
		graph[to].push_back(from);
	}
	
	q.push(1);
	visited[1] = 1;
	int cnt = 1;
	
	while(!q.empty())
	{
		int x = q.front();
		q.pop();
		
		for(int i = 0; i < graph[x].size(); i++)
		{
			int y = graph[x][i];
			
			if(visited[y] == 0)
			{
				q.push(y);
				visited[y] = 1;
				cnt++;
			}
		}
	}
	
	if(cnt == islandCnt)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void solve(int idx, int cnt)
{
	if(cnt == islandCnt - 1)
	{
//		for(int i = 0; i < list.size(); i++)
//		{
//			int from = list[i].first;
//			int to = list[i].second;
//			
//			cout << from << " " << to << endl;	
//		}
//		cout << "=====================\n";
		
		if(check_bridge_connect())
		{
			int sum = 0;
		
			for(int i = 0; i < list.size(); i++)
			{
				int from = list[i].first;
				int to = list[i].second;
				
				sum += bridgeLen[from][to];	
			}
			
			Min = min(Min, sum);	
		}
		
		return;
	}
	
	for(int i = idx; i <= islandCnt; i++)
	{
		for(int j = idx; j <= islandCnt; j++)
		{
			if(i == j)
			{
				continue;
			}
			
			if(check[{i, j}] == 0 && check[{j, i}] == 0)
			{
				check[{i, j}] = 1;
				check[{j, i}] = 1;
				list.push_back({i, j});
				solve(i, cnt + 1);
				list.pop_back();	
				check[{i, j}] = 0;
				check[{j, i}] = 0;
			}
		}
	}
}

void paint_island(int x, int y)
{
	queue<pair<int, int>> q;
	islandCnt++;
	
	q.push({x, y});
	Map[x][y] = islandCnt;
	island[islandCnt].push_back({x, y});
	
	while(!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		for(int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(safe(nx, ny) == 1 && Map[nx][ny] == -1)	
			{
				q.push({nx, ny});
				Map[nx][ny] = islandCnt;
				island[islandCnt].push_back({nx, ny});
			}
		}		
	}
}

int main(void)
{
//	freopen("B17472_input.txt", "r", stdin);
	
	cin >> row >> col;
	
	for(int i = 1; i <= row; i++)
	{
		for(int j = 1; j <= col; j++)
		{
			cin >> Map[i][j];	
			
			if(Map[i][j] == 1) Map[i][j] = -1;
		}
	}
	
	for(int i = 1; i <= row; i++)
	{
		for(int j = 1; j <= col; j++)
		{
			if(Map[i][j] == -1)
			{
				paint_island(i, j);
			}
		}
	}

	cal_bridge_len();
	
	solve(1, 0);
	
	if(Min >= 100000)
	{
		cout << "-1";
	}
	else
	{
		cout << Min;
	}
	
	return 0;
}
