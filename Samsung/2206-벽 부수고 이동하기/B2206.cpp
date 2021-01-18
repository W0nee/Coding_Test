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

int N;
int Map[110][110];
int visited[110][110];
int Min = 99999999;

vector<pair<int, int>> ground[10010];
int groundCnt;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int safe(int x, int y)
{
	if(1 <= x && x <= N && 1 <= y && y <= N)
	{
		return 1;
	}
	
	return 0;
}

void divide(int x, int y, int cnt)
{
	queue<pair<int, int>> q;
	map<pair<int, int>, int> check;
	
	q.push({x, y});
	visited[x][y] = cnt;
	
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
			
			if(Map[nx][ny] == 1 && visited[nx][ny] == 0)
			{
				q.push({nx, ny});
				visited[nx][ny] = cnt;
			}
			else if(Map[nx][ny] == 0 && check[{x, y}] == 0)
			{
				ground[cnt].push_back({x, y});
				check[{x, y}] = 1;
			}
		}
	}
}

void connect(int start)
{
	queue<pair<int, int>> q;
	int check[110][110] = {0};
	
	for(int i = 0; i < ground[start].size(); i++)
	{
		int x = ground[start][i].first;
		int y = ground[start][i].second;
		
		q.push({x, y});
		check[x][y] = 1;
	}
	
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
			
			if(visited[nx][ny] == 0 && check[nx][ny] == 0)
			{
				q.push({nx, ny});
				check[nx][ny] = check[x][y] + 1;
			}
			else if(visited[nx][ny] != start && check[nx][ny] == 0)
			{
				check[nx][ny] = check[x][y] + 1;
				
				Min = min(Min, check[nx][ny] - 2);
				return;
			}
		}
	}
}

void print()
{
	cout << "\n";
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			cout << visited[i][j] << " ";
		}
		cout << "\n";
	}
}

void solve()
{
	for(int i = 1; i <= groundCnt; i++)
	{
		connect(i);
	}

	cout << Min;
}

int main(void)
{
//	freopen("B2206_input.txt", "r", stdin);
	
	cin >> row >> col;
	
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			cin >> Map[i][j];
		}
	}
	
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			if(Map[i][j] == 1 && visited[i][j] == 0)
			{
				divide(i, j, ++groundCnt);
			}
		}
	}
	
	solve();
	
	return 0;
}
