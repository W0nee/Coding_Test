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

int N, Q, len;
int Map[70][70];
int visited[70][70];
int Max;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int safe(int x, int y)
{
	if(1 <= x && x <= len && 1 <= y && y <= len)
	{
		return 1;
	}
	
	return 0;
}

void melt()
{
	vector<pair<int, int>> list;
	
	for(int x = 1; x <= len; x++)
	{
		for(int y = 1; y <= len; y++)
		{
			if(Map[x][y] == 0)
			{
				continue;
			}
			
			int cnt = 0;
			
			for(int k = 0; k < 4; k++)
			{
				int nx = x + dx[k];
				int ny = y + dy[k];
				
				if(safe(nx, ny) && Map[nx][ny] >= 1)
				{
					cnt++;
				}
			}
			
			if(cnt <= 2)
			{
				list.push_back({x, y});
			}
		}
	}
	
	for(int i = 0; i < list.size(); i++)
	{
		int x = list[i].first;
		int y = list[i].second;
		
		Map[x][y]--;
	}
}

void rotate(int x, int y, int size)
{
	int Temp[70][70];
	
	for(int i = 1; i <= size; i++)
	{
		for(int j = 1; j <= size; j++)
		{
			Temp[j][size+1-i] = Map[i+x-1][j+y-1];
		}
	}
	
	for(int i = 1; i <= size; i++)
	{
		for(int j = 1; j <= size; j++)
		{
			Map[i+x-1][j+y-1] = Temp[i][j];
		}
	}
}

int sum()
{
	int val = 0;
	
	for(int i = 1; i <= len; i++)
	{
		for(int j = 1; j <= len; j++)
		{
			val += Map[i][j];
		}	
	}	
	
	return val;
}

void print()
{
	for(int i = 1; i <= len; i++)
	{
		for(int j = 1; j <= len; j++)
		{
			cout << Map[i][j] << " ";
		}	
		cout << endl;
	}	
	cout << endl;
}

void find(int x, int y)
{
	queue<pair<int, int>> q;
	
	q.push({x, y});
	visited[x][y] = 1;
	int cnt = 1;
	
	while(!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();
		
		for(int i = 0; i < 4; i++)
		{
			int nx = x+dx[i];
			int ny = y+dy[i];
			
			if(safe(nx, ny))
			{
				if(Map[nx][ny] >= 1 && visited[nx][ny] == 0)
				{
					q.push({nx, ny});
					visited[nx][ny] = 1;
					cnt++;
				}
			}
		}
	}
	
	Max = max(Max, cnt);
}

void solve(int L)
{
	int size = pow(2, L);
	
	for(int i = 1; i <= len; i += size)
	{
		for(int j = 1; j <= len; j += size)
		{
			rotate(i, j, size);
		}	
	}
	
	melt();
}
 
int main(void)
{
//	freopen("B20058_input.txt", "r", stdin);
	
	cin >> N >> Q;
	
	len = pow(2, N);
	
	for(int i = 1; i <= len; i++)
	{
		for(int j = 1; j <= len; j++)
		{
			cin >> Map[i][j];		
		}
	}
	
	for(int i = 1; i <= Q; i++)
	{
		int L;
		cin >> L;
		
		solve(L);
	}
	
	for(int i = 1; i <= len; i++)
	{
		for(int j = 1; j <= len; j++)
		{
			if(Map[i][j] >= 1 && visited[i][j] == 0)
			{
				find(i, j);
			}
		}
	}
	
	cout << sum() << endl;
	cout << Max << endl;
	
	return 0;
}
